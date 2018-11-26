#ifndef NORM_H
#define NORM_H
#include "../matrixlib/matrix.h"
#include <limits>
#include <cmath>

template <typename T, std::size_t M>
double pNorm(Matrix<T,M,1> vect, int p)
{
  if(p == std::numeric_limits<int>::max())
  {
    T myMax = vect[0][0];
    for(int i=0; i<M; ++i)
    {
      if(vect[i][0] > myMax)
        myMax = vect[i][0];
    }
    return myMax;
  }

  double pSum = 0;
  for(int i=0; i<M; ++i)
    pSum += std::pow(std::abs(vect[i][0]),p);

  return std::pow(pSum, 1.0/p);
}
#endif
