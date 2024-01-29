#ifdef _OPENMP
#include <omp.h>
#endif

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <Eigen/Dense>

template<typename MatrixType>
void fillMatrixRandom(MatrixType& matrix) {
    srand(time(nullptr));
    for (int i = 0; i < matrix.rows(); ++i) {
        for (int j = 0; j < matrix.cols(); ++j) {
            matrix(i, j) = static_cast<float>(rand()) / RAND_MAX;  // Random value between 0 and 1
        }
    }
}

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> run_time;

    int num_trials = 2;
    double series_av = 0;
    double parallel_av = 0;

    const int rows = 400;
    const int cols = 400;

    // Define two matrices
    Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> matrixA(rows, cols);
    Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> matrixB(rows, cols);

    // Fill matrices with random values
    fillMatrixRandom(matrixA);
    fillMatrixRandom(matrixB);
    Eigen::setNbThreads(30);

    // Multiply the matrices in series
    for (int i = 0; i < num_trials; ++i) {
        start_time = std::chrono::high_resolution_clock::now();
        Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> resultMatrix = matrixA * matrixB;
        end_time = std::chrono::high_resolution_clock::now();
        run_time = end_time - start_time;
        series_av += run_time.count();
    }
    int d;
    // Eigen::initParallel();
    // Multiply the matrices in parallel
    for (int j = 0; j < num_trials; ++j) {
        start_time = std::chrono::high_resolution_clock::now();
        Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> resultMatrixParallel = matrixA * matrixB;


        end_time = std::chrono::high_resolution_clock::now();
        run_time = end_time - start_time;
        parallel_av += run_time.count();
    }

    std::cout << "Time to multiply matrices in series:      " << series_av / num_trials << " seconds" << std::endl;
    std::cout << "Time to multiply matrices in parallel:    " << parallel_av / num_trials << " seconds" << std::endl;
    d = Eigen::nbThreads();
    std::cout << d << std::endl;

    return 0;
}
