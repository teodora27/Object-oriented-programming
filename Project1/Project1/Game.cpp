#include "Game.h"
#include "Flower1.h"
#include "Flower2.h"
#include "Flower3.h"
#include "Flower4.h"
#include "Player.h"
#include "Ladybug.h"
#include "FlowerFactory.h"
#include <iostream>
#include <random>
#include <cmath>
#include "DebugInfo.h"
#include <vector>


using namespace sf;
using namespace std;


sf::Vector2f Rotate(Vector2f v, float ang) {
    float x = v.x;
    float y = v.y;
    float Cos = cos(ang);
    float Sin = sin(ang);
    return { x * Cos - y * Sin, x * Sin + y * Cos };
}

bool contains(RectangleShape& rect, Vector2f pos) {
    return rect.getPosition().x <= pos.x && rect.getPosition().y <= pos.y && pos.x <= rect.getPosition().x + rect.getSize().x && pos.y <= rect.getPosition().y + rect.getSize().y;
}

int GenerateRandom(int min, int max) {
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<> distr(min, max);

    return distr(eng);
}


Game::Game() : angle(0) {}

void Game::ViewSetter(sf::RenderWindow& window) {
    view.setSize(sf::Vector2f(1000, 800));
    view.setCenter(sf::Vector2f(500, 400));
    window.setView(view);
}

void Game::LoadFont() {
    if (!font.loadFromFile("font.ttf")) {
        std::cout << "Failed to load font" << std::endl;
    }
}

void Game::SetPozitiiPolenizate(std::pair<int, int> p) {
    pozitiiAdaugate[p]++;
}

std::pair<int, int> Game::pozitiePreferata() {
    std::pair<int, int> maxi;
    int maxim = 0;
    for (const auto& x : pozitiiAdaugate) {
        if (x.second > maxim) {
            maxim = x.second;
            maxi = x.first;
        }
    }
    return maxi;
}

void Game::GridInitializer() {
    grid.resize(randuri, std::vector<sf::RectangleShape>(coloane));
    for (int i = 0; i < randuri; i++) {
        for (int j = 0; j < coloane; j++) {
            sf::RectangleShape rect;
            rect.setSize(sf::Vector2f(lungime_patrat, inaltime_patrat));
            rect.setPosition(sf::Vector2f(j * lungime_patrat, i * inaltime_patrat));
            if (i == 0 || j == 0 || i == randuri - 1) {
                rect.setFillColor(sf::Color(0, 204, 0));
            }
            else {
                if ((i + j) % 2 == 0) {
                    rect.setFillColor(sf::Color(92, 206, 95));
                }
                else {
                    rect.setFillColor(sf::Color(51, 255, 51));
                }
            }
            grid[i][j] = rect;
        }
    }
    flori.resize(randuri, std::vector<Flower*>(coloane));
    flori[0][1] = new Flower1();
    flori[0][1]->SetPosition({ 0,1 });
    flori[0][2] = new Flower2();
    flori[0][2]->SetPosition({ 0,2 });
    flori[0][3] = new Flower3();
    flori[0][3]->SetPosition({ 0,3 });
    flori[0][4] = new Flower4();
    flori[0][4]->SetPosition({ 0,4 });
}

void Game::MoneyTextSetter() {
    moneyText.setFont(font);
    moneyText.setCharacterSize(40);
    moneyText.setFillColor(sf::Color::White);
    moneyText.setString("$: 10");
    moneyText.setPosition(sf::Vector2f(10.f, 10.f));
}

void Game::SpawnBee() {
    std::unique_ptr<Bee> newBee;
    int rnd = GenerateRandom(0, 1);
    if (rnd == 0)
        newBee = std::make_unique<AngryBee>();
    else
        newBee = std::make_unique<Bee>();
    int linie = GenerateRandom(1, 6);
    newBee->SetPosition({ linie , coloane - 1 });
    bees.push_back(std::move(newBee));
    liniiSpawn.resize(randuri);
    liniiSpawn[linie]++;
    std::vector<int>v = liniiSpawn;
    sort(v.rbegin(), v.rend());
    cout << "Cate albine au fost pe fiecare linie, in ordinea nr de albine: ";
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0)
            cout << v[i] << " ";
        else
            break;
    }
    auto it = find(liniiSpawn.begin(), liniiSpawn.end(), v[0]);
    cout << "\nLinie preferata: "<<it-liniiSpawn.begin();
    cout << "\n";
}

