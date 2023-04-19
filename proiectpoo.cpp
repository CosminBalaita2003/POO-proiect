#include <bits/stdc++.h>
using namespace std;
/// clasa exceptie pentru a afisa mesajele de eroare
class MyException : public std::exception {
    string msg;
public:
    MyException(const string &mesaj) : msg(mesaj) {}

    virtual const char *what() const throw() {
        return msg.c_str();
    }
};
/// functie pentru a verifica daca numarul de persoane este 0
double verificare0(double x) {
    if (x == 0) {
        throw MyException("Numarul nu poate fi 0");
    }
    return x;
}
/// functie pentru a procesa inputul pentru numarul de persoane
void processInput(double x) {
    try {
        double result = verificare0(x);
        std::cout << result <<" Locuri rezervate"<< std::endl;
    } catch (MyException &e) {
        std::string message = std::string("Invalid input: ") + e.what();
        throw MyException(message);
    }
}
/// functie care citeste suma de bani si se asigura ca nu este negativa
int CitireCash(){
    int cash;
    cout<<"Introduceti suma de bani:";
    cin >> cash;
    if (cash < 0){
        throw MyException("Suma de bani nu poate fi negativa!");
    }
    return cash;
}
/// functie care citeste numarul de persoane si se asigura ca nu este negativ / zecimal
double citireNumarPeesoane(){
    double nr;
    cout<<"Introduceti numarul de persoane:";
    cin >> nr;
    try{
        processInput(nr);
        if (nr < 0){
            throw MyException("Numarul de persoane nu poate fi negativ!");
        }
        else if (nr!= int(nr))
            throw MyException("Numarul de persoane nu poate fi zecimal!");
    }
    catch(MyException &e){
        cout<<"Eroare:"<<e.what()<<endl;
    }

    return nr;

}
/// functie care citeste pretul si se asigura ca nu este negativ
double citirepret(){
    double pret;
    cout<<"Introduceti pretul:";
    cin >> pret;
    if (pret < 0){
        throw MyException("Pretul nu poate fi negativ!");
    }
    return pret;
};


void PrintMessaje(const string& mesaj) {
    if ( mesaj.empty()){
        throw MyException("Mesajul este gol!");
    }
    cout << mesaj << endl;
}


/// clasa director care retine firma la care lucreaza leading-actorul
class director{
protected:
    string firma;
public:
    director()
    {
        firma=" ";
    }
    director(string f)
    {
        firma=f;
    }
    director(const director &d)
    {
        firma=d.firma;
    }
    ~director()
    {
        firma=" ";
    }
    string get_firma() const
    {
        return firma;
    }
    void set_firma(string f)
    {
        firma=f;
    }
    friend istream &operator>>(istream &in, director &d)
    {
        in>>d.firma;
        return in;
    }
    friend ostream &operator<<(ostream &out, const director &d)
    {
        out<<"Directorul este:"<<'\n';
        out<<"Firma:"<<d.firma<<'\n';
        return out;
    }
    director &operator=(const director &d)
    {
        firma=d.firma;
        return *this;
    }

};

class Actor /// retine numele, prenumele, varsta si numarul de nominalizari
{
    string nume;
    string prenume;
    int varsta;
protected:
    int nominalizari;
public:
    Actor() /// constructor neparametrizat
    {
        nume=" ";
        prenume=" ";
        varsta=0;

    }
    Actor(string n, string p, int v, int nom=0) /// constructor parametrizat
    {
        nume=n;
        prenume=p;
        varsta=v;
        nominalizari=nom;
    }

