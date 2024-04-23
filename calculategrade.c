#include "functions.h"


char calculateGrade(float isa1, float isa2, float esa) {
    float score = (isa1 + isa2 + esa) / 1.8;

    if (score >= 90)
        return 'S';
    else if (score >= 80)
        return 'A';
    else if (score >= 70)
        return 'B';
    else if (score >= 60)
        return 'C';
    else if (score >= 50)
        return 'D';
    else if (score >= 40)
        return 'E';
    else
        return 'F';
}
