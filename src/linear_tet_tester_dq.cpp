#ifdef SIM_STATIC_LIBRARY
# include<../include/linear_tet_tester_dq.h>
#endif

template<typename HessianType, typename DefoType, typename DerivedV, typename Scalar, typename DerivedParams>
void sim::linear_tet_tester_dq(Eigen::DenseBase<HessianType> &out, const Eigen::MatrixBase<DerivedV> &q, const Eigen::Ref<const Eigen::RowVectorXi> element,  
                                    const Eigen::MatrixBase<DefoType> &dXinv, const Scalar &volume, Eigen::MatrixBase<DerivedParams> &params) {

    Eigen::Vector12x<Scalar> qe; qe << q.segment(3*element(0),3), q.segment(3*element(1),3), q.segment(3*element(2),3), q.segment(3*element(3),3); //qe
    Eigen::Matrix<typename DefoType::Scalar, 9,12> B = sim::flatten_multiply_right<Eigen::Matrix<typename DefoType::Scalar, 3,4> >(dXinv); //compute B

    Eigen::Vector9x<Scalar> dF; //type of dF

    d2psi_tester_dF(dF, unflatten<3,3>((B*qe).eval()), volume, params);

    out = B.transpose()*dF;

}