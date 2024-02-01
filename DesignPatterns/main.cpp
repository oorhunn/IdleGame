#include <iostream>
#include <vector>
#include "./include/CompositePattern/Composite.h"

int main() {
    Chassis* chassis = new Chassis("PC Chassis");
    chassis->Add(new FloppyDisk("3.5 inch Floppy"));
    
    std::cout << "Chassis Name: " << chassis->Name() << std::endl;
    std::cout << "Chassis Power: " << chassis->Power() << " watts" << std::endl;
    std::cout << "Chassis Net Price: $" << chassis->NetPrice() << std::endl;
    std::cout << "Chassis Discount Price: $" << chassis->DiscountPrice() << std::endl;
    
    delete chassis;
    
    return 0;
}
