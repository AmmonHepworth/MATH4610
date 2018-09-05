---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Quadratic Equation

**Routine Name:** quadratic

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

Calculates the roots of a polynomial of order two using the quadratic equation. https://en.wikipedia.org/wiki/Quadratic_equation for more information.

## Input

Takes the parameters a, b, and c as input along with their types as template parameters in their respective orders.

## Output

A pair of complex values containing both roots. If the roots do not have an imaginary component, it is left up to the user to extract just the real portion.

## Example

{% highlight c++ %}
int main() 
{
  std::cout << quadratic(1,-1,-6).first << std::endl;
  std::cout << quadratic(1,-1,-6).second << std::endl;
}
{% endhighlight %}

## Result
```
(3,0)
(-2,0)
```

## Code

{% highlight c++ %}
#include <complex>
#include <utility>
template <typename A, typename B, typename C>
std::pair<std::complex<double>,std::complex<double> > quadratic(A a, B b, C c)
{
  std::pair<std::complex<double>,std::complex<double> > ret;
  ret.first = (-b + std::sqrt(b*b-4*a*c))/(2*a);
  ret.second = (-b - std::sqrt(b*b-4*a*c))/(2*a);
  return ret;
}
{% endhighlight %}

Last Modified: September 2018
