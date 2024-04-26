#pragma once

#include "Flower2.h"
#include "Flower3.h"

class Flower4 : public Flower2, public Flower3 {
public:
    Flower4();
    void Polenizare() override;
    void DeadFlower() override;
};
