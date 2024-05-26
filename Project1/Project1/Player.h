#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Subject.h"
#include <utility> 


class Player : public Subject {
    const int coloane = 10;
    const int randuri = 8;
    const float lungime_patrat = 1000.0f / coloane;
    const float inaltime_patrat = 800.0f / randuri;

    sf::Texture* texture;
    sf::RectangleShape img;
    std::pair<int, int> position;

    Player() : position({ 0, 8 }) {
        texture = new sf::Texture;
        if (!texture->loadFromFile("Dora.png")) {
            std::cerr << "Failed to load Dora.png" << std::endl;
        }
    }

    ~Player() {
        delete texture;
    }

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

public:
    static Player& getInstance() {
        static Player instance;
        return instance;
    }

    sf::RectangleShape GetImg() {
        img.setSize(sf::Vector2f(lungime_patrat, inaltime_patrat));
        img.setPosition(sf::Vector2f(position.second * lungime_patrat, position.first * inaltime_patrat));
        img.setTexture(texture);
        return img;
    }

    void MoveUp() {
        if (position.first > 0) {
            position.first--;
        }
    }

    void MoveDown() {
        if (position.first < randuri - 1) {
            position.first++;
        }            
    }

    void MoveLeft() {
        if (position.second > 0) {
            position.second--;
        }
    }

    void MoveRight() {
        if (position.second < coloane - 1) {
            position.second++;
        }
    }

    std::pair<int, int> GetPosition() const {
        return position;
    }
    void SetPosition(std::pair<int,int>p) {
        position = { p.first, p.second };
        NotifyObservers();
    }

};
