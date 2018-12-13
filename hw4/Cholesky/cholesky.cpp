#include "../../hw3/matrixlib/matrix.h"
#include <iostream>
#include <chrono>

template <typename T, std::size_t M>
Matrix<T,M,M> choleskyFactorize(Matrix<T,M,M> A)
{
  Matrix<T,M,M> ret;
	for (int i=0; i<M; i++)
	{
		for (int j=0; j<(i + 1); j++)
		{
			double s=0;
			for (int k = 0; k < j; k++)
			{
				s += ret[i][k] * ret[j][k];
			}
			if (i == j)
			{
				ret[i][j] = std::sqrt(A[i][i] - s);
			}
			else
			{
				ret[i][j] = 1.0 / ret[j][j] * (A[i][j] - s);
			}
		}
	}
	return ret;
}

template <typename T, std::size_t M>
Matrix<T,M,1> choleskySolveSystem(Matrix<T,M,M> A, Matrix<T,M,1> b)
{
  auto R = choleskyFactorize(A);
  auto y = forwardSubstitute(R,b);
  auto x = backSubstitute(transpose(R),y);
  return x;

}

int main()
{
  const int i= 400;
  Matrix<double,i,i> A = genRandoms<double,i,i>();
  Matrix<double,i,1> x = genRandoms<double,i,1>();

  auto start = std::chrono::high_resolution_clock::now();
  auto sol = choleskySolveSystem(A, x);
  auto end = std::chrono::high_resolution_clock::now();
  auto dur = std::chrono::duration<double,std::milli>(end-start).count();
  std::cout << "time: " << dur << " ms" << std::endl;
}
