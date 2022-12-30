#pragma once
#include "givens_matrix.hpp"
#include <eigen3/Eigen/Dense>
#include <iostream>
#define EPS 0.00001

void qr_givens(Eigen::MatrixXd m);
