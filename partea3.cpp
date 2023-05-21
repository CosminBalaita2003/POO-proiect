#include <bits/stdc++.h>
using namespace std;
/// clasa exceptie pentru a afisa mesajele de eroare
class MyException : public exception
{
    string msg;

public:
    MyException(const string &mesaj) : msg(mesaj) {}

    virtual const char *what() const throw()
    {
        return msg.c_str();
    }
};
/// functie pentru a verifica daca numarul de persoane este 0
double verificare0(double x)
{
    if (x == 0)
    {
        throw MyException("Numarul nu poate fi 0");
    }
    return x;
}
/// functie pentru a procesa inputul pentru numarul de persoane
void processInput(double x)
{
    try
    {
        double result = verificare0(x);
        cout << result << " Locuri rezervate" << '\n';
    }
    catch (MyException &e)
    {
        string message = string("Invalid input: ") + e.what();
        throw MyException(message);
    }
}
/// functie care citeste suma de bani si se asigura ca nu este negativa
int CitireCash()
{
    int cash;
    cout << "Introduceti suma de bani:";
    cin >> cash;
    if (cash < 0)
    {
        throw MyException("Suma de bani nu poate fi negativa!");
    }
    return cash;
}
/// functie care citeste numarul de persoane si se asigura ca nu este negativ / zecimal
double citireNumarPeesoane()
{
    double nr;
    cout << "Introduceti numarul de persoane:";
    cin >> nr;
    try
    {
        processInput(nr);
        if (nr < 0)
        {
            throw MyException("Numarul de persoane nu poate fi negativ!");
        }
        else if (nr != int(nr))
            throw MyException("Numarul de persoane nu poate fi zecimal!");
    }
    catch (MyException &e)
    {
        cout << "Eroare:" << e.what() << '\n';
    }

    return nr;
}
/// functie care citeste pretul si se asigura ca nu este negativ
double citirepret()
{
    double pret;
    cout << "Introduceti pretul:";
    cin >> pret;
    if (pret < 0)
    {
        throw MyException("Pretul nu poate fi negativ!");
    }
    return pret;
};

void PrintMessaje(const string &mesaj)
{
    if (mesaj.empty())
    {
        throw MyException("Mesajul este gol!");
    }
    cout << mesaj << '\n';
}

/// clasa Nominalizare care retine premiu_nominalizare la care lucreaza leading-actorul

class Nominalizare
{
protected:
    string premiu_nominalizare;

public:
    Nominalizare()
    {
        premiu_nominalizare = " ";
    }
    Nominalizare(string f)
    {
        premiu_nominalizare = f;
    }
    Nominalizare(const Nominalizare &d)
    {
        premiu_nominalizare = d.premiu_nominalizare;
    }
    ~Nominalizare()
    {
        premiu_nominalizare = " ";
    }
    string get_premiu_nominalizare() const
    {
        return premiu_nominalizare;
    }
    void set_premiu_nominalizare(string f)
    {
        premiu_nominalizare = f;
    }
    friend istream &operator>>(istream &in, Nominalizare &d)
    {
        in >> d.premiu_nominalizare;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Nominalizare &d)
    {
        out << "Nominalizarea este:";
        out << d.premiu_nominalizare << '\n';
        return out;
    }
    Nominalizare &operator=(const Nominalizare &d)
    {
        premiu_nominalizare = d.premiu_nominalizare;
        return *this;
    }
};

class Actor
{
    string nume;
    string prenume;
    int varsta;
    string rol;

public:
    Actor()
    {
        nume = " ";
        prenume = " ";
        varsta = 0;
        rol = " ";
    }
    Actor(string n, string p, int v, string r)
    {
        nume = n;
        prenume = p;
        varsta = v;
        rol = r;
    }
    Actor(const Actor &a)
    {
        nume = a.nume;
        prenume = a.prenume;
        varsta = a.varsta;
        rol = a.rol;
    }
    ~Actor()
    {
        nume = " ";
        prenume = " ";
        varsta = 0;
        rol = " ";
    }
    string get_nume() const
    {
        return nume;
    }
    string get_prenume() const
    {
        return prenume;
    }
    int get_varsta() const
    {
        return varsta;
    }
    string get_rol() const
    {
        return rol;
    }
    void set_nume(string n)
    {
        nume = n;
    }
    void set_prenume(string p)
    {
        prenume = p;
    }
    void set_varsta(int v)
    {
        varsta = v;
    }
    void set_rol(string r)
    {
        rol = r;
    }
    Actor &operator=(const Actor &a)
    {
        nume = a.nume;
        prenume = a.prenume;
        varsta = a.varsta;
        rol = a.rol;
        return *this;
    }
    friend istream &operator>>(istream &in, Actor &a)
    {
        cout << "Actorul este:" << '\n';
        cout << "Nume:";
        in >> a.nume;
        cout << "Prenume:";
        in >> a.prenume;
        cout << "Varsta:";
        in >> a.varsta;
        cout << "Rol:";
        in >> a.rol;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Actor &a)
    {
        out << a.nume << " " << a.prenume << " are " << a.varsta << " ani si a jucat rolul " << a.rol << '\n';
        return out;
    }
};

