---
math: true
layout: default
---

{% include mathjax.html %}
<a href="https://ammonhepworth.github.io/MATH5620/index">HOME</a>

# Conjugate Gradient

**Routine Name:** conjugateGradient

**Author:** Ammon Hepworth

**Language:** C++


## Description

This is the PARALLEL version of conjugate gradient. Parallelization was attempted using OMP. It seems the way I wrote conjugate gradient makes it impossible to parallelize, as each iteration relies on previous iterations. This is why the output is incorrect. I am not sure of another way to write it such that it becomes parallelizable.

Conjugate Gradient is an iterative method that follows the slope of a function to solve a differential equation. It attempts to minimize itself until the difference between steps is low enough. Provided is an implementation of such a method.  When compared to both jacobi and gauss seidel, it was generally better than jacobi as size increased, but gauss seidel occasionally beat it, sometimes by quite a margin. I assume that this is because of the topology of the problems it was given. If the conjugate gradient method is given a slope that is very shallow, it might take a very long time to converge. It also might run into the problem of finding a false minimum.

## Input

This method takes two arguments. The first is the A matrix, followed by the solution matrix b. Both matrices will have their types and sizes inferred and are not manually entered.

## Output

The only output is the x vector that solves the equation Ax=b. It will be a Mx1 matrix of doubles.


## Example

{% highlight c++ %}
int main()
{
  Matrix<double,4,4> mat = genSymmetricDiagDominant<double,4>(-10,10);
  Matrix<double,4,1> sol = genRightHand(mat);

  std::cout << "A" << std::endl << mat << std::endl;
  std::cout << "b" << std::endl << sol << std::endl;

  std::cout << "Serial x" << std::endl << conjugateGradient(mat,sol) << std::endl;
  std::cout << "Parallel x" << std::endl << parallelConjugateGradient(mat,sol) << std::endl;
}
{% endhighlight %}

## Result
```
A
| 14.1243 -5.88175 -4.73444 2.83789 |
| -5.88175 16.6888 9.82196 -0.117759 |
| -4.73444 9.82196 22.4189 -7.20726 |
| 2.83789 -0.117759 -7.20726 10.8765 |

b
| 6.34604 |
| 20.5112 |
| 20.2991 |
| 6.38935 |

Serial x
| 1 |
| 1 |
| 1 |
| 1 |

Parallel x
| 11.256 |
| -7.07319 |
| -10.8384 |
| 8.90237 |
```

## Code

{% highlight c++ %}
template <typename T, std::size_t M, std::size_t N>
Matrix<double,M,1> parallelConjugateGradient(Matrix<T,M,N> A, Matrix<T,M,1> b)
{
	Matrix<double,M,1> x = genZeros<double,M,1>();
	Matrix<double,M,1> r = b;
	Matrix<double,M,1> p;
	Matrix<double,M,1> rk1 = r;
	Matrix<double,M,1> rk2 = r;
	double alpha;
	double bet;
	Matrix<double,M,1> s;
	
#pragma omp parallel for
	for(int k=0; k<10;++k)
	{
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
{% endhighlight %}

Last Modified: November 2018
