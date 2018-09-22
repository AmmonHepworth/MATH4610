---
math: true layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Funcional Iteration - Root Finding

**Routine Name:** rootFindFunctionIteration

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This method works by finding a second function, g(x), such that f(x)=0 only when g(x)=x. If you've chosen a "good" function, then a root should be found. It is possible to have a bad function though, even if it satisfies the conditions. This method can extend to nonlinear and more complicated functions.

## Input

Takes templated values for an initial guess and tolerance, an integer for the max iteration number, and a lambda for the function of which to perform the iteration. Be sure to input a correctly crafted function.

## Output

Outputs the value of a root of the function as a templated type.

## Example

{% highlight c++ %}
#include "functionalIteration.cpp"
#include <iostream>
#include <cmath>

int main()
{

  std::cout << "x^2-3" << std::endl
            << rootFindFunctionIteration<double>(.5, 1e-10, 100,
                                    [](double x){ return x-(x*x -3)/10; })
            << std::endl << std::endl

            << "sin(pi*x)" << std::endl
            << rootFindFunctionIteration<double>(.5, 1e-15, 1000,
                                    [](double x){ return x - std::sin(3.14159265359*x)/2; });


}
{% endhighlight %}

## Result
```
x^2-3
1.73205

sin(pi*x)
0

```

## Code

{% highlight c++ %}
#include <cmath>

template <typename T, typename F>
T rootFindFunctionIteration(T guess, T tol, int maxiter, F f)
{
  T x;
  while(maxiter>0)
  {
    --maxiter;
    x = f(guess);
    if(std::abs(x-guess) < tol) return x;
    guess = x;
  }
  return guess;

}
{% endhighlight %}

Last Modified: September 2018
