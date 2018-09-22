---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Hybrid Bisection-Newton - Root Finding

**Routine Name:** rootFindHybridBisectionNewton

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This method finds the roots of a function, if possible. This particular method uses the bisection method and the newton method. When the newton guess is within the bracketed bounds, then the newton method is used again until it either converges on the root or goes outside the bounds. In that case, the bisection method is used to reduce the size of the brackets by ~10x before running the newton method again. This gives us faster convergence through the newton method while having some of the stability/consistency of the bisection method.

## Input

Takes the beginning and end of the interval in which to search for the roots, the tolerance you desire, the max number of iterations to run, the function that you want the roots of, and the derivative of that function for the newton method.

## Output

Outputs a root of the function as a templated type.

## Example

{% highlight c++ %}
int main()
{
  std::cout << "x^2-3: " 
    << rootFindHybridBisectionNewton<double>(0,3,1e-10,1000,
                                             [](double x){ return x*x - 3; },
                                             [](double x){ return 2*x; }) << std::endl << std::endl;

  std::cout << "sin(pi*x): "
    << rootFindHybridBisectionNewton<double>(0.1,2,1e-10,1000,
                                             [](double x){ return std::sin(3.14159*x); },
                                             [](double x){ return std::cos(3.14159*x); }) << std::endl;
}
{% endhighlight %}

## Result
```
x^2-3: 1.73205

sin(pi*x): 1
```

## Code

{% highlight c++ %}
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

template <typename T, typename F, typename F1>
T newtonStep(T guess, T tol, F f, F1 fp1)
{
  return guess - (f(guess)/fp1(guess));
}

template <typename T, typename F, typename FP>
T rootFindHybridBisectionNewton(T a, T b, T tol, int maxiter, F f, FP fp)
{
  T c =(a+b)/2;
  while(std::abs(f(c)) > tol && maxiter > 0 && f(c) != 0)
  {
    if(c>a && c<b)
    {
      std::cout << "newton" << std::endl;
      c = newtonStep<T>(c, tol, f, fp);
    }
    else
    {
      std::cout << "bisection" << std::endl;
      c = bisectionStep<T>(a, b, tol, f);
    }
  }
  return c;

}
{% endhighlight %}

Last Modified: September 2018
