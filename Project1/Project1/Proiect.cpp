#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <random>
#include <cmath>
#include <exception>
#include <string>
#include "Exception.h"
#include "Flower.h"
#include "Flower1.h"
#include "Flower2.h"
#include "Flower3.h"
#include "Flower4.h"
#include "Bee.h"
#include "AngryBee.h"
#include "Game.h"
#include "Player.h"

using namespace sf;
using namespace std;


int main() {
    Game game;
    game.GameLoop();
    return 0;
}

/*
CERINTE
Moștenire
✅• Definiți minim două ierarhii diferite de moștenire (două ierarhii de moștenire
sunt considerate diferite dacă nu au aceeași clasă de bază și aceeași
clasă derivată).
    -ierarhiile sunt: Bee si Flower

✅• Minim o dată membru și minim o metodă care să aibă modificatorul de
acces protected (în mod util, să fie accesate/apelate dintr-o clasă care le
moștenește).
    -data membra speed din clasa Bee e protected
    -in clasa Flower, functia void SelectPrincipalFlower() e protected si e apelasa in
    clasele derivate Flower1 si Flower2

✅• Cel puțin o situație în care să apelați constructorul (cu parametri) al clasei
de bază, folosind lista de inițializare din constructorul clasei derivate.
    Flower1() : Flower(10, 1) {
        sf::Texture* texture = new sf::Texture;
        texture->loadFromFile("floare1.png");
        setsf::Texture(texture);
    }

Metode virtuale și clase abstracte
✅• Definiți și extindeți (moșteniți) minim o clasă abstractă (poate avea date
membru, dar are cel puțin o metodă pur virtuală).
    -clasa abstracta este Flower, are functia pur virtuala: virtual void DeadFlower() = 0;
    e mostenita de 4 subclase, in care functia e suprascrisa

✅• Definiți cel puțin 2 metode virtuale care să fie suprascrise în clasele moștenitoare.
Pot fi pur virtuale sau cu o implementare implicită. Se iau în considerare
și metodele definite la celelalte subpuncte, exceptând destructorii
virtuali.
    -void DeadFlower()
    -void Polenizare()

Polimorfism la execuție
✅• Identificați și marcați prin câte un comentariu minim 2 instanțe în care să
aibă loc polimorfism la execuție (dynamic dispatch) în proiectul vostru (e.g.
apelul unor metode virtuale prin intermediul unor pointeri/referințe către
clasa de bază).
    - flori[i][j]->DeadFlower(); //dynamic dispatch
    - flori[i][j]->Polenizare(); //dynamic dispatch

✅• Identificați și marcați prin câte un comentariu minim 2 instanțe de upcasting
în codul vostru (e.g. atribuirea unor obiecte de tipul unor clase moștenite
la pointeri/referințe către clasa de bază).
    -flori[i][j] = new Flower2(); //upcasting
    -flori[i][j] = new Flower3(); //upcasting

Excepții
✅• Definiți minim un tip de excepție custom, care să extindă clasa exception
din biblioteca standard.
        class Exception : public exception {
    private:
        string errorMessage;
    public:
        Exception(const string& msg): errorMessage(msg) {}
        const char* what() const noexcept override {
            return errorMessage.c_str();
        }
    };

    void Flower::PositiveNumbers(std::pair<int, int>p) {
    if (p.first < 0 || p.second < 0)
        throw Exception("Error: Pozitia aleasa pentru floare nu este valida!\n");

✅• Aruncați excepții în minim 2 funcții/metode diferite (folosiți tipul de excepție
definit de voi sau pe cele din biblioteca standard).
    -throw bad_cast();
    - throw Exception("Error: Pozitia aleasa pentru floare nu este valida!\n");

✅• Implementați minim un bloc try...catch care să prindă o excepție definită
și generată de voi (cu specificarea explicită a tipului excepției capturate)
și să o trateze într-un fel (să afișeze un mesaj, să reîncerce operațiunea, să
arunce o altă excepție etc).

    static void PositiveNumbers(pair<int,int>p) {
        if (p.first < 0 || p.second < 0)
            throw Exception("Error: Pozitia aleasa pentru floare nu este valida!\n");
    }
    void SetPosition(pair<int, int> newPosition) {
        try {
            position = newPosition;
            PositiveNumbers(newPosition);
        }
        catch(const Exception& e){
            cout << e.what();
        }

    }


Variabile și metode statice
✅• Definiți și inițializați o variabilă membru statică în cel puțin o clasă.
        static int count;

✅• Implementați cel puțin două metode statice în clasele voastre (din care cel
puțin una trebuie să acceseze/folosească variabila statică definită la subpunctul
anterior).
    -static void PositiveNumbers(pair<int,int>p)
    -static int GetCount() { return count; }

Bonus
✅• Separați declarațiile și implementările din programul vostru folosind fișiere
header (.h/.hpp) și sursă (.cpp) distincte. Ar trebui să aveți câte un
fișier header și un fișier sursă pentru fiecare clasă din programul vostru.
✅• Identificați minim o situație de moștenire în diamant (trebuie să aibă sens
pentru tema voastră). Moștenirea în diamant se referă la a avea o clasă de
bază, pe care o moștenesc cu virtual două clase distincte, iar apoi aveți o
clasă care moștenește ambele clase intermediare.
    class Flower4 : public Flower2, public Flower3 {


*/

