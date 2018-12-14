#ifndef CONJUGATE_GRADIENT_HPP
#define CONJUGATE_GRADIENT_HPP
#include "../../hw3/matrixlib/matrix.h"

template <typename T, std::size_t M, std::size_t N>
Matrix<double,M,1> conjugateGradient(Matrix<T,M,N> A, Matrix<T,M,1> b)
{
	int k=0;
	Matrix<double,M,1> x = genZeros<double,M,1>();
	Matrix<double,M,1> r = b;
	Matrix<double,M,1> p;
	Matrix<double,M,1> rk1 = r;
	Matrix<double,M,1> rk2 = r;
	double alpha;
	double bet;
	Matrix<double,M,1> s;
	
	while( k < 10 )
	{
		++k;
		if(k==1) p = r;
		else
		{
			bet = (dot(rk1,rk1))/dot(rk2,rk2);
			p = rk1 + bet*p;
		}
		s = A*p;
		alpha = dot(rk1,rk1)/dot(p,s);
		x = x + (alpha*p);
		r = rk1 - (alpha*s);
		rk2 = rk1;
		rk1 = r;
	}
	return x;
}

#endif
