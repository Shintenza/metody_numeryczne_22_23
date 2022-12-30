#include "include/givens_matrix.hpp"

Eigen::MatrixXd givens_matrix(Eigen::MatrixXd m, int i, int j) {
    int size = m.rows();
    Eigen::MatrixXd g_matrix = Eigen::MatrixXd::Identity(size, size);
    double c = m(i - 1, j) / std::sqrt(m(i - 1, j) * m(i - 1, j) + m(i, j) * m(i, j));
    double s = m(i, j) / std::sqrt(m(i - 1, j) * m(i - 1, j) + m(i, j) * m(i, j));
    g_matrix(i, j) = -s;
    g_matrix(j, i) = s;
    g_matrix(i, i) = c;
    g_matrix(j, j) = c;
    return g_matrix;
}
