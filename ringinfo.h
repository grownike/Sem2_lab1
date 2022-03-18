#ifndef LNLAB1_RINGINFO_H
#define LNLAB1_RINGINFO_H

#include "matrix.h"
#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#include "complex.h"

typedef struct Matrix Matrix;
typedef struct complex_number ComplexNumber;
typedef struct RingInfo RingInfo;
struct RingInfo{
    size_t size;
    void (*sum)(void *, void *, void *);
    void (*mult)(void *, void *, void *);
    void (*zero)(void *);
    void (*input)(Matrix *, int);
    void (*output)(Matrix *);
};


RingInfo *InitRingInfo(
        size_t size,
        void (*sum)(void *, void *, void *),
        void (*mult)(void *, void *, void *),
        void (*zero)(void *),
        void (*input)(Matrix *, int),
        void (*output)(Matrix *));

//МЕТОДЫ INT RING
void IntZero(void *);
void IntMult(void *, void *, void *);
void IntSum(void *, void *, void*);
void IntInput(Matrix *, int);
void IntOutput(Matrix *);
//МЕТОДЫ INT RING

// МЕТОДЫ DOUBLE RING
void DoubleZero(void *);
void DoubleMult(void *, void *, void *);
void DoubleSum(void *, void *, void*);
void DoubleInput(Matrix *, int);
void DoubleOutput(Matrix *);
// МЕТОДЫ DOUBLE RING

// МЕТОДЫ COMPLEX RING
void ComplexZero(void *);
void ComplexMult(void *, void *, void *);
void ComplexSum(void *, void *, void*);
void ComplexInput(Matrix *, int);
void ComplexOutput(Matrix *);
// МЕТОДЫ COMPLEX RING

void CreateRingInfo(Matrix *this, int type);

#endif //LNLAB1_RINGINFO_H
