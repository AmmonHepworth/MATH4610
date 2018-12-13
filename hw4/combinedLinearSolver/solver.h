#include "../../hw3/matrixlib/matrix.h"
#include "../gaussianElim/gaussianElim.h"
#include <iostream>


template <typename T, std::size_t M, std::size_t N>
Matrix<T,M,1> solveSystemGaussian(Matrix<T,M,N> A, Matrix<T,M,1> b)
{
  Matrix<T,M,N+1> modifiedMat;
  for(int i=0; i<M; ++i)
    for(int j=0; j<M; ++j)
      modifiedMat[i][j] = A[i][j];

  for(int i=0; i<M; ++i)
    modifiedMat[i][N] = b[i][0];


  modifiedMat = rowReduce(modifiedMat);

  Matrix<T,M,N> noModMat;
  for(int i=0; i<M; ++i)
    for(int j=0; j<N; ++j)
      noModMat[i][j] = modifiedMat[i][j];

  Matrix<T,M,1> nb;
  for(int i=0; i<M; ++i)
    nb[i][0] = modifiedMat[i][N];

  auto sol = backSubstitute(noModMat,nb);
  return sol;
}

