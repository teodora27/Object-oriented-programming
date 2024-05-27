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
