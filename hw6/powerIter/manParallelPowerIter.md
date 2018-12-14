---
math: true
layout: default
---

{% include mathjax.html %}
<a href="https://ammonhepworth.github.io/MATH5620/index">HOME</a>

# Parallel Power Iteration

**Routine Name:** parallelPowerIteration

**Author:** Ammon Hepworth

**Language:** C++


## Description

This version of the power method is parallel. The openMP directive is used to easily parallelize the main for loop.

The powerIteration method finds the largest eigenvalue of a given diagonalizable matrix using an iterative appraoch. The method relies on multiplying a random guess by the norm to "pull" the direction of the vector towards the correct heading. The algorithm is simple, but may converge slowly.


## Input

Input is a square, diagonalizable matrix of any size and type

## Output

The largest eigenvalue is returned as a double.

## Example

{% highlight c++ %}

int main()
{

  auto A = genSymmetricDiagDominant<double,5>(-10,10);


  std::cout <<"A" << std::endl<< A << std::endl;
  std::cout << "Parallel Largest eigenvalue: " << parallelPowerIteration(A) << std::endl;
}
{% endhighlight %}

## Result
```
A
| 30.8837 -9.70537 3.18498 -5.18757 -9.47436 |
| -9.70537 28.5849 6.96622 -9.48843 1.07869 |
| 3.18498 6.96622 19.7614 -8.81335 0.518061 |
| -5.18757 -9.48843 -8.81335 33.6902 -5.94129 |
| -9.47436 1.07869 0.518061 -5.94129 17.918 |

Parallel Largest eigenvalue: 47.1397
```

## Code

{% highlight c++ %}
#include "../../hw3/matrixlib/matrix.h"
#include "../../hw3/norm/norm.h"
#include "../../hw3/normMat/normMat.h" 
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
{% endhighlight %}

Last Modified: December 2018
