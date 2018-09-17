---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Newtons Method - Root Finding

**Routine Name:** rootFindNewton

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
  std::cout << "x^2-3 guessing 8" << std::endl
            << "-----" << std::endl
            << rootFindNewton<double>(8, 1e-10, 100, 
                                      [](double x){return x*x-3;},
                                      [](double x){return 2*x;})
            << std::endl << std::endl;

  std::cout << "sin(pi*x) guessing .5" << std::endl
            << "---------" << std::endl
            << rootFindNewton<double>(.5, 1e-5, 1000,
                                      [](double x){return std::sin(3.141592653*x);},
                                      [](double x){return 3.141592653*std::cos(3.141592653*x);})
            << std::endl << std::endl;

  std::cout << "sin(pi*x) guessing 2.25" << std::endl
            << "---------" << std::endl
            << rootFindNewton<double>(2.25, 1e-5, 1000,
                                      [](double x){return std::sin(3.141592653*x);},
                                      [](double x){return 3.141592653*std::cos(3.141592653*x);})
            << std::endl;
}
{% endhighlight %}

## Result
```
x^2-3 guessing 8
-----
1.73205

sin(pi*x) guessing .5
---------
-1.07939e+09

sin(pi*x) guessing 2.25
---------
2
```

## Code

{% highlight c++ %}
#include <cmath>

template <typename T, typename F, typename F1>
T rootFindNewton(T guess, T tol, int maxiter, F f, F1 fp1)
{
  for(int i=0; i<maxiter && std::abs(f(guess)) > tol ; ++i)
  {
    guess = guess - (f(guess)/fp1(guess));
  }
  return guess;
}
{% endhighlight %}

Last Modified: September 2018
