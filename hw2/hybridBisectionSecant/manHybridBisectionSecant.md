---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Hybrid Bisection-Secant - Root Finding

**Routine Name:** rootFindHybridBisectionSecant

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This method finds the roots of a function, if possible. This particular method uses the bisection method and the secant method. When the secant guess is within the bracketed bounds, then the secant method is used again until it either converges on the root or goes outside the bounds. In that case, the bisection method is used to reduce the size of the brackets by ~10x before running the secant method again. This gives us faster convergence through the secant method while having some of the stability/consistency of the bisection method.

## Input

Takes the beginning and end of the interval in which to search for the roots, the tolerance you desire, the max number of iterations to run, the function that you want the roots of.

## Output

Outputs a root of the function as a templated type.

## Example

{% highlight c++ %}
int main()
{
  std::cout << "x^2-3: " 
    << rootFindHybridBisectionSecant<double>(0,3,1e-10,1000,
                                             [](double x){ return x*x - 3; }) << std::endl << std::endl;

  std::cout << "sin(pi*x): "
    << rootFindHybridBisectionSecant<double>(0.1,2,1e-10,1000,
                                             [](double x){ return std::sin(3.14159*x); }) << std::endl;
}
{% endhighlight %}

## Result
```
x^2-3: 1.73205

sin(pi*x): 1
```

## Code

{% highlight c++ %}
#include <random>
#include <cmath>
#include <iostream>

template <typename T, typename F>
T bisectionStep(T& a, T& b, T tol, F f)
{
  if(f(a) * f(b) > 0) 
  {
    std::cout << "ERROR: root not found, sign of a and b are the same" << std::endl;
    return 0;
  }

  T c = (a+b)/2;

  for(int i=0; i<4; ++i)
  {
    if(f(c)*f(a) > 0)
      a = c;
    else
      b = c;

    c = (a+b)/2;
  }

  return c;
}

template <typename T, typename F>
T rootFindHybridBisectionSecant(T a, T b, T tol, int maxiter, F f)
{
  T c =(a+b)/2;
  T x1 = (a+b)/2;
  static std::random_device rd;
  static std::mt19937 mt(rd());
  std::uniform_real_distribution<> dist(a,b);
  T x2 = dist(mt);
  T xk;

  while(std::abs(f(c)) > tol && maxiter > 0 && f(c) != 0)
  {
    if(c>a && c<b)
    {
      xk = x1 - f(x1) * (x1-x2)/(f(x1)-f(x2));
      x1=x2;
      x2=xk;
      c = xk;
    }
    else
    {
      c = bisectionStep<T>(a, b, tol, f);
    }
  }
  return c;

}
{% endhighlight %}

Last Modified: September 2018