class Leading_actor : public Actor, public Nominalizare
{
protected:
    int nr_filme;

public:
    Leading_actor() : Actor(), Nominalizare()
    {
        nr_filme = 0;
    }
    Leading_actor(string n, string p, int v, string r, string f, int nr) : Actor(n, p, v, r), Nominalizare(f)
    {
        nr_filme = nr;
    }
    Leading_actor(const Leading_actor &a) : Actor(a), Nominalizare(a)
    {
        nr_filme = a.nr_filme;
    }
    ~Leading_actor()
    {
        nr_filme = 0;
    }
    int get_nr_filme() const
    {
        return nr_filme;
    }
    void set_nr_filme(int nr)
    {
        nr_filme = nr;
    }
    Leading_actor &operator=(const Leading_actor &a)
    {
        Actor::operator=(a);
        Nominalizare::operator=(a);
        nr_filme = a.nr_filme;
        return *this;
    }
    friend istream &operator>>(istream &in, Leading_actor &a)
    {
        cout << "Actorul principal este:" << '\n';
        in >> (Actor &)a;
        cout << "Nominalizarea este:";
        in >> (Nominalizare &)a;
        cout << "Numarul de filme in care a jucat:";
        in >> a.nr_filme;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Leading_actor &a)
    {
        out << "Actorul principal este ";
        out << (Actor &)a;
        out << (Nominalizare &)a;
        out << "Numarul de filme in care a jucat:" << a.nr_filme << '\n';
        return out;
    }
};
class Film
{
    string titlu;
    string gen;
    int durata;
    Leading_actor actor_principal;
    vector<Actor> actori;

public:
    Film()
    {
        titlu = " ";
        gen = " ";
        durata = 0;
        actor_principal = Leading_actor();
    }
    Film(string t, string g, int d, Leading_actor a, vector<Actor> v)
    {
        titlu = t;
        gen = g;
        durata = d;
        actor_principal = a;
        actori = v;
    }
    Film(const Film &f)
    {
        titlu = f.titlu;
        gen = f.gen;
        durata = f.durata;
        actor_principal = f.actor_principal;
        actori = f.actori;
    }
    ~Film()
    {
        titlu = " ";
        gen = " ";
        durata = 0;
        actor_principal = Leading_actor();
        actori.clear();
    }
    string get_titlu() const
    {
        return titlu;
    }
    string get_gen() const
    {
        return gen;
    }
    int get_durata() const
    {
        return durata;
    }
    Leading_actor get_actor_principal() const
    {
        return actor_principal;
    }
    vector<Actor> get_actori() const
    {
        return actori;
    }
    void set_titlu(string t)
    {
        titlu = t;
    }
    void set_gen(string g)
    {
        gen = g;
    }
    void set_durata(int d)
    {
        durata = d;
    }
    void set_actor_principal(Leading_actor a)
    {
        actor_principal = a;
    }
    void set_actori(vector<Actor> v)
    {
        actori = v;
    }
    Film &operator=(const Film &f)
    {
        titlu = f.titlu;
        gen = f.gen;
        durata = f.durata;
        actor_principal = f.actor_principal;
        actori = f.actori;
        return *this;
    }
    friend istream &operator>>(istream &in, Film &f)
    {
        cout << "Filmul este:" << '\n';
        cout << "Titlu:";
        in >> f.titlu;
        cout << "Gen:";
        in >> f.gen;
        cout << "Durata:";
        in >> f.durata;
        cout << "Numarul de actori:";
        int n;
        in >> n;
        in >> f.actor_principal;
        f.actori.push_back(f.actor_principal);
        if (n > 1)
        {
            cout << "Actori secundari:";
            for (int i = 1; i < n; i++)
            {
                Actor a;
                in >> a;
                f.actori.push_back(a);
            }
            /// sortare
            sort(f.actori.begin(), f.actori.end(), [](Actor a, Actor b)
                 { return a.get_nume() < b.get_nume(); });
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, const Film &f)
    {

        out << "Filmul " << f.titlu << " este de genul " << f.gen << " si are o durata de " << f.durata << " minute." << '\n';
        out << "Actorul principal este " << f.actor_principal << '\n';
        out << "Lista de actori:\n";
        for (int i = 0; i < f.actori.size(); i++)
            out << f.actori[i] << '\n';
        return out;
    }
};
class Bilete
{ /// clasa care retine pretul, ora, minutul, data si daca este student sau nu
    float pret;
    int ora;
    int minut;
    string data;
    bool student;

public:
    Bilete() : pret(0), ora(0), minut(0), data(" "), student(false) {}

