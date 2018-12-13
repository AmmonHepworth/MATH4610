---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# LU Factorization - Multiplication Factor Computations

**Routine Name:** luFactorize

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This routine will calculate the upper and lower triangular matrices and the permutation matrix required for solving a linear system using LU factorization. We can break up our matrix to have the relation LU=PA. LU solving is a fast way to solve a linear system, and fairly simple as well.

## Input

This method will just take in the matrix A, a square matrix of any type.

## Output

The result is a std::tuple containing three matrices. The first matrix is the lower trianglular matrix with equal dimension and type to A. Likewise, the second matrix is the upper triangular matrix with the same properties. The third matrix is the permutation matrix, which has the same dimensions as the others but is a matrix of integers.

## Example

{% highlight c++ %}
int main()
{

  Matrix<double,4,4> A = {{ {1, 3, 5, 9},
                            {1, 3, 1, 7},
                            {4, 3, 9, 7},
                            {5, 2, 0, 9} }}; 

  Matrix<double,4,1> b = {{ {1},
                            {2},
                            {8},
                            {3} }}; 

	std::tuple<Matrix<double,4,4>, Matrix<double,4,4>, Matrix<int,4,4>> LUPieces = luFactorize(A);
  auto L = std::get<0>(LUPieces);
  auto U = std::get<1>(LUPieces);
  auto P = std::get<2>(LUPieces);
  std::cout << "L" << std::endl << L << std::endl;
  std::cout << "U" << std::endl << U << std::endl;
  std::cout << "P" << std::endl << P << std::endl;
}
{% endhighlight %}

## Result
```
L
| 1 0 0 0 |
| 0.2 1 0 0 |
| 0.2 1 1 0 |
| 0.8 0.538462 -1.57692 1 |

U
| 5 2 0 9 |
| 0 2.6 5 7.2 |
| 0 0 -4 -2 |
| 0 0 0 -7.23077 |

P
| 0 0 0 1 |
| 1 0 0 0 |
| 0 1 0 0 |
| 0 0 1 0 |
```

## Code

{% highlight c++ %}
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
{% endhighlight %}

Last Modified: November 2018
