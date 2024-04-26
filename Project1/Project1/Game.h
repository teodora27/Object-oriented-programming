#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Flower.h"
#include "Bee.h"
#include "AngryBee.h"

class Game {
private:
    const int coloane = 10;
    const int randuri = 8;
    const float lungime_patrat = 1000.0f / coloane;
    const float inaltime_patrat = 800.0f / randuri;
    const float angularVelocity = 2 * 3.141592653589793 / 2;
    std::vector<std::vector<sf::RectangleShape>> grid;
    std::vector<std::vector<Flower*>> flori;
    std::vector<Bee*> bees;
    sf::View view;
    sf::Font font;
    float angle;
    sf::Clock clock;
    sf::Clock beeSpawnClock;
    sf::Clock beeMovementClock;
    const float beeSpawnInterval = 3.0f;
    const float beeMovementInterval = 2.0f;
    sf::Text moneyText;

public:
    Game();

    void ViewSetter(sf::RenderWindow& window);
    void LoadFont();
    void GridInitializer();
    void MoneyTextSetter();
    void SpawnBee();
    static void PrintFlowerCount();
    void GameLoop();
};