    Bilete(float p, int o, int m, std::string d, bool s) : pret(p), ora(o), minut(m), data(d), student(s) {}

    Bilete(const Bilete &b)
    {
        pret = b.pret;
        ora = b.ora;
        minut = b.minut;
        data = b.data;
        student = b.student;
    }
    ~Bilete()
    {
        pret = 0;
        ora = 0;
        minut = 0;
        data = " ";
        student = false;
    }
    bool get_student() const
    {
        return student;
    }
    float get_pret() const
    {
        return pret;
    }
    int get_ora() const
    {
        return ora;
    }
    int get_minut() const
    {
        return minut;
    }
    string get_data() const
    {
        return data;
    }
    // Metoda statică de fabrică pentru crearea unui obiect Bilete cu std::unique_ptr
    static std::unique_ptr<Bilete> creareBilete(float p, int o, int m, std::string d, bool s)
    {
        return std::make_unique<Bilete>(p, o, m, d, s);
    }

    float get_pret_final() const /// functie care calculeaza pretul final in functie categoria: student sau nu
    {
        return (pret - pret * 0.5 * student);
    }
    friend istream &operator>>(istream &in, Bilete &b)
    {
        cout << "Pret:";
        cin >> b.pret;
        cout << "Ora:";
        in >> b.ora;
        cout << "Minut:";
        in >> b.minut;
        cout << "Data:";
        in >> b.data;
        cout << "Student(1/0): ";
        in >> b.student;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Bilete &b)
    {
        out << "Biletul costa " << b.get_pret_final() << " lei si este pentru data de " << b.data << " la ora " << b.ora << ":" << b.minut << '\n';
        if (b.student)
        {
            out << "Biletul este studentesc." << '\n';
        }
        else
        {
            out << "Biletul nu este studentesc." << '\n';
        }
        return out;
    }
};
class Bilet_3D : public Bilete /// clasa care m`are daca biletul este 3D si daca are ochelari 3D
{
protected:
    bool ochelari;

public:
    Bilet_3D()
        : ochelari(false) {}

    Bilet_3D(float p, int o, int m, std::string d, bool s, bool o3)
        : Bilete(p, o, m, d, s), ochelari(o3) {}

