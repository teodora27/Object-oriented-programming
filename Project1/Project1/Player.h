#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Subject.h"
#include <utility> 

class Player : public Subject {
private:
    const int coloane = 10;
    const int randuri = 8;
    const float lungime_patrat = 1000.0f / coloane;
    const float inaltime_patrat = 800.0f / randuri;

    sf::Texture* texture;
    sf::RectangleShape img;
    std::pair<int, int> position;

    Player();

    ~Player();

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

public:
    static Player& getInstance();

    sf::RectangleShape GetImg();
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    std::pair<int, int> GetPosition() const;
    void SetPosition(std::pair<int, int> p);
};
