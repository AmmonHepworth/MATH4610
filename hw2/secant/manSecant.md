---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Secant Method - Root Finding

**Routine Name:** rootFindSecant

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

The newton method is a simple root finding algorithm that works by following the tangent of an initial guess until it hits the x-axis, and then repeating the process from that point. Formally, this is $$x_{k+1} = x_k - \frac{f(x_k)}{f'(x_k)}$$. This method requires only a single initial guess, but does require that you know the derivative of your function or have a way to approximate it. This method fails if the initial guess or one of the successive iteration lands on a point where the slope is 0 (ie horizontal), and it will have no intersect with the x-axis. Below, we can see an example of this when trying to compute the root of sin(pi*x) with an initial guess of 0.5. The guess is wildly off, to be expected.

## Input

The function takes the initial guess and tolerance with templated types, an integer for maximum iterations, and two lambdas for the function and its derivative

## Output

Outputs a single value of the same type as the template that is the root of the function.

## Example

{% highlight c++ %}
int main()
{
#include <iostream>
#include "secant.cpp"

int main()
{
  std::cout << "x^2-3 guessing 0-8" << std::endl
            << "-----" << std::endl
            << rootFindSecant<double>(0,8, 1e-10, 100, 
                                      [](double x){return x*x-3;})
            << std::endl << std::endl;

  std::cout << "sin(pi*x) guessing .5-1.5" << std::endl
            << "---------" << std::endl
            << rootFindSecant<double>(.1,2, 1e-5, 1000,
                                      [](double x){return std::sin(3.141592653*x);})
            << std::endl << std::endl;
}
{% endhighlight %}

## Result
```
x^2-3 guessing 0-8
-----
1.73205

sin(pi*x) guessing .5-1.5
---------
2
```

## Code

{% highlight c++ %}
#include <cmath>

template <typename T, typename F>
T rootFindSecant(T x1, T x2, T tol, int maxiter, F f)
{
  T xk;
  for(int i=0; i<maxiter && std::abs(f(x1)) > tol ; ++i)
  {
    xk = x1 - f(x1) * (x1-x2)/(f(x1)-f(x2));
    x1=x2;
    x2=xk;
  }
  return xk;
}
{% endhighlight %}

Last Modified: September 2018
