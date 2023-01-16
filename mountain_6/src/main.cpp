#include <cmath>
#include <eigen3/Eigen/Dense>
#include <iostream>

int main() {
    std::cout << std::fixed;

    Eigen::MatrixXd A(5, 5);
    // clang-format off
    A << 2.0, -1.0, 0.0, 0.0, 1.0,
        -1.0,  2.0, 1.0, 0.0, 0.0,
         0.0,  1.0, 1.0, 1.0, 0.0,
         0.0, 0.0, 1.0, 2.0, -1.0,
         1.0, 0.0, 0.0, -1.0, 2.0;
    // clang-format on

    Eigen::Vector<double, 5> starting_vector = {1, 2, 3, 4, 5};
    Eigen::VectorXd y = starting_vector.normalized();

    Eigen::VectorXd z(A.size());

    Eigen::MatrixXd I(5, 5);
    I.setIdentity();

    double tau = 0.38197;

    Eigen::MatrixXd resolvent = A - tau * I;
    Eigen::PartialPivLU<Eigen::Ref<Eigen::MatrixXd> > lu(resolvent);


    double l = 0;
    double l_next = 0;

    do {
        z = lu.solve(y);
        double z_norm = z.norm();
        y = z / z_norm;

        l = l_next;
        l_next = z_norm;
    } while (std::fabs(l_next - l > 0.000001));
    std::cout << z << "\n";
}