    ~Actor() /// destructor
    {
        nume=" ";
        prenume=" ";
        varsta=0;

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
    int get_nominalizari() const
    {
        return nominalizari;
    }
    /// constructor de copiere
    Actor& operator=(const Actor& a)
    {
        nume=a.nume;
        prenume=a.prenume;
        varsta=a.varsta;
        nominalizari=a.nominalizari;
        return *this;

    }
    friend ostream& operator<<(ostream& out, const Actor& a)
    {
        cout<<"Actorul este:"<<'\n';
        cout<<"Nume:";
        out<<a.nume<<'\n';
        cout<<"Prenume:";
        out<<a.prenume<<'\n';
        cout<<"Varsta:";
        out<<a.varsta<<'\n';
        cout<<"Nominalizari:";
        out<<a.nominalizari<<'\n';
        return out;
    }
    friend istream& operator>>(istream& in, Actor& a)
    {
        cout<<"Actorul este:"<<'\n';
        cout<<"Nume:";
        in>>a.nume;
        cout<<"Prenume:";
        in>>a.prenume;
        cout<<"Varsta:";
        in>>a.varsta;
        cout<<"Numar Nominalizari:";
        in>>a.nominalizari;
        return in;
    }
};
class Leading_Actor : public Actor, public director /// clasa care mosteneste clasa Actor si clasa director
{
    int numar_filme;
public:
    Leading_Actor()
    {
        numar_filme=0;
    }
    Leading_Actor(string n, string p, int v,int nom, string f, int nr) : Actor(n,p,v,nom), director(f) /// constructor parametrizat
    {
        numar_filme=nr;
    }
    Leading_Actor(const Leading_Actor &l)
    {
        numar_filme=l.numar_filme;
    }
    ~Leading_Actor()
    {
        numar_filme=0;
    }
    int get_numar_filme() const
    {
        return numar_filme;
    }

