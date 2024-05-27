#include "Flower.h"

int Flower::GetCount() {
    return count;
}
sf::Texture* Flower::getTexture() {
    return texture;
}
void Flower::setTexture(sf::Texture* newTexture) {
    texture = newTexture;
}
void Flower::PositiveNumbers(std::pair<int, int>p) {
    if (p.first < 0 || p.second < 0)
        throw Exception("Error: Pozitia aleasa pentru floare nu este valida!\n");
}
void Flower::SetPosition(std::pair<int, int> newPosition) {
        position = newPosition;

   /* try {
        PositiveNumbers(newPosition);
    }
    catch (const Exception& e) {
        std::cout << e.what();
    }*/

}
std::pair<int, int> Flower::GetPosition() {
    return position;
}
int Flower::GetType() { return type; }
sf::RectangleShape Flower::GetImg()
{
    img.setSize(sf::Vector2f(lungime_patrat, inaltime_patrat));
    img.setPosition(sf::Vector2f(position.second * lungime_patrat, position.first * inaltime_patrat));
    img.setTexture(texture);
    return img;
}

Flower::Flower(int hp, int type) : hp(hp), type(type) {
    count++;
}

Flower::Flower(const Flower& other) : hp(other.hp), type(other.type), texture(nullptr), position(other.position), img(other.img) {
    if (other.texture != 0) {
        texture = new sf::Texture(*other.texture);
    }
    count++;
}

Flower& Flower::operator=(const Flower& other) {
    delete texture;
    hp = other.hp;
    type = other.type;
    position = other.position;
    img = other.img;
    if (other.texture != 0) {
        texture = new sf::Texture(*other.texture);
    }
    else {
        texture = 0;
    }
    return *this;
}

Flower::~Flower() {
    delete(texture);
}

void Flower::SelectPrincipalFlower() {
    std::cout << "Ai selectat o floare ";
}

void Flower::Update() {
    Player& player = Player::getInstance();
    std::pair<int, int> pos = player.GetPosition();
    if (this != nullptr && pos.first >= 1 && pos.first < 7 && pos.second >= 1) {
        std::cout << "Ma descurc eu cu albinele\n";
        hp++;
    }
    else if (this != nullptr) {
        std::cout << "Florile se descurca ele\n";
    }
}

int Flower::count = -4;