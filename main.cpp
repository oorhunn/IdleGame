#include <iostream>
#include <memory>
#include <typeinfo>
#include <thread>
#include <vector>
#include <chrono>

#include "player/User.h"

double determinant(const std::vector<std::vector<double>>& mat);
std::vector<std::vector<double>> generateRandomMatrix(int rows, int cols);
int randomZeroOrOne();
void printMatrix(const std::vector<std::vector<double>>& mat);




int main(int, char**){
    // std::thread t(determinant, 1);
    // std::thread t2(foo, 2);

    // t.join();
    // t2.join();
    auto start = std::chrono::high_resolution_clock::now();

    std::srand(static_cast<unsigned>(std::time(0)));

    const int rows = 9;
    const int cols = 10;

    std::vector<std::vector<double>> randomMatrix;
    randomMatrix = generateRandomMatrix(rows, cols);

    // Display the randomly generated matrix
    std::cout << "Randomly Generated Matrix:\n";
    // printMatrix(randomMatrix);

    // std::thread t1(determinant, randomMatrix);
    // std::thread t2(determinant, randomMatrix);

    // t1.join();
    // t2.join();


    double myNum = determinant(randomMatrix);
    double myNum2 = determinant(randomMatrix);



    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // Print the duration
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

// 2294880

    return 0;
}




void printMatrix(const std::vector<std::vector<double>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << mat[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int randomZeroOrOne() {
    return rand() % 2;
}


std::vector<std::vector<double>> generateRandomMatrix(int rows, int cols) {
    // Seed the random number generator with current time
    std::srand(static_cast<unsigned>(std::time(0)));

    std::vector<std::vector<double>> mat(rows, std::vector<double>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            mat[i][j] = randomZeroOrOne() + randomZeroOrOne();
        }
    }

    return mat;
}

double determinant(const std::vector<std::vector<double>>& mat) {
    int size = mat.size();

    // Base case: If the matrix is 1x1, return its only element
    if (size == 1) {
        return mat[0][0];
    }

    // Base case: If the matrix is 2x2, calculate the determinant using the formula ad - bc
    if (size == 2) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    double det = 0.0;

    // Laplace expansion to calculate determinant
    for (int i = 0; i < size; ++i) {
        std::vector<std::vector<double>> submat(size - 1, std::vector<double>(size - 1, 0.0));

        for (int row = 1; row < size; ++row) {
            int colIdx = 0;
            for (int col = 0; col < size; ++col) {
                if (col != i) {
                    submat[row - 1][colIdx++] = mat[row][col];
                }
            }
        }

        // Alternating signs for each term in the expansion
        double sign = (i % 2 == 0) ? 1.0 : -1.0;

        // Recursive call for submatrix
        det += sign * mat[0][i] * determinant(submat);
    }
    // std::cout << "det..." << det << "\n";
    return det;
}