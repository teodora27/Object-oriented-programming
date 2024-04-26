#include "Flower2.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Flower2::Flower2() : Flower(20, 2) {
    sf::Texture* texture = new sf::Texture;
    texture->loadFromFile("floare2.png");
    setTexture(texture);
}

void Flower2::Polenizare() {
    std::cout << "Floarea de tip 2 a fost polenizata!\n";
}

void Flower2::DeadFlower() {
    std::cout << "Floare de tip 2 a murit!\n";
}

void Flower2::SelectFlower2() {
    SelectPrincipalFlower();
    std::cout << "de tipul 2\n";
}
