---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Vector Error

**Routine Names:** vAbsoluteError, vRelativeError

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

These routines will give you the absolute or the relative error between two vectors. Conveniently, this routine reuses both the p-norm and error functions written for previous assignments.

## Input

Both functions will take two vectors, one being your solution and the other being an approximation. You then give it the norm that you desire in the form of the integer for the p-norm. For example, give it a 1 for the l1 norm, 2 for l2 norm, etc. For the infinity norm, pass it the standard numeric limit integer maximum.

## Output

This will output a double that is either the absolute or relative error between your vectors.

## Example

{% highlight c++ %}
int main()
{
  
  Matrix<double,4,1> v1 = { { {-2},
                               {1},
                               {0},
                               {0} } };

  Matrix<double,4,1> v2 = { { {-1},
                               {1},
                               {0},
                               {0} } };

  std::cout << "relative: " << vRelativeError(v1,v2,1) << std::endl;
  std::cout << "absolute: " << vAbsoluteError(v1,v2,1) << std::endl;
}
{% endhighlight %}

## Result
```
relative: 0.333333
absolute: 1
```

## Code

{% highlight c++ %}
#include "../norm/norm.h"
#include <cmath>

template <typename T>
T absoluteError(T exact, T approx)
{
	return std::abs(exact-approx);
}

template <typename T>
T relativeError(T exact, T approx)
{
	return absoluteError<T>(exact,approx) / exact;
}


template <typename T, std::size_t M>
T vRelativeError(Matrix<T,M,1> v1, Matrix<T,M,1> v2, int p)
{
  return relativeError(pNorm(v1,p),pNorm(v2,p));
}

template <typename T, std::size_t M>
T vAbsoluteError(Matrix<T,M,1> v1, Matrix<T,M,1> v2, int p)
{
  return absoluteError(pNorm(v1,p),pNorm(v2,p));
}
{% endhighlight %}

Last Modified: September 2018
