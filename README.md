# Cinematograf
* Numele Proiectului: proiectpoo.cpp
* Tema: cinematograf
* Clase: Proiectul are in total 19 clase, dintre care 2 abtracte si una.
1. Director
    - are o varibila protected :
	    - string "firma" care retine la ce firma lureaza directorul de film.
    - va fi mostenita de clasa LeadingActor
    - contine constructori parametrizti si neparametrizati, de copiere, si destructor
    - getteri si setteri
    - suprascrie operatorii "<<" ">>" "="
2. Actor
	-	are 3 variabile private: 
		-	2 string: "nume", "prenume"
		-	int: "varsta"
	- o variabila protected:
		-  int: nominalizari"
	-	este mostenita de clasa LeadingActor
	-	 contine constructori parametrizti si neparametrizati, de copiere, si destructor
	-	getteri si setteri
	-	suprascrie operatorii "<<" ">>" "="
3. Leading_Actor
	- mosteneste clasele Actor si director
	- are o variabila privata:
		-  int: "numar_flime" care retine in cate filme a jucat
	- constructori neparametrizati, parametrizati, de copiere, destructor
	- getter
	- suprascrie operatorii "<<", ">>"
4. Personaj
	- variabile private:
		-  string:"nume" 
		- Actor "a" , care retin numele personajului si actorul care il joaca
	- constructori neparametrizati, parametrizati, de copiere, destructor
	- getter
	- suprascrie operatorii "<<", ">>"
5. Film
	- variabile private: 
		- string: "titlu", "gen"
		-  int: "durata"
		- Leading_Actor: "a" 
		- vectorul de obiecte Personal
	- constructori neparametrizati, parametrizati, de copiere, destructor
	- setter si getter
	- suprascrie operatorii "<<", ">>", "="
6. Bilete
	- variabile private: 
		- float: "pret"
		- int: "ora", "minut"
		- string: "data"
		- bool: "student"
	-  constructori neparametrizati, parametrizati, de copiere, destructor
	- setteri, getteri
	- metoda de business: get_pret_final() const
		- daca student=true pretul este redus la jumatate
	-  suprascrie operatorii "<<", ">>"
7. Bilet_3D
	- mosteneste clasa Bilete
	- variabila privata:
		- bool "ochelari"
	- constructori neparametrizati, parametrizati, de copiere, destructor
	- getter
	 - suprascrie operatorii "<<", ">>", iar daca ochelari= true se adauga 10% la pret pentru ochelari
8. SalaCinema
	-	variabile private:
		-	int: "sala", "numar_locuri"
		-	bool: "respecta_distanta"
		-	Film f
	-  constructori neparametrizati, parametrizati, de copiere, destructor
	- getteri, 
	- metoda de business: " get_numar_locuri_final()  const" 
		- daca respecta_distanta=true nr_locuri/=2
	-	suprascrie "<<", ">>"
9. IPayment
	- interfata
	- metode virtuale:
		- virtual  void  ProcessPayment(double  cash)  =  0;
		- virtual  void  ProcessRest(double  cash)  =  0;
	- destructor virtual
		- virtual  ~IPayment()  =  default;
10. Cashpayment
	- mosteneste Interfata IPayment
11. Food
	- clasa de baza abstracta
	 - variabila:
		 - double "pret"
	- constructor si deconstructor (virtual)
	- metoda virtuala de afisare si getter virtual
12. Pizza
	-	mosteneste clasa abstracta Food
	-	variabila:
		-	string "nume"
	- constructor
	- suprascrie afisarea:
		- afiseaza "Pizza " [nume] " are pretul" [get_pre()]
13. Afis
	- clasa de baza abstracta
	- metode virtuale :
		-  virtual  double  aria(){ cout  <<  "Aria afisului este: \n"; return  0;}
		- virtual  void  desen(){cout<<"Desenul afisului este: \n";}
		-	virtual  ~Afis()  =  default;
14. Dreptunghi
	- mosteneste clasa Afis
	- variabile: 
		- double l, L
	- supracrie metoda arie pentru a calcula aria afisului dreptunghic. 
15. Patrat
	- mosteneste clasa Afis
	- variabile: 
		- double l
	- supracrie metoda arie pentru a calcula aria afisului patrat. 
16. Triunghi
	- mosteneste clasa Afis
	- variabile: 
		- double l, h
	- supracrie metoda arie pentru a calcula aria afisului triunghic
17. Afis3D
	-	suprascrie desen
	-	void desen3D - DOWNCASTING
18. Cinema
	- variabile statice:
		- int "nr_sali", "nr_filne"
19. MyException
	-	variabila string: "msg"
	-	pentru exceptii
