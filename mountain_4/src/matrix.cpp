#include "include/matrix.hpp"

Eigen::MatrixXd give_matrix() {

    Eigen::MatrixXd A(6, 6);
    Eigen::Vector<double, 6> v1 = {19. / 12., 13. / 12., 5. / 6., 5. / 6., 13. / 12., -17. / 12.};
    Eigen::Vector<double, 6> v2 = {13. / 12., 13. / 12., 5. / 6., 5. / 6., -11. / 12., 13. / 12.};
    Eigen::Vector<double, 6> v3 = {5. / 6., 5. / 6., 5. / 6., -1. / 6., 5. / 6., 5. / 6.};

    A << v1, v2, v3, v3.colwise().reverse(), v2.colwise().reverse(), v1.colwise().reverse();

    return A;
}
