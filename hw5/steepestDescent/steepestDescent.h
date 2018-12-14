#ifndef STEEPEST_DESCENT_HPP
#define STEEPEST_DESCENT_HPP

#include "../../hw3/matrixlib/matrix.h"

template <typename T, std::size_t M>
Matrix<double,M,1> steepestDescent(Matrix<T,M,M> A, Matrix<T,M,1> b)
{
  const int iter = 1000;
  Matrix<T,M,1> x = genRandoms<T,M,1>();
  Matrix<T,M,1> r = b-A*x;

  auto bot = transpose(r)*A*r;
  auto top = (transpose(r)*r);
  auto a = top[0][0]/bot[0][0];
  Matrix<T,M,1> xnew = x;
  int i=0;
  do{
    ++i;
    x = xnew;
    r = b-A*x;
    bot = transpose(r)*A*r;
    top = (transpose(r)*r);
    a = top[0][0]/bot[0][0];
    xnew = x + a*r;
  }while(!allClose(x,xnew) && i < iter);
  return x;


}

#endif
