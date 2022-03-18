#include <stdio.h>
#include "complex.h"


int input_integer() {
    int x;
    int key = 1;
    char buf[100];
    while (key == 1) {
        fgets(buf, 31, stdin);
        if (sscanf(buf, "%d", &x) != 1)
            printf("Error: enter number\n");
        else {
            key = 0;
        }
    }
    return x;
}

double input_double() {
    double x;
    int key = 1;
    char buf[100];
    while (key == 1) {
        fgets(buf, 31, stdin);
        if (sscanf(buf, "%lf", &x) != 1)
            printf("Error: enter number\n");
        else {
            key = 0;
        }
    }
    return x;
}

ComplexNumber input_complex() {
    double x, y;
    printf("A + Bi, enter A:");
    x = input_double();
    printf("Now enter B:");
    y = input_double();
    ComplexNumber z = {x, y};
    return z;
}

void output_complex(ComplexNumber z) {
    if (z.Im < 0) {
        printf("%4lf%4lfi       ", z.Re, z.Im);
        return;
    }
    printf("%4lf+%4lfi       ", z.Re, z.Im);
}




