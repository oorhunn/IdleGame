#include <vector>
#include <iostream>
#include <chrono>



class WorstMatrix {

public:
    WorstMatrix(int ROWS, int COLS);

    WorstMatrix(const WorstMatrix& matrix);
    WorstMatrix& operator=(const WorstMatrix& matrix);

    ~WorstMatrix();

    std::vector<std::vector<double>> GenerateRandomMatrix();
    int randomZeroOrOne();
    void PrintWorstMatrix();

    int CalculateDeterminant();
    int CalculateDeterminant(const std::vector<std::vector<double>>& matrix);


private:
    std::vector<std::vector<double>> this_matrix;
    int size;
    int rows;
    int cols;


};