    friend istream &operator>>(istream &in, Leading_Actor &l)
    {
        cout<<"Leading actor - - - Director Executiv:"<<'\n';
        in>>(Actor&)l; 
        cout<<"Numarul de filme:";
        in>>l.numar_filme;
        cout<<"Firma:";
        in>>(director&)l;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Leading_Actor &l)
    {
        cout<<"\nLeading actor:";
        out<<l.get_prenume()<<" "<<l.get_nume()<<" are "<<l.get_varsta()<<" ani."<<'\n';
        out<<"A jucat in "<<l.numar_filme<<" filme."<<'\n';
        out<<"Totodata este director la:"<<l.get_firma()<<'\n';
        return out;
    }
};
class Personaj{ /// clasa care retine numele personajului si actorul care il joaca
    string nume;
    Actor actor;
public:
    Personaj()
    {
        nume=" ";
    }
    Personaj(string n, Actor a)
    {
        nume=n;
        actor=a;
    }
    Personaj(const Personaj &p)
    {
        nume=p.nume;
        actor=p.actor;
    }
    ~Personaj()
    {
        nume=" ";
    }
    string get_nume() const
    {
        return nume;
    }
    Actor get_actor() const
    {
        return actor;
    }
    friend istream &operator>>(istream &in, Personaj &p)
    {
        cout<<"Personajul este:"<<'\n';
        cout<<"Nume:";
        in>>p.nume;
        cout<<"Actor:"<<'\n';
        in>>p.actor;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Personaj &p)
    {
        out<<"Personajul "<<p.nume<<" este interpretat de "<<p.actor.get_prenume()<<' '<<p.actor.get_nume()<<" care are "<<p.actor.get_varsta()<<" ani."<< "Si are "<<p.actor.get_nominalizari()<<" Nominalizari"<<'\n';
        return out;
    }
};
class Film /// clasa care retine titlul, genul, durata, vectorul de personaje si actorul principal
{
    string titlu;
    string gen;
    int durata;
    Leading_Actor a;
    vector <Personaj> p;
    
public:
    Film()
    {
        titlu=" ";
        gen=" ";
        durata=0;
    }
    Film(string t, string g, int d, vector <Personaj> p,Leading_Actor a) /// constructor parametrizat
    {
        titlu=t;
        gen=g;
        durata=d;
        this->p=p;
        this->a=a;
    }
    Film(const Film &f)
    {
        titlu=f.titlu;
        gen=f.gen;
        durata=f.durata;
        p=f.p;
        a=f.a;
    }
    ~Film()
    {
        titlu=" ";
        gen=" ";
        durata=0;
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
    vector <Personaj> get_persoane() const
    {
        return p;
    }
    Leading_Actor get_actor() const
    {
        return a;
    }

    friend istream &operator>>(istream &in, Film &f)
    {
        cout<<"Filmul este:"<<'\n';
        cout<<"Titlu:";
        in>>f.titlu;
        cout<<"Gen:";
        in>>f.gen;
        cout<<"Durata:";
        in>>f.durata;
        cout<<"Actor principal:"<<'\n';
        in>>f.a;
        cout<<"Numarul de personaje:";
        int n;
        in>>n;
        for(int i=0;i<n;i++)
        {
            Personaj p;
            in>>p;
            f.p.push_back(p);

        }
        return in;
    }
    friend ostream &operator<<(ostream &out, const Film &f)
    {
        out<<"Filmul "<<f.titlu<<" este de genul "<<f.gen<<" si are o durata de "<<f.durata<<" minute."<<'\n';
        out<<"Actorul principal este "<<f.a.get_prenume()<<" "<<f.a.get_nume()<<" care are "<<f.a.get_varsta()<<" ani,"<<" jucand  in "<<f.a.get_numar_filme()<< " filme"<<" fiind totodata regizor la "<<f.a.get_firma()<<'\n';
        out<<"Personajele sunt:"<<'\n';
        for(int i=0;i<f.p.size();i++)
        {
            out<<f.p[i].get_nume()<<" este interpretat de "<<f.p[i].get_actor().get_prenume()<<' '<<f.p[i].get_actor().get_nume()<<" care are "<<f.p[i].get_actor().get_varsta()<<" ani, "<<" avand "<<f.p[i].get_actor().get_nominalizari()<<" nominalizari"<<'\n';
        }
        return out;
    }
};
class Bilete{ /// clasa care retine pretul, ora, minutul, data si daca este student sau nu
    float pret;
    int ora;
    int minut;
    string data;
    bool student;
public:
    Bilete()
    {
        pret=0;
        ora=0;
        minut=0;
        data=" ";
        student=false;
    }
    Bilete(float p, int o, int m, string d, bool s)
    {
        pret=p;
        ora=o;
        minut=m;
        data=d;
        student=s;
    }
    Bilete(const Bilete &b)
    {
        pret=b.pret;
        ora=b.ora;
        minut=b.minut;
        data=b.data;
        student=b.student;
    }
    ~Bilete()
    {
        pret=0;
        ora=0;
        minut=0;
        data=" ";
        student=false;
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
    float get_pret_final() const /// functie care calculeaza pretul final in functie categoria: student sau nu
    {
        return (pret-pret*0.5*student);
    }
    friend istream &operator>>(istream &in, Bilete &b)
    {
        cout<<"Pret:";
        cin>>b.pret;
        cout<<"Ora:";
        in>>b.ora;
        cout<<"Minut:";
        in>>b.minut;
        cout<<"Data:";
        in>>b.data;
        cout<<"Student(1/0): ";
        in>>b.student;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Bilete &b)
    {
        out<<"Biletul costa "<<b.get_pret_final()<<" lei si este pentru data de "<<b.data<<" la ora "<<b.ora<<":"<<b.minut<<'\n';
        if (b.student)
        {
            out<<"Biletul este studentesc."<<'\n';
        }
        else
        {
            out<<"Biletul nu este studentesc."<<'\n';
        }
        return out;
    }

};
class Bilet_3D : public Bilete /// clasa care m`are daca biletul este 3D si daca are ochelari 3D
{
    bool ochelari;
public:
    Bilet_3D()
    {
        ochelari=false;
    }
    Bilet_3D(float p, int o, int m, string d, bool s, bool o3) : Bilete(p, o, m, d, s)
    {
        ochelari=o3;
    }
    Bilet_3D(const Bilet_3D &b) : Bilete(b)
    {
        ochelari=b.ochelari;
    }
    ~Bilet_3D()
    {
        ochelari=false;
    }
    bool get_ochelari() const
    {
        return ochelari;
    }
    friend istream &operator>>(istream &in, Bilet_3D &b)
    {
        cout<<"Biletul 3D este:"<<'\n';
        in>>(Bilete&)b;
        cout<<"Ochelari 3D(1/0): ";
        in>>b.ochelari;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Bilet_3D &b)
    {
        out<<(Bilete&)b;
        if (b.ochelari==true)
        {
            out<<"Biletul este 3D."<<'\n';
            out<<"Service 3D:"<< b.get_pret_final()+b.get_pret_final()*0.1<<'\n'; /// se adauga 10% la pretul biletului
        }
        else
        {
            out<<"Biletul nu este 3D."<<'\n';
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
        sala=0;
        numar_locuri=0;
        respecta_distanta=false;
    }
    SalaCinema(int s, int n, bool r, Film f)
    {
        sala=s;
        numar_locuri=n;
        respecta_distanta=r;
        this->f=f;
    }
    SalaCinema(const SalaCinema &s)
    {
        sala=s.sala;
        numar_locuri=s.numar_locuri;
        respecta_distanta=s.respecta_distanta;
        f=s.f;
    }
    ~SalaCinema()
    {
        sala=0;
        numar_locuri=0;
        respecta_distanta=false;
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
        return numar_locuri-respecta_distanta*0.5*numar_locuri;
    }
    friend istream &operator>>(istream &in, SalaCinema &s)
    {
        cout<<"Vizionare"<<'\n';
        cout<<"Numarul salii:";
        in>>s.sala;
        cout<<"Numarul de locuri:";
        in>>s.numar_locuri;
        cout<<"Respecta distanta(1/0):";
        in>>s.respecta_distanta;
        cout<<"Filmul:"<<'\n';
        in>>s.f;
        return in;
    }
    friend ostream &operator<<(ostream &out, const SalaCinema &s)
    {
        out<<"\n \nSala "<<s.sala<<" are "<<s.get_numar_locuri_final()<<" locuri si respecta distanta."<<'\n';
        out<<s.f;
        return out;
    }
};
/* Definiți și extindeți (moșteniți) minim o interfață (clasă fără date membru,
doar metode pur virtuale și un destructor virtual) care să aibă minim două
metode (alternativ: minim două interfețe, fiecare cu cel puțin o metodă).
*/
class IPayment{ /// interfata care contine metodele de plata si rest
public:
    virtual void ProcessPayment(double cash)=0;
    virtual void ProcessRest(double cash)=0;
    virtual ~IPayment()= default;
};
class CashPayment : public IPayment{ /// clasa care implementeaza metodele de plata si rest
public:
    void ProcessPayment(double cash) override {
        cout<<"Cash payment: "<<cash<<endl;
    }
    void ProcessRest(double cash) override{
        cout<<"Rest: "<<cash<<endl;
    }
};
///Definiți și extindeți (moșteniți) minim o clasă de bază abstractă (clasă capoate avea date membru, dar are cel puțin o metodă pur virtuală).
class Food{ /// clasa de baza abstracta care contine pretul

