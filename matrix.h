#ifndef LNLAB1_MATRIX_H
#define LNLAB1_MATRIX_H

#include "ringinfo.h"
#include <stdio.h>
#include "stdlib.h"
#include "complex.h"

typedef struct Matrix Matrix;
typedef struct complex_number ComplexNumber;
typedef struct RingInfo RingInfo;
struct Matrix {
    int size_matrix;
    void *data;
    RingInfo *ring;
};

void InputMatrix(Matrix *, int);
void OutputMatrix(Matrix *);
Matrix *InitMatrix(int);
void CleanMemory(Matrix *);
void SumOfMatrix(Matrix *, Matrix *, Matrix *);
void MultiplicationOfMatrix(Matrix *, Matrix *, Matrix *);
void AddLinearCombination(Matrix *this, int, int, void*);


#endif //LNLAB1_MATRIX_H
