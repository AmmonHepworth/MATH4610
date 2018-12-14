#include "../../hw3/matrixlib/matrix.h"
#include "../../hw3/norm/norm.h"
#include "../../hw3/normMat/normMat.h" 
#include "../../hw4/LUSolve/LUPieces.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

template <typename T, size_t M, size_t N>
double powerIteration(Matrix<T,M,N> A)
{
	auto v = genRandoms<double,M,1>();
	Matrix<double,M,1> w;
	double lambda = 0;

	for(int i=0;i<100;++i)
	{
	  w = A*v;
		double myNorm = pNorm(w,2);
		v = w * (1.0/myNorm);
		lambda = pNorm(A*v,2);
	}
	return lambda;
}

template <typename T, size_t M, size_t N>
double inversePowerIteration(Matrix<T,M,N> A)
{
	auto v = genRandoms<double,M,1>();
	Matrix<double,M,1> w;
	double lambda = 0;

	for(int i=0;i<100;++i)
	{
	  w = LUSolveSystem(A,v);
		double myNorm = pNorm(w,2);
		v = w * (1.0/myNorm);
		lambda = pNorm(A*v,2);
	}
	return lambda;
}

template <typename T, size_t M, size_t N>
double parallelPowerIteration(Matrix<T,M,N> A)
{
	auto v = genRandoms<double,M,1>();
	Matrix<double,M,1> w;
	double lambda = 0;

#pragma omp parallel for
	for(int i=0;i<100;++i)
	{
	  w = A*v;
		double myNorm = pNorm(w,2);
		v = w * (1.0/myNorm);
		lambda = pNorm(A*v,2);
	}
	return lambda;
}

template <typename T, size_t M, size_t N>
double parallelInversePowerIteration(Matrix<T,M,N> A)
{
	auto v = genRandoms<double,M,1>();
	Matrix<double,M,1> w;
	double lambda = 0;

#pragma omp parallel for
	for(int i=0;i<100;++i)
	{
	  w = LUSolveSystem(A,v);
		double myNorm = pNorm(w,2);
		v = w * (1.0/myNorm);
		lambda = pNorm(A*v,2);
	}
	return lambda;
}

template <typename T, size_t M, size_t N>
double condition2(Matrix<T,M,N> A)
{
  auto max = powerIteration(A);
  auto min = inversePowerIteration(A);
  return std::abs(max/min);
}

template <typename T, size_t M, size_t N>
double parallelCondition2(Matrix<T,M,N> A)
{
  auto max = parallelPowerIteration(A);
  auto min = parallelInversePowerIteration(A);
  return std::abs(max/min);
}

template <typename T, size_t M, size_t N>
double inversePowerIteration1(Matrix<T,M,N> A)
{
	Matrix<double,M,1> v;
	for(auto &&e:v)
	{
		e[0]=rand() %10;
	}

	double lambda;
	for(int i=0; i<100; ++i)
	{
		Matrix<double,M,1> w = LUSolveSystem(A,v);
		double myNorm = pNorm(w,2);
		for(int j=0;j<M;++j)
		{
			v[j][0] = w[j][0]/ myNorm;
		}
		Matrix<double,M,1> Av = A*v;
		lambda = dot(v,Av);
	}
	return lambda;
}
