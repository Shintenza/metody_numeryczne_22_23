#include <eigen3/Eigen/Dense>
#include <iomanip>
#include <iostream>
#include <vector>

#include "include/matrix.hpp"
#include "include/power_method.hpp"

int main() {

    Eigen::MatrixXd A = give_matrix();
    Eigen::Vector<double, 6> starting_vector = {1, 2, 3, 4, 5, 6};

    Eigen::VectorXd e1 = starting_vector.normalized();

    double lambda = 0;
    double lambda_next = 0;

    get_first_eigenvalue(A, e1, lambda, lambda_next);

    std::cout << "First eigenvalue is: " << lambda_next << std::endl;
    std::cout << "First eigenvector is :\n" << e1 << std::endl;

    Eigen::VectorXd e2 = (starting_vector - e1 * (e1.transpose() * starting_vector)).normalized();

    get_second_eigenvalue(A, e2, lambda, lambda_next, e1);

    std::cout << "Second eigenvalue is: " << lambda_next << std::endl;
    std::cout << "Second eigenvector is :\n"<< e2 << std::endl;
}
