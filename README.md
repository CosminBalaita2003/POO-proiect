# POO-proiect
Numele Proiectului: proiectpoo.cpp
Tema: cinematograf
Clase:
  1. String - pentru a memora variabile de tip string pentru a fi utilizate in celelate clase
  2. Actor - retine numele actorului (String) si varsta sa, va fi utilizat pentru a creea cast-ul unui film
  3. Film - retine titlul (String)si durata filmului si un vector de Actori pentru a memora cast-ul
  4. Bilete - retine pretul, ora si minutul difuzarii, si in variabila student de tip bool daca este stuent sau nu. Daca este student se va oferi o reducere de 5 lei
  5. SalaCinema- retine numarul salii si numarul de locuri, iar in variabila restrictii de tip bool daca se aplica restrictii pandemice. In cazul in care se aplica restrictii numarul de locuri se imparte la 2.
Functionalitati:
    Aplica reducere de student daca parametrul primit este true (Bilete bilet(20, true); //se va oferi reducere).
    Aplica restrictii pandemice atunci cand este cazul:
            sala1.setRestrictii(true); ///se vor pune restrictii
            sala1.getNumar_locuri(sala1.getRestrictii());

                
