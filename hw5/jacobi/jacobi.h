#ifndef JACOBI_H
#define JACOBI_H
#include "../../hw3/maceps/maceps.h"
#include "../../hw3/matrixlib/matrix.h"

template <typename T, std::size_t M>
Matrix<double,M,1> jacobi(Matrix<T,M,M> A, Matrix<double,M,1> b)
{
  const int maxiter = 1000;
  Matrix<double,M,1> x = genZeros<double,M,1>();

  for(int n=0; n<maxiter; ++n)
  {
    auto xnew = genZeros<double,M,1>();
    for(int i=0; i<M; ++i)
    {
      double sum = 0;
      for(int j=0; j<M; ++j)
      {
        if(j != i)
        {
          sum += A[i][j] * x[j][0];
        }
      }
      xnew[i][0] = (b[i][0] - sum) / A[i][i];
    }

    if(allClose(x,xnew)) break;

    x = xnew;
  }
  return x;
}


template <typename T, std::size_t M>
Matrix<double,M,1> parallelJacobi(Matrix<T,M,M> A, Matrix<double,M,1> b)
{
  const int maxiter = 1000;
  Matrix<double,M,1> x = genZeros<double,M,1>();

  for(int n=0; n<maxiter; ++n)
  {
    auto xnew = genZeros<double,M,1>();
#pragma omp parallel for
    for(int i=0; i<M; ++i)
    {
      double sum = 0;
      for(int j=0; j<M; ++j)
      {
        if(j != i)
        {
          sum += A[i][j] * x[j][0];
        }
      }
      xnew[i][0] = (b[i][0] - sum) / A[i][i];
    }

    if(allClose(x,xnew)) break;

    x = xnew;
  }
  return x;
}

#endif
