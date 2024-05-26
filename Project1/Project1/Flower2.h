#pragma once

#include "Flower.h"

class Flower2 : virtual public Flower {
private:
    bool duplicate;
public:
    Flower2();
    void Polenizare() override;
    void DeadFlower() override;
    void SelectFlower2();
};

