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

    double tau = 0.3819;

    auto resolvent = A - tau * I;
    auto resolvent_inverse = resolvent.inverse();

    double l = 0;
    double l_next = 0;

    do {
        z = resolvent_inverse * y;
        double z_norm = z.norm();
        y = z / z_norm;

        l = l_next;
        l_next = z_norm;
    } while (std::fabs(l_next - l > 0.000001));

    std::cout << z << "\n";
}
