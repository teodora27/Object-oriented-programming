#pragma once
#include <iostream>
#include <typeinfo>

template<typename T>
class DebugInfo {
public:
    static void print(T& object) {
        std::cout << "Debugging info for object of type " << typeid(T).name() << std::endl;
        std::cout << "Pozitie: " << object.GetPosition().first << " " << object.GetPosition().second << std::endl;
    }
};
// la Flower si la Bee adaugi o functie cu acelasi nume, 
// acelasi tip de date returnat si acelasi tip de parametrii
// clasele template NU, NICIODATA, Never nu le spargi in .cpp (preferabil stergi comentariul asta in viitor)