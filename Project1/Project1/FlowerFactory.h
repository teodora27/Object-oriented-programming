#pragma once

#include "Flower.h"
#include "Flower1.h"
#include "Flower2.h"
#include "Flower3.h"
#include "Flower4.h"

class FlowerFactory {
public:
    static Flower* CreateFlower(int type);
};
