#include <ctime>
#include <iostream>
#include <cmath>
#include <memory>

#include "Boov.h"
#include "Gorg.h"

int lcm(float a, float b);
int gcd(int a, int b);
int RemoveDecimals(float number);

int main () {
    srand(static_cast<unsigned>(time(0)));
    int shield = 100;
    int health = 100000;
    std::string name = "oh";
    const int NUMBER_OF_SIM = 4;

    int booWins = 0;
    int georgeWins = 0;
    std::shared_ptr<Gorg> george = std::make_shared<Gorg>();
    std::shared_ptr<Boov> player = std::make_shared<Boov>(name, health, shield, 2.2, 1.2);

    int turn = lcm(player->GetAttackSpeed(), george->GetAttackSpeed());
    for (int game_tick = 0; game_tick < turn; ++game_tick){
        std::cout << "aa"<< std::endl;
    }

    // for (int i = 1; i <= NUMBER_OF_SIM; i++){
    //     std::shared_ptr<Boov> oh(new Boov(name, health, shield));
    //     std::shared_ptr<Gorg> george(new Gorg);
    //     std::shared_ptr<Gorg> george1(new Gorg);
    //     while ((oh->IsDefeated() == false)&&(george->IsDefeated() == false)) {
    //         george->GetsAttacked();
    //         if (!george->IsDefeated()) {
    //             oh->GetsAttacked();
    //         }
    //     }
    //     if (george->IsDefeated()) {
    //         ++booWins;
    //     }
    //     else {
    //         ++georgeWins;
    //     }
    //     std::cout << "smart ptr " << george << std::endl;
    //     std::cout << "smart ptr " << george2 << std::endl;

    // }
    std::cout << "average nubmer of rounds until defeat" << std::endl;
    std::cout << "booWins wins "<< booWins << " george wins "<< georgeWins << std::endl;


    return 0;
}


int gcd(int a, int b) {

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(float a, float b) {
    a = RemoveDecimals(a);
    b = RemoveDecimals(b);
    return (a * b) / gcd(a, b);
}

int RemoveDecimals(float number){
    bool isDecimalYet = true;

    while (isDecimalYet){
        float temp = std::floor(number);
        if (temp == number){
            isDecimalYet = false;
            break;
        }
        number = number * 10;
    }
    return number;

}
