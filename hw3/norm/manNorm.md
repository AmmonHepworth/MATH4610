---
math: true
layout: default
---

{% include mathjax.html %}
<a href="https://ammonhepworth.github.io/MATH5620/index">HOME</a>

# Vector Norms

**Routine Name:** pNorm

**Author:** Ammon Hepworth

**Language:** C++


## Description

This algorithm is a general purpose vector norm solver. It will find any arbitrary vector p-norm, including infinity. To get the infinity norm, pass the numeric limit of the integer and it will return the appropriate value. The 1-norm will give a summation of the vector, the 2-norm will be the square root of the sum of the squares, and the infinity-norm will give the max element, for example. This code will produce a norm of ANY NUMBER. Note that the norm where p=2 is also called the Frobenius norm.

## Input

An Mx1 Matrix type of templated type as the first parameter. For the second parameter, you enter the arbitrary p value for your desired norm.

## Output

Will output a double that is the p-norm of the vector for the given p value. Will also provide the infinity norm if given the numeric limit for integer type.

## Example

{% highlight c++ %}
#include "norm.h"
#include "../matrixlib/matrix.h"
#include <iostream>

int main() {

	Matrix<double,3,1> rekt = { { {1} , {2}, {3} } };

	std::cout << "L1: " << pNorm(rekt,1) << std::endl;
	std::cout << "L2: " << pNorm(rekt,2) << std::endl;
	std::cout << "L3: " << pNorm(rekt,std::numeric_limits<int>::max()) << std::endl;

}
{% endhighlight %}

## Result
```
L1: 6
L2: 3.74166
L3: 3
```

## Code

{% highlight c++ %}
#ifndef NORM_H
#define NORM_H
#include "../matrixlib/matrix.h"
#include <limits>
#include <cmath>

template <typename T, std::size_t M>
double pNorm(Matrix<T,M,1> vect, int p)
{
  if(p == std::numeric_limits<int>::max())
  {
    T myMax = vect[0][0];
    for(int i=0; i<M; ++i)
    {
      if(vect[i][0] > myMax)
        myMax = vect[i][0];
    }
    return myMax;
  }

  double pSum = 0;
  for(int i=0; i<M; ++i)
    pSum += std::pow(std::abs(vect[i][0]),p);

  return std::pow(pSum, 1.0/p);
}
#endif
{% endhighlight %}


Last Modified: Nov 2018
