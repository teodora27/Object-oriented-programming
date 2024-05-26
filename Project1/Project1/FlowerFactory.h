#pragma once

#include "Flower.h"
#include "Flower1.h"
#include "Flower2.h"
#include "Flower3.h"
#include "Flower4.h"

class FlowerFactory {
public:
    static Flower* CreateFlower(int type) {
        switch (type) {
        case 1:
            return new Flower1();
        case 2:
            return new Flower2();
        case 3:
            return new Flower3();
        case 4:
            return new Flower4();
        default:
            return nullptr;
        }
    }
};
