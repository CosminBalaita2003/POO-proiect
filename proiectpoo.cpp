#include <bits/stdc++.h>
using namespace std;
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
class Actor
{
    string nume;
    string prenume;
    int varsta;
protected:
    int nominalizari;
public:
    Actor()
    {
        nume=" ";
        prenume=" ";
        varsta=0;

    }
    Actor(string n, string p, int v, int nom=0)
    {
        nume=n;
        prenume=p;
        varsta=v;
        nominalizari=nom;
    }

    ~Actor()
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
class Leading_Actor : public Actor, public director
{
    int numar_filme;
public:
    Leading_Actor()
    {
        numar_filme=0;
    }
    Leading_Actor(string n, string p, int v,int nom, string f, int nr) : Actor(n,p,v,nom), director(f)
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
class Personaj{
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
class Film
{
    string titlu;
    string gen;
    int durata;
    Leading_Actor a;
    vector <Personaj> p;
    Personaj p1;
public:
    Film()
    {
        titlu=" ";
        gen=" ";
        durata=0;
    }
    Film(string t, string g, int d, vector <Personaj> p,Leading_Actor a)
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
class Bilete{
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
    float get_pret_final() const
    {
        return (pret-pret*0.5*student);
    }
    friend istream &operator>>(istream &in, Bilete &b)
    {
        cout<<"Pret:";
        in>>b.pret;
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
        if (b.student==true)
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
class Bilet_3D : public Bilete
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
            out<<"Service 3D:"<< b.get_pret_final()+b.get_pret_final()*0.1<<'\n';
        }
        else
        {
            out<<"Biletul nu este 3D."<<'\n';
        }
        return out;
    }
};
class SalaCinema
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

int main()
{
    SalaCinema s;
    cin>>s;
    Bilete b;
    cin>>b;
    Bilet_3D b3;
    cin>>b3;
    cout<<s;
    cout<<"bilet simplu\n"<<b;
    cout<<"bilet 3D\n"<<b3;
    cout<<b3;

    Bilet_3D b2(25.5, 20, 30, "12.12.2020", 1, 1);
    cout<<"\nExemplu de bilet 3D:\n"<<b2;
    return 0;
}