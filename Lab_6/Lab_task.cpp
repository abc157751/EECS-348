#include <iostream>
#include <fstream>

static const int MAX_SIZE = 100;

// Function prototypes
void readMatrix(std::ifstream& fin, int matrix[MAX_SIZE][MAX_SIZE], int N);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int N);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N);

int main() {
    std::cout << "Lingfeng Li" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl << std::endl;

    std::string filename;
    std::cout <<"please enter the filename containing the matrices: ";
    std::cin >> filename;

    std:: ifstream fin(filename);

    int N;
    fin >> N; // Read the matrix size only once

    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    readMatrix(fin, matrixA, N);
    readMatrix(fin, matrixB, N);

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, N);

    std::cout << std::endl << "Matrix B:" << std::endl;
    printMatrix(matrixB, N);

    std::cout << std::endl << "Matrix Sum (A + B):" << std::endl;
    addMatrices(matrixA, matrixB, result, N);
    printMatrix(result, N);

    std::cout << std::endl << "Matrix Product (A * B):" << std::endl;
    multiplyMatrices(matrixA, matrixB, result, N);
    printMatrix(result, N);

    std::cout << std::endl << "Matrix Difference (A - B):" << std::endl;
    subtractMatrices(matrixA, matrixB, result, N);
    printMatrix(result, N);

    fin.close();
    return 0;
}

// Function definitions

void readMatrix(std::ifstream& fin, int matrix[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> matrix[i][j];
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
}

void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result[i][j] = matrix1[i][j] - matrix2[i][j];
}

void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
