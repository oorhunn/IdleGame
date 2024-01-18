#ifndef GRAPHOBSERVER_H
#define GRAPHOBSERVER_H
#include <vector>
#include <memory>
// oberver interface incoming
class Observer { 
public:
    virtual void update(std::vector<std::vector<int>> graphPaths) = 0;

    virtual ~Observer() = default;
};


class GraphObserver {

public:


private:


};

class CircuitGraph{

public:

private:

    void registerObserver(std::shared_ptr<Observer> observer);
    void removeObserver(std::shared_ptr<Observer> observer);

};

#endif
