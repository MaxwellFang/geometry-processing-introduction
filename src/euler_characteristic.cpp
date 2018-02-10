#include "euler_characteristic.h"
#include "edges.h"
#include <iostream>
using namespace std;

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE
  int E = edges(F).rows();
  Chi = F.maxCoeff() + 1 - E + F.rows();
  return Chi;
}
