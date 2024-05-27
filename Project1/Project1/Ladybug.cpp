#include "ladybug.h"

Ladybug::Ladybug() : position({ 7, 2 }) {
    texture = new sf::Texture;
    if (!texture->loadFromFile("bug.png")) {
        std::cout << "Failed to load ladybug.png" << std::endl;
    }
}

Ladybug::~Ladybug() {
    //delete texture;
    //nu mai e nevesar deoarece folosim smart pointers
}

std::shared_ptr<Ladybug> Ladybug::clone() const {
    return std::make_shared<Ladybug>(*this);
}

sf::RectangleShape Ladybug::GetImg() {
    img.setSize(sf::Vector2f(lungime_patrat, inaltime_patrat));
    img.setPosition(sf::Vector2f(position.second * lungime_patrat, position.first * inaltime_patrat));
    img.setTexture(texture);
    return img;
}

void Ladybug::MoveUp() {
    if (position.first > 0) {
        position.first--;
    }
}

void Ladybug::MoveDown() {
    if (position.first < randuri - 1) {
        position.first++;
    }
}

void Ladybug::MoveLeft() {
    if (position.second > 0) {
        position.second--;
    }
}

void Ladybug::MoveRight() {
    if (position.second < coloane - 1) {
        position.second++;
    }
}

std::pair<int, int> Ladybug::GetPosition() const {
    return position;
}

void Ladybug::SetPosition(std::pair<int, int> p) {
    position = { p.first, p.second };
}
