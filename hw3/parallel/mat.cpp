#include "../matrixlib/matrix.h"
#include <iostream>
#include <vector>
#include <chrono>


template<typename L, typename R, typename T = decltype(L()*R()), std::size_t M, std::size_t N, std::size_t O >
Matrix<T,M,O> parallelMult(const Matrix<L,M,N> lh, const Matrix<R,N,O> rh)
{
  Matrix<T,M,O> temp = genZeros<T,M,O>();
#pragma omp parallel
  {
#pragma omp for
    for(int i=0; i<M; ++i)
    {
      for(int j=0; j<O; ++j)
      {
        for(int k=0; k<N; ++k)
        {
          temp[i][j] += lh[i][k] * rh[k][j];
        }
      }
    }
  }
  return temp;
}

template<typename L, typename R, typename T = decltype(L()*R()), std::size_t M, std::size_t N, std::size_t O >
Matrix<T,M,O> parallelMult2(const Matrix<L,M,N> lh, const Matrix<R,N,O> rh)
{
  Matrix<T,M,O> temp = genZeros<T,M,O>();
  {
    for(int i=0; i<M; ++i)
    {
      for(int j=0; j<O; ++j)
      {
        for(int k=0; k<N; ++k)
        {
          temp[i][j] += lh[i][k] * rh[k][j];
        }
      }
    }
  }
  return temp;
}

int main() 
{
  const int i = 720;

  Matrix<double,i,i> a = genRandoms<double,i,i>();
  Matrix<double,i,1> b = genRandoms<double,i,1>();

  auto start = std::chrono::high_resolution_clock::now();
  Matrix<double,i,1> temp =  parallelMult(a,b);
  auto stop = std::chrono::high_resolution_clock::now();
  auto pduration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 

  start = std::chrono::high_resolution_clock::now();
  temp = a*b;
  stop = std::chrono::high_resolution_clock::now();
  auto sduration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 

  std::cout << "serial:   " << (double)sduration.count() << "ms" << std::endl;
  std::cout << "parallel: " << pduration.count() << "ms" << std::endl;

}

