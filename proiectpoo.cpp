#include <bits/stdc++.h>
using namespace std;

class String 
{
    int lungime;
    char* sir;

    public:

        String(const char* str = "") ///constructor cu parametru char
        {
            lungime = strlen(str);
            sir = new char[lungime + 1];
            strcpy(sir, str);
        }

        String(const String& elem) ///constr de copiere
        {
            lungime = elem.lungime;
            sir = new char[lungime + 1];
            strcpy(sir, elem.sir);
        }

        ~String() {
            delete[] sir;
        }

        String& operator=(const String& elem) ///constr suprascriere egal
        {
            if (this != &elem) {
                delete[] sir;
                lungime = elem.lungime;
                sir = new char[lungime + 1];
                strcpy(sir, elem.sir);
            }
            return *this;
        }

        friend ostream& operator<<(ostream& os, const String& str) {
            os << str.sir;
            return os;
        }
    };

    class Actor ///aceasta clasa va retine numele si varsta actorilor si va fi utilizata in pentru a memora actorii din filme
    {
        String nume;
        int varsta;

        public:
        
            Actor() ///constructor neparametrizat
            {
                nume="";
                varsta=0;
            }
        
            Actor (String n, int v) //constructor parametrizat
            {
                nume =n;
                varsta=v;
            }
        
            String getNume() const 
            {
                return nume;
            }
        
            int getVarsta() const
            {
                return varsta;
            }
    };
    /// clasa film retine titlul filmului, durata acestuia si cast-ul sub forma unui vector de tip Actori
    
    class Film
    {
        String titlu;
        int durata;
        vector<Actor> actori;
    
        public:
    
        Film()
        {
            titlu="unknown";
            durata=0;
        }
    
        Film (String t,int d, vector<Actor> a)
        {
            titlu=t;
            durata=d;
            actori=a;
        }
    
        String getTitlu() const
        {
            return titlu;
        }
    
        int getDurata() const
        {
            return durata;
        }
    
        vector<Actor> getActori()
        {
            return actori;
        }
};

class Bilete
{
double pret;
int ora;
int minut;
bool student; ///va fi utilizat pentru partea de logica business pentru a acorda reducere de student

public:

    Bilete(double p, bool s)
    {
        pret=p;
        student=s;
        if (student==true)
            pret=pret-5;
    }

    void setOra( int o)
    {
        ora=o;
    }

    void setMinut( int m)
    {
        minut=m;
    }

    int getPret() const
    {
        return pret;
    }

    int getOra() const
    {
        return ora;
    }

    int getMinut() const
    {
        return minut;
    }

    void afisare()
    {
        cout<<"\nPretul biletului este: "<<pret<<"lei iar filmul se va difuza la ora: "<<ora<<":"<<minut<<'\n';
    }
};

class SalaCinema
{
    int sala;
    int numar_locuri;
    bool restrictii;

    public:

    void setNumar_locuri(int n)
    {
        numar_locuri=n;
    }

    void setSala(int s)
    {
        sala=s;
    }

    void setRestrictii(bool r)
    {
        restrictii=r;
    }

    bool getRestrictii()
    {
        return restrictii;
    }

    int getSala()
    {return sala;
    }

    int getNumar_locuri(bool r)
    {
        if(r)
            numar_locuri/=2;
        else numar_locuri=numar_locuri*1;
        return numar_locuri;

    }

    void afisare()
    {
        cout<<"\nSala este "<<sala<<" iar numarul de locuri este "<<numar_locuri<<" locuri \n";
    }
};

int main()
{
    ///prima intrare
    Actor actor1("Elizabeth Olsen",34);
    Actor actor2("Benedict Cumberbatch", 46);
    Actor actor3("Xochitl Gomez", 16);
    vector<Actor> actori={actor1,actor2,actor3};
    Film film1("Doctor Strange in the Multiverse of Madness", 126,actori);
    cout<<"Film: "<<film1.getTitlu()<<'\n'<<"Durata:"<<film1.getDurata()<<" minute\n";
    
    cout<<"Cast: \n";
    for (int i = 0; i < actori.size(); i++)  ///afisare informatii actori
    {
        cout << " - " << actori[i].getNume() << " (" << actori[i].getVarsta() << " ani)" << endl;
    }
    
    SalaCinema sala1;
    sala1.setSala(1);
    sala1.setNumar_locuri(400);
    sala1.setRestrictii(true); ///se vor pune restrictii
    sala1.getNumar_locuri(sala1.getRestrictii());
    sala1.afisare();
    
    Bilete bilet(20, true); //se va oferi reducere
    bilet.setOra(20);
    bilet.setMinut(30);
    bilet.getPret();
    bilet.afisare();

/// a doua intrare
    Actor actor4("Sam Worthington",46);
    Actor actor5("Zoe Saldana", 44);
    Actor actor6("Sigourney Weave", 73);
    Actor actor7("Josh Friedman",56);
    vector<Actor> actori2={actor4,actor5,actor6,actor7};
    Film film2("Avatar: The Way of Water", 192 ,actori2);
    cout<<"Film: "<<film2.getTitlu()<<'\n'<<"Durata:"<<film2.getDurata()<<" minute\n";
    
    cout<<"Cast: \n";
    for (int i = 0; i < actori2.size(); i++)  ///afisare informatii actori
    {
        cout << " - " << actori2[i].getNume() << " (" << actori2[i].getVarsta() << " ani)" << endl;
    }

    SalaCinema sala2;
    sala2.setSala(2);
    sala2.setNumar_locuri(400); 
    sala2.setRestrictii(false);//nu se vor pune restrictii
    sala2.getNumar_locuri(sala2.getRestrictii());
    sala2.afisare();
    
    Bilete bilet2(30, false); //nu se va oferi reducere
    bilet2.setOra(20);
    bilet2.setMinut(40);
    bilet2.getPret();
    bilet2.afisare();
}
