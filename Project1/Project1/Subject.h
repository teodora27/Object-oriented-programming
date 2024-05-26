#pragma once

#include <vector>
#include "Observer.h"

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void Attach(Observer* observer) {
        observers.push_back(observer);
    }

    void Detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }


    void NotifyObservers() {
        for (Observer* observer : observers) {
            observer->Update();
        }
    }
};
