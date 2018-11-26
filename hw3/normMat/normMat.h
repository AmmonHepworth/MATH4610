#include "../matrixlib/matrix.h"
#include <vector>
#include <algorithm>
#include <cmath>

template <typename T, size_t M, size_t N>
double oneNormMat(Matrix<T,M,N> mat)
{
	std::vector<double> sums(N,0);

	for(int j=0; j< M; ++j)
	{
		for(int i=0; i< N; ++i)
		{
			sums[i] += mat[j][i];
		}
	}
	return *std::max_element(sums.begin(),sums.end());
}


template <typename T, size_t M, size_t N>
double infNormMat(Matrix<T,M,N> mat) 
{
	std::vector<double> sums(M,0);
	for(int i=0; i<M; ++i)
	{
		sums[i] = std::accumulate(mat[i].begin(),mat[i].end(),0);
	}

	return *std::max_element(sums.begin(),sums.end());
}


