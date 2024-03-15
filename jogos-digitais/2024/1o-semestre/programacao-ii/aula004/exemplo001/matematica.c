#include "matematica.h"

int potencia (int base, int expoente) {

    int res = 1;

    for (int i = 1; i <= expoente; i++) {
        res = res * base;
    }

    return res;

}
