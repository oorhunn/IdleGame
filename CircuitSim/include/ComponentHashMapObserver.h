#ifndef GRAPHOBSERVER_H
#define GRAPHOBSERVER_H
#include <vector>
#include <unordered_map>
#include <memory>

#include "Components.h"


using ComponentsHashMap = std::unordered_map<int, std::shared_ptr<Component>>;

// oberver interface for Components resistor, voltage values etc. incoming
class ComponentCatalogObserver { 
public:
    virtual void update(std::shared_ptr<ComponentsHashMap> newComponentCatalogPtr) = 0;

    virtual ~ComponentCatalogObserver() = default;
};


// subject class for the compnentCatalog hash map
class ComponentCatalog {

public:
    ComponentCatalog();
    ~ComponentCatalog();
    
    void registerObserver(std::shared_ptr<ComponentCatalogObserver> observer);
    void removeObserver(std::shared_ptr<ComponentCatalogObserver> observer);
    void notifyObservers();

    void addNewComponent(std::shared_ptr<Component> newComp);

private:
    std::shared_ptr<ComponentsHashMap> componentCatalogPtr;
    std::vector<std::shared_ptr<ComponentCatalogObserver>> observers;

};
#endif