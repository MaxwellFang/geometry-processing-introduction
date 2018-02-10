#include "edges.h"
#include <iostream>
#include <igl/slice.h>
#include <igl/sortrows.h>
using namespace std;

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E(F.rows()*3, 2);
  // ADD YOUR CODE HERE
  Eigen::MatrixXi E1(F.rows(), 2);
  Eigen::MatrixXi E2(F.rows(), 2);
  Eigen::MatrixXi E3(F.rows(), 2);

  E1.col(0) << F.col(0);
  E1.col(1) << F.col(1);
  E2.col(0) << F.col(1);
  E2.col(1) << F.col(2);
  E3.col(0) << F.col(2);
  E3.col(1) << F.col(0);
  E << E1,
       E2,
       E3;
  Eigen::MatrixXi e1 = (E.array().col(0) > E.array().col(1)).select(999999, E.col(0));
  Eigen::MatrixXi e2 = (E.array().col(0) > E.array().col(1)).select(999999, E.col(1));
  E.col(0) = e1;
  E.col(1) = e2;
  Eigen::MatrixXi I;
  Eigen::MatrixXi Y;
  igl::sortrows(E,true,Y,I);
  E = Y.topRows(E.rows()/2);
  return E;
}
