#include "include/qr_givens.hpp"

void qr_givens(Eigen::MatrixXd m) {
    int size = m.rows();

    double diff = 0;
    double tmp = 0;
    do {
        Eigen::MatrixXd Q(size, size);
        Q = givens_matrix(m, 1, 0);
        m = Q * m;
        Q.transposeInPlace();

        for (int i = 1; i < size - 1; i++) {
            Eigen::MatrixXd tmp = givens_matrix(m, i + 1, i);
            m = tmp * m;
            Q *= tmp.transpose();
        }
        m = m * Q;
        diff = tmp;
        tmp = m.diagonal().norm();
    } while (std::fabs(tmp - diff) > EPS);

    std::cout << m.diagonal() << std::endl;
}
