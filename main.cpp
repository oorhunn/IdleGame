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
    const int NUMBER_OF_SIM = 1;

    int booWins = 0;
    int georgeWins = 0;
    std::shared_ptr<Gorg> george2(new Gorg);

    for (int i = 1; i <= NUMBER_OF_SIM; i++){
        Boov oh(name, health, shield);
        Gorg bigGeorge;
        Gorg* gorgPtr = &bigGeorge;
        // Gorg george1;
        std::shared_ptr<Gorg> george(new Gorg);
        std::shared_ptr<Gorg> george1(new Gorg);
        while ((oh.IsDefeated() == false)&&(george->IsDefeated() == false)) {
            george->GetsAttacked();
            if (!george->IsDefeated()) {
                oh.GetsAttacked();
            }
        }
        if (george->IsDefeated()) {
            ++booWins;
        }
        else {
            ++georgeWins;
        }
        std::cout << "smart ptr " << george << std::endl;
        std::cout << "smart ptr " << george2 << std::endl;
        std::cout << "static ptr " << gorgPtr << std::endl;

    }
    std::cout << "average nubmer of rounds until defeat" << std::endl;
    std::cout << "booWins wins "<< booWins << " george wins "<< georgeWins << std::endl;
    return 0;
}