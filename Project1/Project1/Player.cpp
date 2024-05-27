#include "Player.h"

Player::Player() : position({ 0, 8 }) {
    texture = new sf::Texture;
    if (!texture->loadFromFile("Dora.png")) {
        std::cerr << "Failed to load Dora.png" << std::endl;
    }
}

Player::~Player() {
    delete texture;
}

Player& Player::getInstance() {
    static Player instance;
    return instance;
}

sf::RectangleShape Player::GetImg() {
    img.setSize(sf::Vector2f(lungime_patrat, inaltime_patrat));
    img.setPosition(sf::Vector2f(position.second * lungime_patrat, position.first * inaltime_patrat));
    img.setTexture(texture);
    return img;
}

void Player::MoveUp() {
    if (position.first > 0) {
        position.first--;
    }
}

void Player::MoveDown() {
    if (position.first < randuri - 1) {
        position.first++;
    }
}

void Player::MoveLeft() {
    if (position.second > 0) {
        position.second--;
    }
}

void Player::MoveRight() {
    if (position.second < coloane - 1) {
        position.second++;
    }
}

std::pair<int, int> Player::GetPosition() const {
    return position;
}

void Player::SetPosition(std::pair<int, int> p) {
    position = { p.first, p.second };
    NotifyObservers();
}
