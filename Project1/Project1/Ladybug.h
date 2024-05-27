#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class Ladybug {
    const int coloane = 10;
    const int randuri = 8;
    const float lungime_patrat = 1000.0f / coloane;
    const float inaltime_patrat = 800.0f / randuri;

    sf::Texture* texture;
    sf::RectangleShape img;
    std::pair<int, int> position;

public:
    Ladybug();
    ~Ladybug();

    std::shared_ptr<Ladybug> clone() const;

    sf::RectangleShape GetImg();
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    std::pair<int, int> GetPosition() const;
    void SetPosition(std::pair<int, int> p);
};
