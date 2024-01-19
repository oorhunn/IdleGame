#ifndef CIRCUIT_PATHS_H
#define CIRCUIT_PATHS_H

#include <vector>
#include <memory>
#include "Components.h"


class CircuitPathObserver { 
public:
    virtual void update(std::shared_ptr<std::vector<std::vector<int>>> newPtr) = 0;
    virtual ~CircuitPathObserver() = default;
};


// subject class
class CircuitPath {

public:
    CircuitPath();
    ~CircuitPath();

    void registerObserver(std::shared_ptr<CircuitPathObserver> observer);
    void removeObserver(std::shared_ptr<CircuitPathObserver> observer);

    void notifyObservers();
    
    void updatePath(std::shared_ptr<std::vector<std::vector<int>>> loopPtr); 

private:
    std::vector<std::shared_ptr<CircuitPathObserver>> observers;
    std::shared_ptr<std::vector<std::vector<int>>> circuitLoopsPtr;
};




#endif