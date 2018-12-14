#ifndef LU_SOLVE_H
#define LU_SOLVE_H

#include "../../hw3/matrixlib/matrix.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <tuple>

template <typename T, std::size_t M, std::size_t N >
std::tuple<Matrix<double,M,N>, Matrix<double,M,N>, Matrix<int,M,N>> luFactorize(Matrix<T,M,N> mat)
{
	auto permutation = genIdentity<int,M,N>();
	auto slamMatrix = genIdentity<double,M,N>();
	auto lower = genZeros<double,M,N>();
	auto upper = genIdentity<double,M,N>() * mat;
	auto I = genIdentity<double,M,N>();

	for(int iter=0; iter<M-1; ++iter)
	{
		T high = 0;
		int index = iter;
		for(int i=iter; i<M; i++)
		{
			if(std::abs(upper[i][iter]) > high)
			{
				index = i;
				high = upper[i][0];
			}
		}
		std::swap(upper[iter],upper[index]);
		std::swap(permutation[iter],permutation[index]);
		std::swap(lower[iter],lower[index]);

		slamMatrix = genIdentity<double,M,N>();
		for(int j=iter+1; j<M; ++j)
		{
			slamMatrix[j][iter] = -upper[j][iter] / (double)upper[iter][iter];
		}
		lower = lower - (slamMatrix-I);
		upper = slamMatrix * upper;

	}
	lower = lower + I;


	return std::tuple<Matrix<double,M,N>, Matrix<double,M,N>, Matrix<int,M,N>>(lower,upper,permutation);
}


template <typename T, std::size_t M, std::size_t N>
Matrix<T,M,1> LUSolveSystem(Matrix<T,M,N> A, Matrix<T,M,1> b)
{
	//std::tuple<Matrix<double,M,N>, Matrix<double,M,N>, Matrix<double,M,N>> LUPieces = luFactorize(A);
	auto LUPieces = luFactorize(A);
  auto L = std::get<0>(LUPieces);
  auto U = std::get<1>(LUPieces);
  auto P = std::get<2>(LUPieces);
  Matrix<double,M,1> PB= P*b;
  Matrix<double,M,1> y = forwardSubstitute(L,PB);
  Matrix<double,M,1> x = backSubstitute(U,y);

  return x;
}
#endif
