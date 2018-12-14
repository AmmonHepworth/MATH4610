---
math: true
layout: default
---

{% include mathjax.html %}
<a href="https://ammonhepworth.github.io/MATH5620/index">HOME</a>

# Gauss Seidel

**Routine Name:** gaussSeidel

**Author:** Ammon Hepworth

**Language:** C++


## Description

This is the PARALLEL version of the Gauss Seidel Method. As we can see in the example, this version performs the same calculation and gets the same answer as our regular method. Luckily, OMP makes parallelization easy for us. The Gauss Seidel Method is an iterative approach to solve a linear system of equations.  When compared to the jacobi method, the jacobi method got worse and worse as the size of the matrix increased. Gauss-Seidel on the other hand still grows but not nearly as fast as jacobi when matrix size increases.

## Input

Takes two matrices as input. The first matrix is an MxN matrix A, while the second is the Mx1 solution matrix b. Their type and size will be inferred by the templating engine.

## Output

Outputs a single Mx1 matrix that contains the values needed to satisfy Ax=b.

## Example

{% highlight c++ %}
int main()
{
  Matrix<double,4,4> mat = genSymmetricDiagDominant<double,4>(-10,10);
  Matrix<double,4,1> sol = genRightHand(mat);

  std::cout << "A" << std::endl << mat << std::endl;
  std::cout << "b" << std::endl << sol << std::endl;

  std::cout << "Serial x" << std::endl << gaussSeidel(mat,sol) << std::endl;
  std::cout << "Parallel x" << std::endl << parallelGaussSeidel(mat,sol) << std::endl;
}
{% endhighlight %}

## Result
```
A
| 24.696 9.23567 -9.56617 -3.09745 |
| 9.23567 23.7168 -6.468 4.86554 |
| -9.56617 -6.468 25.7668 -8.48323 |
| -3.09745 4.86554 -8.48323 16.9285 |

b
| 21.268 |
| 31.35 |
| 1.24935 |
| 10.2134 |

Serial x
| 1 |
| 1 |
| 1 |
| 1 |

Parallel x
| 1 |
| 1 |
| 1 |
| 1 |
```
## Code

{% highlight c++ %}
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
{% endhighlight %}

Last Modified: November 2018
