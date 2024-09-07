#include <stdio.h>
#include "mathTools.h"

int main(void) {
    double a = 3;
    for (int i = 0; i < 10; i++) {
        printf("%.5f à la puissance %d est égal à %.5f\n", a, i, power(a, i));
    }
    for (int i = 0; i > -10; i--) {
        printf("%.5f à la puissance %d est égal à %.5f\n", a, i, power(a, i));
    }
}
