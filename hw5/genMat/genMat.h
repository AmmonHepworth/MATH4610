#ifndef GENSYMDDIAGDOM
#define GENSYMDDIAGDOM
#include "../../hw3/matrixlib/matrix.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>

template<typename T, std::size_t M>
Matrix<T,M,M> genSymmetricDiagDominant(T a, T b)
{
  Matrix<T,M,M> ret = genZeros<T,M,M>();
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(a,b);

  for(int i=0; i<M; ++i)
  {
    for(int j=i+1; j<M; ++j) 
    { 
      //produces a uniform distribution of real numbers
      ret[i][j] = (T)(dis(gen));
    }
  }

  for(int i=0; i<M; ++i)
  {
    for(int j=i; j<M; ++j) 
    { 
      ret[j][i] = ret[i][j];
    }
  }

  //diagonal dominance
  for(int i=0; i<M; ++i)
  {
    auto rowSum = std::accumulate(ret[i].begin(), ret[i].end(), 0.0, [](T a, T b){ return a + std::abs(b); });
    ret[i][i] = rowSum + std::abs(dis(gen))/2;
  }

  return ret;
}

template<typename T, std::size_t M>
Matrix<T,M,1> genRightHand(Matrix<T,M,M> mat)
{
  Matrix<T,M,1> ones;
  for(int i=0; i<M; ++i)
    ones[i][0] = 1;
  return mat*ones;
}
#endif
