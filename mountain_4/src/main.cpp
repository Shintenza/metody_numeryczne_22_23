#include "include/matrix.hpp"
#include "include/qr_givens.hpp"
#include "include/tridiagonal_matrix.hpp"

#include <cmath>
#include <eigen3/Eigen/Dense>
#include <iomanip>
#include <iostream>

int main() {
    Eigen::MatrixXd A = give_matrix();
    Eigen::MatrixXd tridiagonal = tridiagonal_matrix(A);
    std::cout << std::fixed;
    qr_givens(tridiagonal);
}
