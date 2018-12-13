#include "../../hw3/matrixlib/matrix.h"
#include <iostream>


template<typename T, std::size_t M, std::size_t N>
Matrix<double,M,N> rowReduce(Matrix<T,M,N> mat)
{
  Matrix<double,M,N> ret = mat;

  //for each column
  for(int j=0; j<N; ++j)
  {
    //find highest row value
    int max = j;
    for(int i=j; i<M; ++i)
    {
      if(std::abs(ret[i][j]) > std::abs(ret[max][j])) max = i;
    }
    //swap to top
    std::swap(ret[j], ret[max]);

    T pivot = ret[j][j];
    //reduce with all rows below
    for(int k=j+1; k<M; ++k)
    {
      T killer = ret[k][j] / pivot;
      for(int l=j; l<N; ++l)
      {
        ret[k][l] = ret[k][l] - (killer*ret[j][l]);
      }
    }
  }
  return ret;
}

