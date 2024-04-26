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
    e mostenita de 4 subclase, in care functia e suptrascrisa

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