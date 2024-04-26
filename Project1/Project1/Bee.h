#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Bee {
private:
    const int coloane;
    const int randuri;
    const float lungime_patrat;
    const float inaltime_patrat;

    Texture* texture;
    RectangleShape img;
    pair<int, float> position;
    int hp;
    float inner;
protected:
    float speed;
public:
    Bee();

    void setTexture(Texture* newTexture);
    pair<int, float> GetPosition();
    void SetPosition(pair<int, float> newPosition);
    RectangleShape GetImg();
    void Move(float dt);

    friend istream& operator>>(istream& in, Bee& bee);
    friend ostream& operator<<(ostream& out, Bee& bee);
};
