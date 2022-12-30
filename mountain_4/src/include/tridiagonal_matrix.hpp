#pragma once
#include <eigen3/Eigen/Dense>
#include "householder_matrix.hpp"

Eigen::MatrixXd tridiagonal_matrix(Eigen::MatrixXd matrix);
