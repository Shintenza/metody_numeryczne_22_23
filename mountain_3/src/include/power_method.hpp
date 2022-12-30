#pragma once
#include <eigen3/Eigen/Dense>

#define EPS 0.0000001

void get_first_eigenvalue(Eigen::MatrixXd a, Eigen::VectorXd &x, double &l, double &l_next);
void get_second_eigenvalue(Eigen::MatrixXd A, Eigen::VectorXd &x, double &l, double &l_next, Eigen::VectorXd &prev_e);
