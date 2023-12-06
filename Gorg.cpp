#include "Gorg.h"

Gorg::Gorg() 
    : Competitor("george", 30, 15),
    max_shield(5)
{
    // Nothen
}

void Gorg::GetsAttacked() {
        int roll = rand() % 100;

    if (roll < 15) {
        if (++shield > max_shield){
            --shield;
        } 
    }
    else if (roll < 65) {
        shield -= (1 + (rand() % 2));
        if (shield < 0) {
            health -= (25 + (rand() % 6) );
        }
    
    }

}
