#include "Bee.h"

Bee::Bee() : coloane(10), randuri(8), lungime_patrat(1000.0f / coloane), inaltime_patrat(800.0f / randuri), hp(20), speed(0.5f), inner(0) {
    texture = new Texture;
    texture->loadFromFile("bee.png");
}

void Bee::setTexture(Texture* newTexture) {
    texture = newTexture;
}

pair<int, float> Bee::GetPosition() {
    return position;
}

void Bee::SetPosition(pair<int, float> newPosition) {
    position = newPosition;
}

RectangleShape Bee::GetImg() {
    img.setSize(Vector2f(lungime_patrat, inaltime_patrat));
    img.setPosition(Vector2f(position.second * lungime_patrat, (position.first + 0.15 * sin(inner*3)) * inaltime_patrat));
    img.setTexture(texture);
    return img;
}

void Bee::Move(float dt) {
    position.second -= dt * speed;
    inner += dt;
}

istream& operator>>(istream& in, Bee& bee) {
    in >> bee.hp;
    in >> bee.position.first >> bee.position.second;
    return in;
}

ostream& operator<<(ostream& out, Bee& bee) {
    out << "Sanatatea albinei: " << bee.hp << "\n";
    out << "Pozitia albinei: " << bee.position.first << " " << bee.position.second << "\n";
    return out;
}
