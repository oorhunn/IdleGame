#include "../../include/CompositePattern/Composite.h"


Equipment::Equipment(const char* name) :
    _name(name)
{

}

const char* Equipment::Name() {
    return _name;
}

int Equipment::Power() {
    return 0;
}

double Equipment::NetPrice() {
    return 0.0;
}

double Equipment::DiscountPrice() {
    return 0.0; 
}

FloppyDisk::FloppyDisk(const char* name) :
    Equipment(name)
{

}

int FloppyDisk::Power() {
    return 5;
}
double FloppyDisk::NetPrice() {
    return 20.0;
}
double FloppyDisk::DiscountPrice() {
    return 18.0;
}



CompositeEquipment::CompositeEquipment(const char* name) :
    Equipment(name)
{

}
CompositeEquipment::~CompositeEquipment(){

}

int CompositeEquipment::Power() {
    int totalPower = 0;
    for (auto& component : _equipment) {
        totalPower += component->Power();
    }
    return totalPower;
}

double CompositeEquipment::NetPrice() {
    double totalPrice = 0.0;
    for (auto& component : _equipment) {
        totalPrice += component->NetPrice();
    }
    return totalPrice;
}

double CompositeEquipment::DiscountPrice() {
    double totalDiscount = 0.0;
    for (auto& component : _equipment) {
        totalDiscount += component->DiscountPrice();
    }
    return totalDiscount;
}


void CompositeEquipment::Add(Equipment* equipment) {
    _equipment.push_back(equipment);
}


std::vector<Equipment*> CompositeEquipment::CreateIterator() {
    return _equipment;
}

Chassis::Chassis(const char* name) :
    CompositeEquipment(name)
{

}

int Chassis::Power() {
    return CompositeEquipment::Power() + 10;
}
