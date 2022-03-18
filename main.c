#include <stdio.h>
#include "ringinfo.h"
#include "complex.h"
#include "stdlib.h"
#include "matrix.h"
#include "iso646.h"


int main() {
    int random = 0;
    int key0 = 1;
    int key1;
    int type;
    int size = 0;
    while (key0) {
        printf("Choose type of data witch you wanna use:\n0 Integer\n1 Real\n2 Complex\n3 Exit\n");
        type = input_integer();
        if (type == 3) {
            return 0;
        } else if (type == 2 or type == 1 or type == 0) {
            key0 = 0;
        } else {
            printf("Error: wrong number, try again\n");
        }
    }
    while (size < 1) {
        printf("Enter size of matrix:"); // Если ввести 404, то 2 матрицы автоматически сгенерируются. Использовалось для тестов
        size = input_integer();
        if (size == 404) {
            random = 1;
            size = 0;
        }
        if (size < 1) {
            printf("Error: size can not be zero or negative\n");
        }
    }
    Matrix *m1 = InitMatrix(size);
    Matrix *m2 = InitMatrix(size);
    Matrix *res = InitMatrix(size);
    CreateRingInfo(m1, type);
    m2->ring = m1->ring;
    res->ring = m1->ring;
    Matrix *m[3] = {m1, m2, res};
    key0 = 1;
    while (key0) {
        if (random) {
            InputMatrix(m1, random);
            random = 2;
            InputMatrix(m2, random);
            random = 0;
        }
        printf("What do you wanna do?\n0 Input matrix\n1 Output matrix\n2 Summa of two matrix\n3 Multiplication of two matrix\n"
               "4 Add linear combination of lines\n5 Delete matrix\n6 Exit\n");
        key1 = input_integer();
        switch (key1) {
            case 0:
                printf("Choose matrix:\n0 First matrix\n1 Second matrix\n");
                key0 = input_integer();
                if (key0 == 0 or key0 == 1) {
                    InputMatrix(m[key0], 0);
                } else {
                    printf("Error: wrong number\n");
                }
                key0 = 1;
                break;

            case 1:
                printf("Choose matrix:\n0 First matrix\n1 Second matrix\n2 Result-matrix\n");
                key0 = input_integer();
                if (key0 == 0 or key0 == 1 or key0 == 2) {
                    if (m[key0]->data == NULL) {
                        printf("Error: matrix doesn't exist\n");
                        key0 = 1;
                        break;
                    }
                    OutputMatrix(m[key0]);
                } else {
                    printf("Error: wrong number\n");
                }
                key0 = 1;
                break;

            case 2:
                if ((m1->data == NULL or m2->data == NULL)) {
                    printf("Error: one of matrix doesn't exist\n");
                    break;
                }
                printf("Result will be saved into result-matrix\n");
                SumOfMatrix(m1, m2, res);
                printf("Done\n");
                break;
            case 3:
                printf("0 First on first\n1 First on second\n2 Second on first\n3 Second on second\n");
                key0 = input_integer();
                if (key0 == 0 or key0 == 1 or key0 == 2 or key0 == 3) {
                    printf("Result will be saved into result-matrix\n");
                    switch (key0) {
                        case 0:
                            if (m1->data == NULL) {
                                printf("Error: first matrix doesn't exist\n");
                                break;
                            }
                            MultiplicationOfMatrix(m1, m1, res);
                            printf("Done\n");
                            break;
                        case 1:
                            if (m1->data == NULL or m2->data == NULL) {
                                printf("Error: one of matrix doesn't exist\n");
                                break;
                            }
                            MultiplicationOfMatrix(m1, m2, res);
                            printf("Done\n");
                            break;
                        case 2:
                            if (m1->data == NULL or m2->data == NULL) {
                                printf("Error: one of matrix doesn't exist\n");
                                break;
                            }
                            MultiplicationOfMatrix(m2, m1, res);
                            printf("Done\n");
                            break;
                        case 3:
                            if (m2->data == NULL) {
                                printf("Error: second matrix doesn't exist\n");
                                break;
                            }
                            MultiplicationOfMatrix(m2, m2, res);
                            printf("Done\n");
                            break;
                        default: {
                        }
                    }
                } else {
                    printf("Error: wrong number\n");
                }
                key0 = 1;
                break;
            case 4:
                printf("Choose matrix:\n0 First matrix\n1 Second matrix\n");
                key0 = input_integer();
                if (key0 == 0 or key0 == 1) {
                    if (m[key0]->data == NULL) {
                        printf("Error: matrix doesn't exist\n");
                    }
                    int n = m[key0]->size_matrix;
                    int A, B;
                    printf("Witch line A * scalar you wanna add to line B. Enter A and B\n");
                    A = input_integer();
                    B = input_integer();
                    if (!(A > 0 and B > 0 and A <= n and B <= n)) {
                        printf("Error: wrong line numbers\n");
                    }
                    printf("Enter scalar: ");
                    void *scalar = calloc(1, m[key0]->ring->size);
                    if (!type) {
                        *(int *) scalar = input_integer();
                    } else {
                        *(double *) scalar = input_double();
                    }
                    AddLinearCombination(m[key0], A, B, scalar);
                    printf("Done\n");
                    free(scalar);
                } else {
                    printf("Error: wrong number\n");
                }
                key0 = 1;
                break;
            case 5:
                printf("Choose matrix:\n0 First matrix\n1 Second matrix\n");
                key0 = input_integer();
                if (key0 == 0 or key0 == 1) {
                    if (m[key0]->data == NULL) {
                        printf("Error: matrix doesn't exist\n");
                        key0 = 1;
                        break;
                    }
                    CleanMemory(m[key0]);


                } else {
                    printf("Error: wrong number\n");
                }
                key0 = 1;
                break;
            case 6:
                key0 = 0;
                break;
            default:
                printf("Error: wrong number\n");
        }
    }
    free(m1->ring);
    for (int i = 0; i < 3; i++) {
        if (m[i]->data != NULL) {
            CleanMemory(m[i]);
        }
        free(m[i]);
    }
    return 0;

}
