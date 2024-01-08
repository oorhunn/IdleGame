#include "WorstMatrix.h"

WorstMatrix::WorstMatrix(int ROWS, int COLS)
    : rows(ROWS),
    cols(COLS)
{
    size = rows;
    std::srand(static_cast<unsigned>(std::time(0)));

}

WorstMatrix::WorstMatrix(const WorstMatrix &matrix)
    : rows(matrix.rows),
    cols(matrix.cols)
{
}

WorstMatrix &WorstMatrix::operator=(const WorstMatrix &matrix)
{
    if (this != &matrix){
        cols = matrix.cols;
        rows = matrix.rows;
    }
    return *this;
}

WorstMatrix::~WorstMatrix()
{
}

std::vector<std::vector<double>> WorstMatrix::GenerateRandomMatrix()
{
    std::vector<std::vector<double>> mat(rows, std::vector<double>(cols, 0));
    // may be try to multithread here 
    // TODO: make intervals adjustable
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            mat[i][j] = randomZeroOrOne() + randomZeroOrOne();
        }
    }

    return mat;}

int WorstMatrix::randomZeroOrOne()
{
    return rand() % 2;
}

void WorstMatrix::PrintWorstMatrix()
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << this_matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int WorstMatrix::CalculateDeterminant()
{
    if (size == 1) {
        return this_matrix[0][0];
    }

    // Base case: If the matrix is 2x2, calculate the determinant using the formula ad - bc
    if (size == 2) {
        return this_matrix[0][0] * this_matrix[1][1] - this_matrix[0][1] * this_matrix[1][0];
    }
    
    int det = 0;
    for (int i = 0; i < size; ++i) {
    std::vector<std::vector<double>> submat(size - 1, std::vector<double>(size - 1, 0.0));

    for (int row = 1; row < size; ++row) {
        int colIdx = 0;
        for (int col = 0; col < size; ++col) {
            if (col != i) {
                submat[row - 1][colIdx++] = this_matrix[row][col];
            }
        }
    }

    // Alternating signs for each term in the expansion
    int sign = (i % 2 == 0) ? 1.0 : -1.0;

    // Recursive call for submatrix
    det += sign * this_matrix[0][i] * CalculateDeterminant(submat);
    }
    // std::cout << "det..." << det << "\n";
    return det;
}
