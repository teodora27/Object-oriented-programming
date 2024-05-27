#pragma once

#include <vector>
#include "Observer.h"

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void Attach(Observer* observer);
    void Detach(Observer* observer);
    void NotifyObservers();
};
