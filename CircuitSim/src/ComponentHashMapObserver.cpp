#include "../include/ComponentHashMapObserver.h"


ComponentCatalog::ComponentCatalog() : 
    componentCatalogPtr(nullptr),
    observers()
{

}


ComponentCatalog::~ComponentCatalog(){}



void ComponentCatalog::notifyObservers(){
    for (const auto& observer : observers){
        observer->update(componentCatalogPtr);
    }
}

void ComponentCatalog::registerObserver(std::shared_ptr<ComponentCatalogObserver> observer){
    // observers.resize(observers.size() + 1);
    observers.push_back(observer);
}

void ComponentCatalog::removeObserver(std::shared_ptr<ComponentCatalogObserver> observer){
    for (auto it = observers.begin(); it != observers.end(); ) {
        if (*it == observer) {
            it = observers.erase(it);
            observers.resize(observers.size() - 1);
        } else {
            ++it;
        }
    }
}

void ComponentCatalog::addNewComponent(std::shared_ptr<Component> newComp){
    if (!componentCatalogPtr){
        componentCatalogPtr = std::make_shared<ComponentsHashMap>();
    }
    componentCatalogPtr->insert(std::make_pair(newComp->getComponentID(), newComp));

}


