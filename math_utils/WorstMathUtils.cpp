#include "WorstMathUtils.h"

int WorstMathUtils::gcd(int a, int b)
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int WorstMathUtils::lcm(float a, float b)
{
    int scale_factor = 1;  // Adjust the scale factor based on your requirements

    int intA = static_cast<int>(a);
    int intB = static_cast<int>(b);
    while((intA != a) && (intB != b)){
        scale_factor *= 10;
        intA = static_cast<int>(a * scale_factor);
        intB = static_cast<int>(b * scale_factor);
        a *= scale_factor;
        b *= scale_factor;
    }
    // Calculate LCM using integers
    int gcd = intA;
    while (gcd % intB != 0) {
        gcd += intA;
    }

    return gcd;
}