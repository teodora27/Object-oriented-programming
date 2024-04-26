#pragma once
#include <SFML/Graphics.hpp>
#include "Exception.h"
#include <iostream>

class Flower {
private:
    const int coloane = 10;
    const int randuri = 8;
    const float lungime_patrat = 1000.0f / coloane;
    const float inaltime_patrat = 800.0f / randuri;

    int hp;
    int type;
    sf::Texture* texture;
    std::pair<int, int> position;
    sf::RectangleShape img;
    static int count;
public:
    static int GetCount();
    virtual void DeadFlower() = 0;
    virtual void Polenizare() = 0;
    sf::Texture* getTexture();
    void setTexture(sf::Texture* newTexture);
    static void PositiveNumbers(std::pair<int, int>p);
    void SetPosition(std::pair<int, int> newPosition);
    int GetType();
    sf::RectangleShape GetImg();
    Flower(int hp, int type);
    Flower(const Flower& other);
    Flower& operator=(const Flower& other);

    virtual ~Flower();
protected:
    void SelectPrincipalFlower();
};
