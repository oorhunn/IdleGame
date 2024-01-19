#include "../include/CircuitPaths.h"



CircuitPath::CircuitPath() :
    observers(),
    circuitLoopsPtr(nullptr)
{

}
CircuitPath::~CircuitPath() {}

void CircuitPath::registerObserver(std::shared_ptr<CircuitPathObserver> observer){
    observers.resize(observers.size() + 1);
    
    observers.push_back(observer);

}


void CircuitPath::removeObserver(std::shared_ptr<CircuitPathObserver> observer){
    for (auto it = observers.begin(); it != observers.end(); ) {
        if (*it == observer) {
            it = observers.erase(it);
            observers.resize(observers.size() - 1);
        } else {
            ++it;
        }
    }
}

void CircuitPath::notifyObservers() {
    for (const auto& observer : observers){
        observer->update(circuitLoopsPtr);
    }
}

void CircuitPath::updatePath(std::shared_ptr<std::vector<std::vector<int>>> loopPtr){
    if(!circuitLoopsPtr){
        circuitLoopsPtr = std::make_shared<std::vector<std::vector<int>>>();
    }
    circuitLoopsPtr = loopPtr;
}
