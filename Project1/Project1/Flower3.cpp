#include "Flower3.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Flower3::Flower3() : Flower(30, 3) {
    sf::Texture* texture = new sf::Texture;
    texture->loadFromFile("floare3.png");
    setTexture(texture);
}

void Flower3::Polenizare() {
    std::cout << "Floarea de tip 3 a fost polenizata!\n";
}

void Flower3::DeadFlower() {
    std::cout << "Floare de tip 3 a murit!\n";
}