    ~Bilet_3D()
    {
        ochelari = false;
    }
    bool get_ochelari() const
    {
        return ochelari;
    }
    static std::shared_ptr<Bilet_3D> creareBilet3D(float p, int o, int m, std::string d, bool s, bool o3)
    {
        return std::make_shared<Bilet_3D>(p, o, m, d, s, o3);
    }
    friend istream &operator>>(istream &in, Bilet_3D &b)
    {
        cout << "Biletul 3D este:" << '\n';
        in >> (Bilete &)b;
        cout << "Ochelari 3D(1/0): ";
        in >> b.ochelari;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Bilet_3D &b)
    {
        out << (Bilete &)b;
        if (b.ochelari == true)
        {
            out << "Biletul este 3D." << '\n';
            out << "Service 3D:" << b.get_pret_final() + b.get_pret_final() * 0.1 << '\n'; /// se adauga 10% la pretul biletului
        }
        else
        {
            out << "Biletul nu este 3D." << '\n';
        }
        return out;
    }
};
class SalaCinema /// clasa principala care contine sala, numarul de locuri, daca respecta distanta si un obiect de tip Film
{
    int sala;
    int numar_locuri;
    bool respecta_distanta;
    Film f;

public:
    SalaCinema()
    {
        sala = 0;
        numar_locuri = 0;
        respecta_distanta = false;
    }
    SalaCinema(int s, int n, bool r, Film f)
    {
        sala = s;
        numar_locuri = n;
        respecta_distanta = r;
        this->f = f;
    }
    SalaCinema(const SalaCinema &s)
    {
        sala = s.sala;
        numar_locuri = s.numar_locuri;
        respecta_distanta = s.respecta_distanta;
        f = s.f;
    }
    ~SalaCinema()
    {
        sala = 0;
        numar_locuri = 0;
        respecta_distanta = false;
    }
    int get_sala() const
    {
        return sala;
    }
    int get_numar_locuri() const
    {
        return numar_locuri;
    }
    bool get_respecta_distanta() const
    {
        return respecta_distanta;
    }
    Film get_film() const
    {
        return f;
    }
    int get_numar_locuri_final() const
    {
        return numar_locuri - respecta_distanta * 0.5 * numar_locuri;
    }
    friend istream &operator>>(istream &in, SalaCinema &s)
    {
        cout << "Vizionare" << '\n';
        cout << "Numarul salii:";
        in >> s.sala;
        cout << "Numarul de locuri:";
        in >> s.numar_locuri;
        cout << "Respecta distanta(1/0):";
        in >> s.respecta_distanta;
        cout << "Filmul:" << '\n';
        in >> s.f;
        return in;
    }
    friend ostream &operator<<(ostream &out, const SalaCinema &s)
    {
        out << "\n \nSala " << s.sala << " are " << s.get_numar_locuri_final() << " locuri in total si respecta distanta." << '\n';
        vector<int> numbers(20);

        // Generatorul de valori random
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(1, 100);

        // Generarea valorilor
        generate(numbers.begin(), numbers.end(), [&dist, &gen]()
                 { return dist(gen); });

        // Afișarea valorilor generate
        out << "Locuri disponibile in sala:";
        for (const auto &number : numbers)
        {
            out << " " << number;
        }
        out << '\n';
        out << s.f;
        return out;
    }
};
/* Definiți și extindeți (moșteniți) minim o interfață (clasă fără date membru,
doar metode pur virtuale și un destructor virtual) care să aibă minim două
metode (alternativ: minim două interfețe, fiecare cu cel puțin o metodă).
*/
class IPayment
{ /// interfata care contine metodele de plata si rest
public:
    virtual void ProcessPayment(double cash) = 0;
    virtual void ProcessRest(double cash) = 0;
    virtual ~IPayment() = default;
};
class CashPayment : public IPayment
{ /// clasa care implementeaza metodele de plata si rest
public:
    void ProcessPayment(double cash) override
    {
        cout << "Cash payment: " << cash << '\n';
    }
    void ProcessRest(double cash) override
    {
        cout << "Rest: " << cash << '\n';
    }
};
/// Definiți și extindeți (moșteniți) minim o clasă de bază abstractă (clasă capoate avea date membru, dar are cel puțin o metodă pur virtuală).
class Food
{ /// clasa de baza abstracta care contine pretul

