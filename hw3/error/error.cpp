#include "../norm/norm.h"
#include <cmath>

template <typename T>
T absoluteError(T exact, T approx)
{
	return std::abs(exact-approx);
}

template <typename T>
T relativeError(T exact, T approx)
{
	return absoluteError<T>(exact,approx) / exact;
}


template <typename T, std::size_t M>
T vRelativeError(Matrix<T,M,1> v1, Matrix<T,M,1> v2, int p)
{
  return relativeError(pNorm(v1,p),pNorm(v2,p));
}

template <typename T, std::size_t M>
T vAbsoluteError(Matrix<T,M,1> v1, Matrix<T,M,1> v2, int p)
{
  return absoluteError(pNorm(v1,p),pNorm(v2,p));
}



int main()
{
  
  Matrix<double,4,1> v1 = { { {-2},
                               {1},
                               {0},
                               {0} } };

  Matrix<double,4,1> v2 = { { {-1},
                               {1},
                               {0},
                               {0} } };

  std::cout << "relative: " << vRelativeError(v1,v2,1) << std::endl;
  std::cout << "absolute: " << vAbsoluteError(v1,v2,1) << std::endl;



}
