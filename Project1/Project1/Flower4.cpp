#include "Flower4.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Flower4::Flower4() : Flower(45, 4) {
    sf::Texture* texture = new sf::Texture;
    texture->loadFromFile("floare4.png");
    setTexture(texture);
}

void Flower4::Polenizare() {
    std::cout << "Floarea de tip 4 a fost polenizata!\n";
}

void Flower4::DeadFlower() {
    std::cout << "Floare de tip 4 a murit!\n";
}