void Game::PrintFlowerCount() {
    std::cout << "Numarul de flori create: " << Flower::GetCount() << std::endl;
}

void Game::GameLoop() {
    std::shared_ptr<Ladybug> bug = std::make_shared<Ladybug>(); 
    std::shared_ptr<Ladybug> clone = bug->clone();
    std::shared_ptr<Ladybug> bug2 = std::make_shared<Ladybug>(); 
    bug2.get()->SetPosition({ 7,4 });
    bugs.push_back(std::ref(*bug));
    bugs.push_back(std::ref(*bug2));


    Player& player = Player::getInstance();
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML Blue Background");
    ViewSetter(window);
    LoadFont();
    GridInitializer();
    MoneyTextSetter();
    int selector = 0;
    bool was_mouse_pressed = false;
    sf::Clock moveCooldownClock;
    float moveCooldown = 0.2f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (event.type == sf::Event::KeyPressed) {
            if (moveCooldownClock.getElapsedTime().asSeconds() >= moveCooldown) {
                auto cloned = bugs[0].get().clone();
                cloned->MoveUp();

                switch (event.key.code) {
                case sf::Keyboard::Up:
                    player.MoveUp();
                    for(auto bugg:bugs)
                        bugg.get().MoveDown();
                    moveCooldownClock.restart();
                    break;
                case sf::Keyboard::Down:
                    player.MoveDown();
                    for (auto bugg : bugs)
                        bugg.get().MoveUp();
                    
                    moveCooldownClock.restart();
                    break;
                case sf::Keyboard::Left:
                    player.MoveLeft();
                    for (auto bugg : bugs)
                        bugg.get().MoveRight();
                    moveCooldownClock.restart();
                    break;
                case sf::Keyboard::Right:
                    player.MoveRight();
                    for (auto bugg : bugs)
                        bugg.get().MoveLeft();
                    moveCooldownClock.restart();
                    break;
                default:
                    break;
                }
                player.SetPosition(player.GetPosition());
            }

        }

        bool is_mouse_pressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
        sf::Vector2f pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        for (int j = 1; j <= 4; j++) {
            if (contains(grid[0][j], pos) && (is_mouse_pressed && !was_mouse_pressed)) {
                selector = flori[0][j]->GetType();
            }
        }
        if (selector == 0) {
            angle = 0;
        }
        float dt = clock.restart().asSeconds();
        angle += dt * angularVelocity;
        for (int i = 1; i < randuri - 1; i++) {
            for (int j = 1; j < coloane; j++) {
                if (contains(grid[i][j], pos) && !is_mouse_pressed && was_mouse_pressed && !flori[i][j]) {
                    if (selector != 0) {
                        //if (selector == 1) {
                        //    flori[i][j] = new Flower1();
                        //}
                        //if (selector == 2) {
                        //    flori[i][j] = new Flower2(); //upcasting
                        //}
                        //if (selector == 3) {
                        //    flori[i][j] = new Flower3(); //upcasting
                        //}
                        //if (selector == 4) {
                        //    flori[i][j] = new Flower4();
                        //}

                        // flori[i][j]->SetPosition({ i,j });
                        //partea comanetata de mai sus s a transformat 
                        //in urmatoarele 3 randuri


                        Flower* newFlower = FlowerFactory::CreateFlower(selector);
                        newFlower->SetPosition({ i, j });
                        SetPozitiiPolenizate({ i,j });
                        flori[i][j] = newFlower;
                        player.Attach(flori[i][j]);
                         selector = 0;

                        try {
                            Flower1* flower1 = dynamic_cast<Flower1*>(flori[i][j]);
                            if (flower1) {
                                flower1->SelectFlower1();
                            }
                            else {
                                throw std::bad_cast();
                            }
                        }
                        catch (const std::bad_cast&) {
                            std::cout << "Ai selectat o floare de alt tip!\n";
                        }

                        cout << "Pozitie preferata: " << pozitiePreferata().first << " " << pozitiePreferata().second << "\n";
                    }
                }
                if (contains(grid[i][j], pos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
                    if (flori[i][j] != nullptr) {
                        flori[i][j]->DeadFlower(); //dynamic dispatch
                        player.Detach(flori[i][j]);
                        delete flori[i][j];
                        flori[i][j] = nullptr;
                    }
                }
            }
        }
        if (!is_mouse_pressed) {
            selector = 0;
        }
        was_mouse_pressed = is_mouse_pressed;
        if (beeSpawnClock.getElapsedTime().asSeconds() >= beeSpawnInterval) {
            SpawnBee();
            beeSpawnClock.restart();
            PrintFlowerCount();
        }

        for (int i = 0; i < bees.size(); i++) {
            bees[i]->Move(dt);
            Player* player1 = &player;
            /*if (floor(bees[i]->GetPosition().first) == player1->GetPosition().first &&
                floor( bees[i]->GetPosition().second) == player1->GetPosition().second)*/
            if(CheckPosition(bees[i],player1))
            {
                //delete(bees[i]);
                bees[i] = nullptr;
                std::swap(bees[i], bees[bees.size() - 1]);
                bees.pop_back();
            }
                
        }

        window.clear();
        for (int i = 0; i < randuri; ++i) {
            for (int j = 0; j < coloane; ++j) {
                window.draw(grid[i][j]);
                if (flori[i][j] != nullptr) {
                    window.draw(flori[i][j]->GetImg());
                    if (debug) {
                        DebugInfo<Flower> debugFlower;
                        debugFlower.print(*flori[i][j]);
                    }
                }
            }
        }
        for (int i = 0; i < bees.size(); i++) {
            if (debug) {
                DebugInfo<Bee> debugBee;
                debugBee.print(*bees[i]);
            }
            window.draw(bees[i]->GetImg());
        }
        for (int i = 0; i < randuri - 1; i++) {
            for (int j = 0; j < coloane; j++) {
                if (flori[i][j])
                {
                    Player* player1 = &player;
                    if (CheckPosition(flori[i][j], player1))
                        cout << "`We are in this toghether!\n";
                }
                for (int k = 0; k < bees.size(); k++) {
                    /*if (floor(bees[k]->GetPosition().first) == flori[i][j]->GetPosition().first &&
                        floor(bees[k]->GetPosition().second) <= flori[i][j]->GetPosition().second &&
                        flori[i][j])*/
                    if(floor(bees[k]->GetPosition().first) == i &&
                        floor(bees[k]->GetPosition().second) <= j &&
                        flori[i][j])
                    //if(CheckPosition(bees[k],flori[i][j]))
                    {
                        flori[i][j]->Polenizare();//dynamic dispatch
                        player.Detach(flori[i][j]);
                        delete flori[i][j];
                        flori[i][j] = nullptr;
                        //delete(bees[k]);
                        bees[k] = nullptr;
                        std::swap(bees[k], bees[bees.size() - 1]);
                        bees.pop_back();
                    }
                }
            }
        }

        window.draw(moneyText);
        if (selector != 0) {
            sf::VertexArray varray(sf::Quads, 4);
            varray[0].position = sf::Vector2f(-lungime_patrat * 0.5, -inaltime_patrat * 0.5);
            varray[1].position = sf::Vector2f(-lungime_patrat * 0.5, inaltime_patrat * 0.5);
            varray[2].position = sf::Vector2f(lungime_patrat * 0.5, inaltime_patrat * 0.5);
            varray[3].position = sf::Vector2f(lungime_patrat * 0.5, -inaltime_patrat * 0.5);
            for (int i = 0; i < 4; i++) {
                varray[i].position = Rotate(varray[i].position, angle) + pos;
            }
            sf::Texture* texture = nullptr;
            if (selector == 1) texture = flori[0][1]->getTexture();
            if (selector == 2) texture = flori[0][2]->getTexture();
            if (selector == 3) texture = flori[0][3]->getTexture();
            if (selector == 4) texture = flori[0][4]->getTexture();
            varray[0].texCoords = sf::Vector2f(0, 0);
            varray[1].texCoords = sf::Vector2f(0, texture->getSize().y);
            varray[2].texCoords = sf::Vector2f(texture->getSize().x, texture->getSize().y);
            varray[3].texCoords = sf::Vector2f(texture->getSize().x, 0);
            window.draw(varray, texture);
        }
       
        window.draw(player.GetImg());
        for(auto bg:bugs)
            window.draw(bg.get().GetImg());
        window.display();
    }
}
