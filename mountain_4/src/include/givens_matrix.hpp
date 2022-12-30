#pragma once
#include <eigen3/Eigen/Dense>

Eigen::MatrixXd givens_matrix(Eigen::MatrixXd m, int i, int j);