    double pret;

public:
    Food(double p) : pret(p) {}
    virtual void afisare() = 0;
    virtual ~Food() = default;
    virtual double get_pre() const
    {
        return pret;
    }
};
class Pizza : public Food
{ /// clasa derivata care mosteneste clasa de baza abstracta
    string nume;

public:
    Pizza(double p, string nume) : Food(p), nume(nume) {}
    void afisare() override
    {
        cout << "Pizza " << nume << " are pretul de " << get_pre() << '\n';
    }
};
class Afis
{ /// clasa de baza abstracta care contine metodele de afisare a ariei si desenul
public:
    virtual double aria()
    {
        cout << "Aria afisului este: \n";
        return 0;
    }
    virtual void desen()
    {
        cout << "Desenul afisului este: \n";
    }
    virtual ~Afis() = default;
};
class Dreptunghi : public Afis
{ /// clasa derivata care mosteneste clasa de baza abstracta
    double l;
    double L;

public:
    Dreptunghi(double l, double L) : l(l), L(L) {}
    double aria() override
    {
        cout << "Aria dreptunghiului este: ";
        return l * L;
    }
};
class Patrat : public Afis
{ /// clasa derivata care mosteneste clasa de baza abstracta
    double l;

public:
    Patrat(double l) : l(l) {}
    double aria() override
    {
        cout << "Aria patratului este: ";
        return l * l;
    }
};
class Triunghi : public Afis
{ /// clasa derivata care mosteneste clasa de baza abstracta
    double l;
    double h;

public:
    Triunghi(double l, double h) : l(l), h(h) {}
    double aria() override
    {
        cout << "Aria triunghiului este: ";
        return l * h / 2;
    }
};

class Afis3D : public Afis
{ /// clasa derivata care mosteneste clasa de baza abstracta
public:
    void desen() override
    {
        cout << "Desenul afisului 3D este: \n";
    }
    void desen3D()
    {
        cout << "Afisul e acum 3D \n";
    }
};
class cinema

{ /// clasa care contine numarul de sali si filme
    static int nr_sali;
    static int nr_filme;

public:
    static int get_nr_sali()
    {
        return nr_sali;
    }
    static int get_nr_filme()
    {
        return nr_filme;
    }
    static void add_movie(int nr)
    {
        nr_filme += nr;
    }
};
template <typename FilmType>
class Cinematograf
{
private:
    vector<FilmType> filme;

public:
    void add_movie(FilmType f)
    {
        filme.push_back(f);
    }
    void afisare_filme()
    {
        cout << "Filmele disponibile sunt: \n";
        for (auto i : filme)
            cout << i << '\n';
    }
    template <typename T>
    friend int numarTotalFilme(const Cinematograf<T> &cinematograf);
};
template <typename T>
int numarTotalFilme(const Cinematograf<T> &cinematograf)
{
    return cinematograf.filme.size();
}
template <typename TicketType>
class Bilet
{
private:
    string numeClient;
    TicketType tipTichet;

public:
    Bilet(const string &nume, const TicketType &tip)
        : numeClient(nume), tipTichet(tip) {}

    string getNumeClient() const
    {
        return numeClient;
    }

