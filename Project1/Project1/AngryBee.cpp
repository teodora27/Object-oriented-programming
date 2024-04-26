#include "AngryBee.h"

AngryBee::AngryBee()  {
        speed = 1.0f;
        sf::Texture* texture = new sf::Texture;
        texture->loadFromFile("bee2.png");
        setTexture(texture);
    }
