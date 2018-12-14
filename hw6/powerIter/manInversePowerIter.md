---
math: true
layout: default
---

{% include mathjax.html %}
<a href="https://ammonhepworth.github.io/MATH5620/index">HOME</a>

# Inverse Power Iteration

**Routine Name:** inversePowerIteration

**Author:** Ammon Hepworth

**Language:** C++


## Description

The inversePowerIteration method finds the smallest eigenvalue. The method rely on multiplying a random guess by the norm to "pull" the direction of the vector towards the correct heading. The inverse operation also makes use of a linear solver. Because of how the methods are implemented, powerIteration will return a eigen vector and inverse will give the eigenvalue directly. 


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
  std::cout << "Smallest eigenvalue: " << inversePowerIteration(A) << std::endl;
}
{% endhighlight %}

## Result
```
A
| 18.8994 8.01509 -0.927162 5.22117 4.44383 |
| 8.01509 32.8445 -6.17753 -4.76567 9.30863 |
| -0.927162 -6.17753 10.4803 0.667093 -0.234124 |
| 5.22117 -4.76567 0.667093 17.6648 -2.19354 |
| 4.44383 9.30863 -0.234124 -2.19354 19.2736 |

Smallest eigenvalue: 7.9985

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
double inversePowerIteration(Matrix<T,M,N> A)
{
	auto v = genRandoms<double,M,1>();
	Matrix<double,M,1> w;
	double lambda = 0;

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