/*
CERINTE
Design patterns
✅• Implementați 3 object-oriented design patterns diferite (se acordă până la
un punct pentru fiecare design pattern implementat și folosit corect). (3p)
Observație: pattern-ul trebuie să se regăsească în codul scris de voi. De
exemplu, dacă ați folosit o clasă iterator deja existentă din biblioteca standard, nu înseamnă că ați implementat design pattern-ul iterator.
Referințe utile: design patterns cu exemple de cod și când se utilizează,
catalog de design patterns comune.
    Clasa Player e singleton.
    Clasa FlowerFactory e factory.
    Clasa Flower e observer pt Player(de fiecare data cand playarul intra pe tabla, anunta florile ca se ocupa el si le creste hp ul)


Programare generică
✅• Utilizați minim o clasă șablon (template) definită de voi. Trebuie să fie
parametrizată de cel puțin un tip de date generic (cel puțin un typename),
care să fie folosit în mod util în interiorul clasei (e.g. pentru a defini un
atribut, o metodă etc.). (1p)
    Clasa template DebugInfo

✅• Definiți și apelați minim o funcție șablon (poate fi funcție liberă sau metodă
a unei clase care nu este neapărat generică). Trebuie să fie parametrizată de
cel puțin un tip de date generic (cel puțin un typename), care să fie folosit
în definirea funcției (e.g. parametru, tip de date returnat). (1p)
     template <typename T1, typename T2>
    bool CheckPosition(T1& ob1,T2& ob2) {
        return floor(ob1->GetPosition().first) == ob2->GetPosition().first &&
            floor(ob1->GetPosition().second) == ob2->GetPosition().second;
    }

Biblioteca standard
✅• Utilizați minim două tipuri de date container diferite din STL în clasele
definite de voi. (1p)
Exemple: vector, array, list, set, map etc.
     std::map<std::pair<int, int>, int>pozitiiAdaugate;
     std::vector<std::vector<Flower*>> flori;

✅• Utilizați minim două funcții utilitare diferite din biblioteca standard (funcții libere, nu metode ale claselor din STL). (1p)
Exemple: sort, find, search, all_of/any_of/none_of, accumulate,
fill, generate, copy, reverse, orice alte funcții din fișierul header din
biblioteca standard <algorithm>.
     auto it = find(liniiSpawn.begin(), liniiSpawn.end(), v[0]);
     sort(v.rbegin(), v.rend());


• Utilizați în mod corespunzător două tipuri diferite de smart pointers din
biblioteca standard (se acordă un punct dacă ați folosit corect un tip de smart
pointers, două puncte dacă ați folosit două tipuri diferite). (2p)
Prin smart pointer ne referim la una dintre clasele std::reference_wrapper1,
std::unique_ptr, std::shared_ptr sau std::weak_ptr.
Puteți să folosiți aceste clase în locul referințelor sau pointerilor obișnuiți
din codul vostru.
Referințe utile: avantajele smart pointers, utilizarea smart pointers în C++.
Oficiu (1p)
         std::vector<std::unique_ptr<Bee>> bees;


Bonus - ai asta dar trebuie sa o configurezi
Utilizați în proiectul vostru o bibliotecă externă (alta decât biblioteca standard).
Poate să ofere orice fel de funcționalitate care se potrivește cu nevoile temei voastre:
interfață grafică, animații, audio, importarea/exportul datelor în diferite formate, conectarea la o bază de date, conexiuni pe rețea, interacțiune cu hardware-ul,
algoritmi specializați etc.
Puteți primi până la 2 puncte bonus pentru această cerință, în funcție de complexitatea bibliotecii alese și cât de bine se integrează cu proiectul vostru.
Pentru a primi punctajul complet, trebuie să includeți biblioteca în proiectul vostru într-un mod portabil, configurând în mod corespunzător build system-ul folosit
(CodeBlocks Project, Visual Studio Project, CMake, Makefile etc.), nu copiind
fișierele în proiectul/repository-ul vostru.

*/