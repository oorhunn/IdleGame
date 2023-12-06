#include <ctime>
#include <iostream>
#include "Boov.h"
#include "Gorg.h"
#include <memory>

int main () {
    srand(static_cast<unsigned>(time(0)));

    int shield = 100;
    int health = 100000;
    std::string name = "oh";
    const int NUMBER_OF_SIM = 10000;

    int booWins = 0;
    int georgeWins = 0;


    for (int i = 1; i <= NUMBER_OF_SIM; i++){
        Boov oh(name, health, shield);
        Gorg george;
        
        while ((oh.IsDefeated() == false)&&(george.IsDefeated() == false)) {
            george.GetsAttacked();
            if (!george.IsDefeated()) {
                oh.GetsAttacked();
            }

        }
        if (george.IsDefeated()) {
            ++booWins;
        }
        else {
            ++georgeWins;
        }
    }
    std::cout << "average nubmer of rounds until defeat" << std::endl;
    double average = booWins + static_cast<double>(NUMBER_OF_SIM);
    std::cout << booWins << std::endl;
    std::cout << georgeWins << std::endl;


    

    return 0;
}