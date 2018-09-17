---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Bisection Method - Root Finding

**Routine Name:** rootFindBisection

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This method find a root of a given function between two given points. It performs this by essentially doing a binary search on the function until it closes in upon a root. You must be sure to give a begin and end point that have opposite signs, to ensure that the x axis is crossed between them.

## Input

The user is required to enter a beginning and end x value that must have opposing signs, a tolerance for the root, the maximum number of iterations that should be used, and a function to be explored as a lambda. The types of the begin, end, and tolerance are determined with a template type, whilst maxiter is an integer.

## Output

The program will output the x value for which the given function has a root. Alternatively, if a root cannot be determined or the input was bad it will print a message saying so and return a bad value.

## Example

{% highlight c++ %}
#include <iostream>
#include "bisection.cpp"

int main()
{
  std::cout << "x^2-3 between 0 and 10" << std::endl
            << "-----" << std::endl
            << rootFindBisection<double>(0, 10, 1e-10, 100, 
                                        [](double x){return x*x-3;})
            << std::endl << std::endl;

  std::cout << "sin(pi*x) between .5 and 2" << std::endl
            << "---------" << std::endl
            << rootFindBisection<double>(0.5, 2, 1e-10, 1000, 
                                        [](double x){return std::sin(3.141592653*x);})
            << std::endl;
}
{% endhighlight %}

## Result
```
x^2-3 between 0 and 10
-----
1.73205

sin(pi*x) between .5 and 2
---------
1
```

## Code

{% highlight c++ %}
#include <cmath>
#include <iostream>

template <typename T, typename F>
T rootFindBisection(T a, T b, T tol, int maxiter, F f)
{
  if(f(a) * f(b) > 0) 
  {
    std::cout << "ERROR: root not found, sign of a and b are the same" << std::endl;
    return 0;
  }

  T c = (a+b)/2;

  while(std::abs(f(c)) > tol && maxiter > 0 && f(c) != 0)
  {
    --maxiter;
    if(f(c)*f(a) > 0)
      a = c;
    else
      b = c;

    c = (a+b)/2;
  }
  if(maxiter == 0)
    std::cout << "ERROR: root not found, maxiter exceeded" << std::endl;

  return c;
}
{% endhighlight %}

Last Modified: September 2018
