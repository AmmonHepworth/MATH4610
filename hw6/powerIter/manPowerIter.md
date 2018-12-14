---
math: true
layout: default
---

{% include mathjax.html %}
<a href="https://ammonhepworth.github.io/MATH5620/index">HOME</a>

# Power Iteration

**Routine Name:** powerIteration

**Author:** Ammon Hepworth

**Language:** C++


## Description

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
  std::cout << "Largest eigenvalue: " << powerIteration(A) << std::endl;
}
{% endhighlight %}

## Result
```
A
| 15.7168 1.5575 3.93572 4.24465 -4.93808 |
| 1.5575 13.6162 -2.13587 6.52308 -3.01576 |
| 3.93572 -2.13587 21.478 -7.85562 2.91364 |
| 4.24465 6.52308 -7.85562 32.1477 9.46739 |
| -4.93808 -3.01576 2.91364 9.46739 24.9254 |

Largest eigenvalue: 40.9479
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
