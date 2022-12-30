#include "include/householder_matrix.hpp"

Eigen::MatrixXd householder_matrix(Eigen::VectorXd x) {
    Eigen::MatrixXd I = Eigen::MatrixXd::Identity(x.rows(), x.rows());
    double x_norm = x.norm();
    Eigen::VectorXd u = x;
    u(0, 0) += x_norm;
    double u_norm = u.norm();

    return (I - (2 * u * u.transpose()) / (u_norm * u_norm));
}
