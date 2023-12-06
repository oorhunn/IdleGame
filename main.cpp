#include <ctime>
#include <iostream>
#include "Boov.h"

int main () {
    srand(static_cast<unsigned>(time(0)));

    int shield = 10;
    int health = 100;
    std::string name = "oh";
    const int NUMBER_OF_SIM = 10000;

    int roundSurvived = 0;

    for (int i = 1; i <= NUMBER_OF_SIM; i++){
        Boov oh(name, 100, 50);


        while (oh.IsDefeated() == false) {
            ++roundSurvived;
            oh.GetsAttacked();
        }

    }
    std::cout << "average nubmer of rounds until defeat" << std::endl;
    double average = roundSurvived + static_cast<double>(NUMBER_OF_SIM);
    std::cout << average << std::endl;

    

    return 0;
}