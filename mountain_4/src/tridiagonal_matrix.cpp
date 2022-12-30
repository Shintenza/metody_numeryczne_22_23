#include "include/tridiagonal_matrix.hpp"

Eigen::MatrixXd tridiagonal_matrix(Eigen::MatrixXd matrix) {
    int matrix_size = matrix.rows();
    Eigen::MatrixXd matrixCopy = matrix;
    for (int i = 0; i < matrix_size - 2; i++) {
        Eigen::MatrixXd P = Eigen::MatrixXd::Identity(matrix_size, matrix_size);
        P.block(i + 1, i + 1, matrix_size - 1 - i, matrix_size - 1 - i) = householder_matrix(matrixCopy.block(i + 1, i, matrix_size - i - 1, 1));
        matrixCopy = P * matrixCopy * P.transpose();
    }
    return matrixCopy;
}
