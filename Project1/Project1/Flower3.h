#pragma once

#include "Flower.h"

class Flower3 : virtual public Flower {
private:
    int extraPower;
public:
    Flower3();
    void Polenizare() override;
    void DeadFlower() override;
};
