---
math: true
layout: default
---

{% include mathjax.html %}
<a href="https://ammonhepworth.github.io/MATH5620/index">HOME</a>

# Parallel Inverse Power Iteration

**Routine Name:** parallelInversePowerIteration

**Author:** Ammon Hepworth

**Language:** C++


## Description

This is the parallel version of inverse power iteration using openMP. The main for loop was parallelized using an openMP directive, which made it nice and easy.


The inversePowerIteration method finds the smallest eigenvalue. The method rely on multiplying a random guess by the norm to "pull" the direction of the vector towards the correct heading. The inverse operation also makes use of a linear solver. 


## Input

It takes as input a templatized, square Matrix of any size. The user will not have to specify type or size of the Matrix as they will be inferred by the template engine for use in the function.

## Output

The method will return a single double that is the smallest eigenvalue.


## Example

{% highlight c++ %}
int main()
{

  auto A = genSymmetricDiagDominant<double,5>(-10,10);


  std::cout <<"A" << std::endl<< A << std::endl;
  std::cout << "Parallel Smallest eigenvalue: " << parallelInversePowerIteration(A) << std::endl;
}
{% endhighlight %}

## Result
```
A
| 8.55291 5.83434 0.442503 1.58598 0.633082 |
| 5.83434 24.1731 7.09105 7.68266 2.46798 |
| 0.442503 7.09105 17.7169 5.06349 2.61964 |
| 1.58598 7.68266 5.06349 18.4024 1.95347 |
| 0.633082 2.46798 2.61964 1.95347 8.25983 |

Parallel Smallest eigenvalue: 6.2043
```
## Code

{% highlight c++ %}
#include "../matrixlib/matrix.h"
#include "../norm/norm.h"
#include "../normMat/normMat.h" 
#include "../lufactorization/lufact.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

template <typename T, size_t M, size_t N>
double parallelInversePowerIteration(Matrix<T,M,N> A)
{
	auto v = genRandoms<double,M,1>();
	Matrix<double,M,1> w;
	double lambda = 0;

#pragma omp parallel for
	for(int i=0;i<100;++i)
	{
	  w = luFactorize(A,v);
		double myNorm = pNorm(w,2);
		v = w * (1.0/myNorm);
		lambda = pNorm(A*v,2);
	}
	return lambda;
}
{% endhighlight %}

Last Modified: December 2018