    double pret;
public:
    Food(double p):pret(p){}
    virtual void afisare()=0;
    virtual ~Food()= default;
    virtual double get_pre() const{
        return pret;
    }
};
class Pizza : public Food{ /// clasa derivata care mosteneste clasa de baza abstracta
    string nume;
public:
    Pizza( double p, string nume):Food(p),nume(nume){}
    void afisare() override {
        cout<<"Pizza "<<nume<<" are pretul de "<<get_pre()<<endl;
    }
};
class Afis{ /// clasa de baza abstracta care contine metodele de afisare a ariei si desenul
public:
    virtual double aria(){
        cout<<"Aria afisului este: \n";
        return 0;
    }
    virtual void desen(){
        cout<<"Desenul afisului este: \n";
    }
    virtual ~Afis()= default;

};
class Dreptunghi: public Afis{ /// clasa derivata care mosteneste clasa de baza abstracta
    double l;
    double L;
public:
    Dreptunghi(double l, double L):l(l),L(L){}
    double aria() override {
        cout<<"Aria dreptunghiului este: ";
        return l*L;
    }
};
class Patrat: public Afis{ /// clasa derivata care mosteneste clasa de baza abstracta
    double l;
public:
    Patrat(double l):l(l){}
    double aria() override {
        cout<<"Aria patratului este: ";
        return l*l;
    }
};
class Triunghi: public Afis{  /// clasa derivata care mosteneste clasa de baza abstracta
    double l;
    double h;
public:
    Triunghi(double l, double h):l(l),h(h){}
    double aria() override {
        cout<<"Aria triunghiului este: ";
        return l*h/2;
    }
};

class Afis3D : public Afis{ /// clasa derivata care mosteneste clasa de baza abstracta
public:
    void desen() override {
        cout<<"Desenul afisului 3D este: \n";
    }
    void desen3D(){
        cout<<"Afisul e acum 3D \n";
    }
};
class cinema{ /// clasa care contine numarul de sali si filme
    static int nr_sali;
    static int nr_filme;
public:
    static int get_nr_sali(){
        return nr_sali;
    }
    static int get_nr_filme(){
        return nr_filme;
    }
    static void add_movie (int nr){
        nr_filme+=nr;
    }
};
int cinema::nr_sali = 5; /// initializare variabile statice
int cinema::nr_filme = 10; /// initializare variabile statice
int main() {
    cout<<"\n\nNumarul de sali disponibile in cinema este:"<<cinema::get_nr_sali()<<'\n';
    cout<<"Numarul de filme disponibile in cinema este:"<<cinema::get_nr_filme()<<'\n';
    cinema::add_movie(5);
    cout<<"Numarul nou de filme disponibile in cinema este:"<<cinema::get_nr_filme()<<'\n';
    SalaCinema s;
    cin>>s;
    Bilete b;
    cin>>b;
    ///exceptie daca pretul=0
    try {
        if (b.get_pret_final() == 0)
            throw MyException("Pretul este 0?!?");
    }
    catch (MyException &e){
        cout<<e.what()<<endl;
    }
    Bilet_3D b3;
    cin>>b3;
    try {
        if (b.get_pret_final() == 0)
            throw MyException("Pretul este 0?!?");
    }
    catch (MyException &e){
        cout<<e.what()<<endl;
    }
    cout<<s;
    cout<<"bilet simplu\n"<<b;
    cout<<"bilet 3D\n"<<b3;
    cout<<"- - - -- - - - ";
    cout<<"\nPreteul final al biletului simplu este: "<<b.get_pret_final()+b3.get_pret_final()<<endl;
    IPayment *payment = new CashPayment();


    try {
        int n=CitireCash();
        payment->ProcessPayment(n);
        payment->ProcessRest(n-(b.get_pret_final()+b3.get_pret_final()));
        cout<<"Payment processed"<<endl;
        delete payment;
        cout<<"- - -- - - - "<<endl;
    }
    catch (MyException &e){
        cout<<e.what()<<endl;
    }
    catch (exception &e){
        cout<<e.what()<<endl;
    }
    catch (...){
        cout<<"Unknown exception"<<endl;
    }

    Bilet_3D b2(25.5, 20, 30, "12.12.2020", 1, 1);
    cout<<"\nExemplu de bilet 3D:\n"<<b2;




    Food *f = new Pizza(25.5, "Diavola");
    f->afisare();

    Afis *d = new Dreptunghi(2, 3);
    cout<<d->aria()<<'\n';
    Afis *p = new Patrat(2);
    cout<<p->aria()<<'\n';
    Afis *t = new Triunghi(2, 3);
    cout<<t->aria()<<'\n';
    delete d, p, t;


    Afis *afis = new Afis3D();
    Afis3D *afis3d=dynamic_cast<Afis3D*>(afis);
    if(afis3d!=nullptr) {
        cout << "DownCast la Afis3D reusit"<<'\n';
        afis3d->desen3D();
    }
    else
        cout<<"Nu se poate face cast la Afis3D";

    delete afis;

    ///exceptii
    try{
        PrintMessaje("");
    }
    catch(MyException &e){
        cout << "error:"<<e.what() << endl;
    }
    try{
        PrintMessaje("Textul nu e gol");
    }
    catch(MyException &e){
        cout << "error:"<<e.what() << endl;
    }
    try{
        double n=citireNumarPeesoane();

    }
    catch(MyException &e){
        cout << "error:"<<e.what() << endl;
    }

    return 0;
}
