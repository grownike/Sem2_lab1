#ifndef LNLAB1_COMPLEX_H
#define LNLAB1_COMPLEX_H

typedef struct Matrix Matrix;
typedef struct complex_number ComplexNumber;
typedef struct RingInfo RingInfo;

struct complex_number { /*Комплексные числа*/
    double Re;
    double Im;
};

double input_double();
int input_integer();
ComplexNumber input_complex();
void output_complex(ComplexNumber z);


#endif //LNLAB1_COMPLEX_H
