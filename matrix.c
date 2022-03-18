#include "matrix.h"



void SumOfMatrix(Matrix *s1, Matrix *s2, Matrix *res) {
    int n = res->size_matrix;
    if (res->data != NULL) {
        CleanMemory(res);
    }
    res->data = calloc(n * n, res->ring->size);
    for (int i = 0; i < n * n; i++) {
        res->ring->sum(s1->data + i * s1->ring->size, s2->data + i * s2->ring->size, res->data + i * res->ring->size);
    }
} //Сумма матриц
void MultiplicationOfMatrix(Matrix *s1, Matrix *s2, Matrix *res) {
    if (res->data != NULL) {
        CleanMemory(res);
    }
    int n = res->size_matrix;
    res->data = calloc(n * n, res->ring->size);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res->ring->zero(res->data + (i * n + j) * res->ring->size);
            for (int k = 0; k < n; k++) {
                void *temp = calloc(1, res->ring->size);
                res->ring->zero(temp);
                res->ring->mult(s1->data + (i * n + k) * s1->ring->size, s2->data + (k * n + j) * res->ring->size,
                                temp);
                res->ring->sum(res->data + (i * n + j) * res->ring->size, temp,
                               res->data + (i * n + j) * res->ring->size);
                free(temp);
            }
        }
    }
} //Произведение матриц
void AddLinearCombination(Matrix *this, int A, int B, void *scalar) {
    int n = this->size_matrix;
    for (int i = 0; i < n; i++) {
        void *temp = calloc(1, this->ring->size);
        this->ring->zero(temp);
        this->ring->mult(scalar, this->data + ((A - 1) * n + i) * this->ring->size, temp);
        this->ring->sum(this->data + ((B - 1) * n + i) * this->ring->size, temp,
                        this->data + ((B - 1) * n + i) * this->ring->size);
        free(temp);
    }
} //Добавление линейной комбинации строки к другой строке
void OutputMatrix(Matrix *this) {
    this->ring->output(this);
} //Вывод матрицы
void InputMatrix(Matrix *this, int random) {
    if (this->data != NULL) {
        CleanMemory(this);
    }
    this->ring->input(this, random);
} //Ввод матрицы
Matrix *InitMatrix(int size) {
    Matrix *this = (Matrix *) calloc(1, sizeof(struct Matrix));
    this->data = NULL;
    this->size_matrix = size;
    this->ring = NULL;
    return this;
} //Иницилизация матрицы размером n*n
void CleanMemory(Matrix *this) {
    free(this->data);
    this->data = NULL;
} //Ручной сборщик мусора


