#pragma once

#include "Flower.h"

class Flower1 : public Flower {
public:
    Flower1();
    void Polenizare() override;
    void DeadFlower() override;
    void SelectFlower1();
};
