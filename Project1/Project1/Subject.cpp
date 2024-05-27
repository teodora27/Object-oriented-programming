#include "subject.h"

void Subject::Attach(Observer* observer) {
    observers.push_back(observer);
}

void Subject::Detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::NotifyObservers() {
    for (Observer* observer : observers) {
        observer->Update();
    }
}
