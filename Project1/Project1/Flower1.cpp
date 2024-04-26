#include "Flower1.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Flower1::Flower1() : Flower(10, 1) {
    sf::Texture* texture = new sf::Texture;
    texture->loadFromFile("floare1.png");
    setTexture(texture);
}

void Flower1::Polenizare() {
    std::cout << "Floarea de tip 1 a fost polenizata!\n";
}

void Flower1::DeadFlower() {
    std::cout << "Floare de tip 1 a murit!\n";
}

void Flower1::SelectFlower1() {
    SelectPrincipalFlower();
    std::cout << "de tipul 1\n";
}
