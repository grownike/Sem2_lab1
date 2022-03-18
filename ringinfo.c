#include "ringinfo.h"

RingInfo *InitRingInfo(
        size_t size,
        void (*sum)(void *, void *, void *),
        void (*mult)(void *, void *, void *),
        void (*zero)(void *),
        void (*input)(Matrix *, int),
        void (*output)(Matrix *)) {
    RingInfo *ring = calloc(1, sizeof(RingInfo));
    ring->size = size;
    ring->sum = sum;
    ring->mult = mult;
    ring->zero = zero;
    ring->input = input;
    ring->output = output;
    return ring;
}


// МЕТОДЫ INT RING

void IntSum(void *x, void *y, void *res) {
    *(int *) res = *(int *) x + *(int *) y;
}

void IntMult(void *x, void *y, void *res) {
    *(int *) res = (*(int *) x) * (*(int *) y);
}

void IntZero(void *x) {
    *(int *) x = 0;
}

void IntInput(Matrix *this, int random) {
    srand(time(NULL));
    int n = this->size_matrix;
    this->data = calloc(n * n, this->ring->size);
    for (int i = 0; i < n * n; i++) {
        printf("I[%d][%d]:", 1 + i / n, 1 + i % n);
        if (random == 1) {
            *((int *) (this->data + i * this->ring->size)) = rand() % 200 - 100;
        } else if (random == 2) {
            *((int *) (this->data + i * this->ring->size)) = rand() % 150 - 75;
        } else {
            *((int *) (this->data + i * this->ring->size)) = input_integer();
        }
    }
    srand(time(NULL));
}

void IntOutput(Matrix *this) {
    int n = this->size_matrix;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8d ", *(int *) (this->data + (i * n + j) * this->ring->size));
        }
        printf("\n");
    }
    printf("\n");
}

// МЕТОДЫ INT RING

// МЕТОДЫ DOUBLE RING

void DoubleSum(void *x, void *y, void *res) {
    *(double *) res = *(double *) x + *(double *) y;
}

void DoubleMult(void *x, void *y, void *res) {
    *(double *) res = (*(double *) x) * (*(double *) y);
}

void DoubleZero(void *x) {
    *(double *) x = 0.0;
}

void DoubleInput(Matrix *this, int random) {
    srand(time(NULL));
    int n = this->size_matrix;
    this->data = calloc(n * n, this->ring->size);
    for (int i = 0; i < n * n; i++) {
        printf("R[%d][%d] = ", 1 + i / n, 1 + i % n);
        if (random == 1) {
            *((double *) (this->data + i * this->ring->size)) = ((rand() % 200 - 100) / -0.97);
        } else if (random == 2) {
            *((double *) (this->data + i * this->ring->size)) = ((rand() % 150 - 80) / -0.76);
        } else {
            *((double *) (this->data + i * this->ring->size)) = input_double();
        }
    }

}

void DoubleOutput(Matrix *this) {
    int n = this->size_matrix;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5lf ", *(double *) (this->data + (i * n + j) * this->ring->size));
        }
        printf("\n");
    }
    printf("\n");
}

// МЕТОДЫ DOUBLE RING

// МЕТОДЫ COMPLEX RING

void ComplexSum(void *x, void *y, void *res) {
    ((ComplexNumber *) res)->Re = ((ComplexNumber *) x)->Re + ((ComplexNumber *) y)->Re;
    ((ComplexNumber *) res)->Im = ((ComplexNumber *) x)->Im + ((ComplexNumber *) y)->Im;
}

void ComplexZero(void *x) {
    ((ComplexNumber *) x)->Re = 0.0;
    ((ComplexNumber *) x)->Im = 0.0;
}

void ComplexMult(void *x, void *y, void *res) {
    ((ComplexNumber *) res)->Re = ((ComplexNumber *) x)->Re * ((ComplexNumber *) y)->Re -
                                  ((ComplexNumber *) x)->Im * ((ComplexNumber *) y)->Im;
    ((ComplexNumber *) res)->Im = ((ComplexNumber *) x)->Re * ((ComplexNumber *) y)->Im +
                                  ((ComplexNumber *) x)->Im * ((ComplexNumber *) y)->Re;
}

void ComplexInput(Matrix *this, int random) {
    srand(time(NULL));
    int n = this->size_matrix;
    this->data = calloc(n * n, this->ring->size);
    for (int i = 0; i < n * n; i++) {
        printf("Z[%d][%d] = ", 1 + i / n, 1 + i % n);
        if (random == 1) {
            ComplexNumber z = {((rand() % 200 - 100) / -0.97), ((rand() % 200 - 100) / -0.97)};
            *((ComplexNumber *) (this->data + i * this->ring->size)) = z;
        } else if (random == 2) {
            ComplexNumber z = {((rand() % 150 - 90) / -0.84), ((rand() % 170 - 95) / -0.68)};
            *((ComplexNumber *) (this->data + i * this->ring->size)) = z;
        } else {
            *((ComplexNumber *) (this->data + i * this->ring->size)) = input_complex();
        }
    }

}

void ComplexOutput(Matrix *this) {
    int n = this->size_matrix;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            output_complex(*(ComplexNumber *) (this->data + (i * n + j) * this->ring->size));
        }
        printf("\n");
    }
    printf("\n");
}

void CreateRingInfo(Matrix *this, int type) {
    if (type == 0) {
        this->ring = InitRingInfo(sizeof(int),
                                  IntSum,
                                  IntMult,
                                  IntZero,
                                  IntInput,
                                  IntOutput
        );
    }
    if (type == 1) {
        this->ring = InitRingInfo(sizeof(double),
                                  DoubleSum,
                                  DoubleMult,
                                  DoubleZero,
                                  DoubleInput,
                                  DoubleOutput
        );
    }
    if (type == 2) {
        this->ring = InitRingInfo(sizeof(ComplexNumber),
                                  ComplexSum,
                                  ComplexMult,
                                  ComplexZero,
                                  ComplexInput,
                                  ComplexOutput
        );
    }
}