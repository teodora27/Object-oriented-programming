#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Flower.h"
#include "Bee.h"
#include "AngryBee.h"
#include "Ladybug.h"
#include "Player.h"

class Game {
private:
    const int coloane = 10;
    const int randuri = 8;
    const float lungime_patrat = 1000.0f / coloane;
    const float inaltime_patrat = 800.0f / randuri;
    const float angularVelocity = 2 * 3.141592653589793 / 2;
    std::vector<std::vector<sf::RectangleShape>> grid;
    std::vector<std::vector<Flower*>> flori;
    std::vector<std::unique_ptr<Bee>> bees;
    sf::View view;
    sf::Font font;
    float angle;
    sf::Clock clock;
    sf::Clock beeSpawnClock;
    sf::Clock beeMovementClock;
    const float beeSpawnInterval = 3.0f;
    const float beeMovementInterval = 2.0f;
    sf::Text moneyText;
    bool debug = false;
    std::map<std::pair<int, int>, int>pozitiiAdaugate;
    std::vector<int>liniiSpawn;
    std::vector<std::reference_wrapper<Ladybug>> bugs;

public:
    template <typename T1, typename T2>
    bool CheckPosition(T1& ob1,T2& ob2) {
        return floor(ob1->GetPosition().first) == ob2->GetPosition().first &&
            floor(ob1->GetPosition().second) == ob2->GetPosition().second;
    }
    void SetPozitiiPolenizate(std::pair<int, int>p) {
        pozitiiAdaugate[p]++;
    }
    std::pair<int, int>pozitiePreferata() {
        std::pair<int, int>maxi;
        int maxim = 0;
        for (auto& x : pozitiiAdaugate) {
            if (x.second > maxim) {
                maxim = x.second;
                maxi = x.first;
            }
        }
        return maxi;
    }
    Game();

    void ViewSetter(sf::RenderWindow& window);
    void LoadFont();
    void GridInitializer();
    void MoneyTextSetter();
    void SpawnBee();
    static void PrintFlowerCount();
    void GameLoop();
};
