#include "../../hw3/matrixlib/matrix.h"
#include "../../hw3/maceps/maceps.h"

template <typename T, std::size_t M, std::size_t N>
Matrix<double,M,1> gaussSeidel(Matrix<T,M,N> A, Matrix<T,M,1> b)
{
	const int MAX_ITER = 1000;
	int iter = 0;
	Matrix<double,M,1> x = genRandoms<double,M,1>();
	Matrix<double,M,1> xtemp;
	do{
		++iter;
		xtemp = x;
		for(int i=0; i<M; ++i)
		{
			double sigma = 0;
			for(int j=0; j<M; ++j)
			{
				if(j!=i) sigma += A[i][j]*x[j][0];
			}
			x[i][0] = (1.0/A[i][i])*(b[i][0]-sigma);
		}
	}while(!allClose(x,xtemp) && iter < MAX_ITER);
	return x;
}

template <typename T, std::size_t M, std::size_t N>
Matrix<double,M,1> parallelGaussSeidel(Matrix<T,M,N> A, Matrix<T,M,1> b)
{
	const int MAX_ITER = 1000;
	int iter = 0;
	Matrix<double,M,1> x = genRandoms<double,M,1>();
	Matrix<double,M,1> xtemp;
	do{
		++iter;
		xtemp = x;
#pragma omp parallel for
		for(int i=0; i<M; ++i)
		{
			double sigma = 0;
			for(int j=0; j<M; ++j)
			{
				if(j!=i) sigma += A[i][j]*x[j][0];
			}
			x[i][0] = (1.0/A[i][i])*(b[i][0]-sigma);
		}
	}while(!allClose(x,xtemp) && iter < MAX_ITER);
	return x;
}
