#ifndef SIM_linear_tetmesh_linear_elasticity_dq_H
#define SIM_linear_tetmesh_linear_elasticity_dq_H

#include <Eigen/Dense>
#include <EigenTypes.h>

#include <assemble.h>
#include <linear_tet_linear_elasticity_dq.h>


namespace sim {

//some c++ trickery to allow for default call backs 
auto default_callback = [](auto &element_matrix){};

template<typename DerivedRet, typename DerivedV, typename DerivedQ, typename DefoType, typename DerivedVol, 
         typename DerivedParam, class ElementMatrixCallback = decltype(default_callback)>
void linear_tetmesh_linear_elasticity_dq(Eigen::VectorXx<DerivedRet> &H, Eigen::MatrixBase<DerivedV> &V,  Eigen::Ref<const Eigen::MatrixXi> E,
                                        const Eigen::MatrixBase<DerivedQ> &q, 
                                        const Eigen::MatrixBase<DefoType> &dphidX, const Eigen::MatrixBase<DerivedVol>  &volume, 
                                        const Eigen::MatrixBase<DerivedParam> &params,
                                        const ElementMatrixCallback func = default_callback);



}

#ifndef SIM_STATIC_LIBRARY
#   include <../src/linear_tetmesh_linear_elasticity_dq.cpp>
#endif

#endif
