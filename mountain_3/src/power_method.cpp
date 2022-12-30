#include "include/power_method.hpp"

void get_first_eigenvalue(Eigen::MatrixXd A, Eigen::VectorXd &x, double &l, double &l_next) {
    Eigen::VectorXd z(A.size());
    do {
        z = A*x;
        double z_norm = z.norm();
        x = z / z_norm;

        l = l_next;
        l_next = z_norm;
        
    } while(std::fabs(l_next-l) > EPS);
}

void get_second_eigenvalue(Eigen::MatrixXd A, Eigen::VectorXd &x, double &l, double &l_next, Eigen::VectorXd &prev_e) {
    Eigen::VectorXd z(A.size());
    do {
        z = A*x;
        double z_norm = z.norm();
        x = z / z_norm;

        x = (x - prev_e*(prev_e.transpose()*x)).normalized();

        l = l_next;
        l_next = z_norm;
        
    } while(std::fabs(l_next-l) > EPS);
}