    TicketType getTipTichet() const
    {
        return tipTichet;
    }
    /// factory method
    /*am adăugat o metodă statică de fabrică numită "creareBilet()" în clasa "Bilet". Această metodă poate fi apelată direct pe clasa, fără a fi necesar să se creeze o instanță a clasei. Metoda primește parametrii necesari pentru crearea obiectului "Bilet" și returnează obiectul creat.*/
    static Bilet<TicketType> creareBilet(const string &nume, const TicketType &tip)
    {
        // Logică pentru crearea obiectului de tip "Bilet" în funcție de criterii specifice
        return Bilet<TicketType>(nume, tip);
    }
};

template <typename TicketType> /// cerinta1b
/// template method
/*Acest pattern este utilizat în clasa șablon "Bilet". Clasa definește o metodă template afisareDetalii() care servește ca un schelet al algoritmului și lasă subclasele să implementeze pașii individuali. În implementarea specializată pentru Bilet<int>, putem vedea cum se suprascrie metoda afisareDetalii() pentru a afișa informații specifice pentru tipul de tichet int. Astfel, pattern-ul Template Method ne permite să definim un schelet comun pentru o anumită funcționalitate și să lăsăm subclasele să implementeze pașii specifici.*/
void afisareDetaliiBilet(const Bilet<TicketType> &bilet)
{

    cout << "Nume client: " << bilet.getNumeClient() << '\n';
    cout << "Tip tichet: " << bilet.getTipTichet() << '\n';
    '\n';
    cout << "------------------------------------" << '\n';
}
template <> /// cerinta1c
void afisareDetaliiBilet<int>(const Bilet<int> &bilet)
{
    cout << "Detalii bilet:" << '\n';
    cout << "Nume client: " << bilet.getNumeClient() << '\n';
    cout << "Tip tichet (int): " << bilet.getTipTichet() << '\n';
    cout << "------------------------------------" << '\n';
}

int cinema::nr_sali = 5;   /// initializare variabile statice
int cinema::nr_filme = 10; /// initializare variabile statice
int main()
{
    cout << "\n\nNumarul de sali disponibile in cinema este:" << cinema::get_nr_sali() << '\n';
    cout << "Numarul de filme disponibile in cinema este:" << cinema::get_nr_filme() << '\n';
    cinema::add_movie(5);
    cout << "Numarul nou de filme disponibile in cinema este:" << cinema::get_nr_filme() << '\n';

    SalaCinema s;
    cin >> s;
    Bilete b;
    cin >> b;
    /// exceptie daca pretul=0
    try
    {
        if (b.get_pret_final() == 0)
            throw MyException("Pretul este 0?!?");
    }
    catch (MyException &e)
    {
        cout << e.what() << '\n';
    }
    Bilet_3D b3;
    cin >> b3;
    try
    {
        if (b.get_pret_final() == 0)
            throw MyException("Pretul este 0?!?");
    }
    catch (MyException &e)
    {
        cout << e.what() << '\n';
    }
    cout << s;
    cout << "bilet simplu\n"
         << b;
    cout << "bilet 3D\n"
         << b3;
    cout << "- - - -- - - - ";
    cout << "\nPreteul final al biletului simplu este: " << b.get_pret_final() << '\n';
    IPayment *payment = new CashPayment();

    try
    {
        int n = CitireCash();
        payment->ProcessPayment(n);
        payment->ProcessRest(n - (b.get_pret_final() + b3.get_pret_final()));
        cout << "Payment processed" << '\n';
        delete payment;
        cout << "- - -- - - - " << '\n';
    }
    catch (MyException &e)
    {
        cout << e.what() << '\n';
    }
    catch (exception &e)
    {
        cout << e.what() << '\n';
    }
    catch (...)
    {
        cout << "Unknown exception" << '\n';
    }

    Bilet_3D b2(25.5, 20, 30, "12.12.2020", 1, 1);
    cout << "\nExemplu de bilet 3D:\n"
         << b2;
    // polimorfism la executie
    Food *f = new Pizza(25.5, "Diavola");
    f->afisare();

    Afis *d = new Dreptunghi(2, 3);
    cout << d->aria() << '\n';
    Afis *p = new Patrat(2);
    cout << p->aria() << '\n';
    Afis *t = new Triunghi(2, 3);
    cout << t->aria() << '\n';
    delete d, p, t;

    Afis *afis = new Afis3D();
    Afis3D *afis3d = dynamic_cast<Afis3D *>(afis);
    if (afis3d != nullptr)
    {
        cout << "DownCast la Afis3D reusit" << '\n';
        afis3d->desen3D();
    }
    else
        cout << "Nu se poate face cast la Afis3D";

    delete afis;

    /// exceptii
    try
    {
        PrintMessaje("");
    }
    catch (MyException &e)
    {
        cout << "error:" << e.what() << '\n';
    }
    try
    {
        PrintMessaje("Textul nu e gol");
    }
    catch (MyException &e)
    {
        cout << "error:" << e.what() << '\n';
    }
    try
    {
        double n = citireNumarPeesoane();
    }
    catch (MyException &e)
    {
        cout << "error:" << e.what() << '\n';
    }

    Bilet<string> biletString = Bilet<string>::creareBilet("John Doe", "Tichet normal");
    afisareDetaliiBilet(biletString);

    Bilet<int> biletInt = Bilet<int>::creareBilet("Alice Smith", 12345);
    afisareDetaliiBilet(biletInt);

    // Utilizarea smart pointer-ului unique_ptr pentru a crea un obiect Bilete
    std::unique_ptr<Bilete> bilet = std::make_unique<Bilete>(10.0f, 12, 30, "18/05/2023", true);

    // Accesarea metodelor obiectului Bilete prin smart pointer
   cout << "Pret bilet: " << bilet->get_pret() << '\n';
   cout << "Ora bilet: " << bilet->get_ora() << '\n';
   cout << "Minut bilet: " << bilet->get_minut() << '\n';
   cout << "Data bilet: " << bilet->get_data() << '\n';

    // Utilizarea smart pointer-ului unique_ptr pentru a crea un obiect Bilet_3D
    std::unique_ptr<Bilet_3D> bilet3D = std::make_unique<Bilet_3D>(15.0f, 15, 45, "18/05/2023", false, true);

    // Accesarea metodelor obiectului Bilet_3D prin smart pointer
   cout << "Pret bilet 3D: " << bilet3D->get_pret() << '\n';
   cout << "Ora bilet 3D: " << bilet3D->get_ora() << '\n';
   cout << "Minut bilet 3D: " << bilet3D->get_minut() << '\n';
   cout << "Data bilet 3D: " << bilet3D->get_data() << '\n';
   cout << "Ochelari 3D: " << (bilet3D->get_ochelari() ? "Da" : "Nu") << '\n';
}
