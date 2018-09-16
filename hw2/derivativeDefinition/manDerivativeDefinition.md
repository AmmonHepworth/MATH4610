---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Definition of Derivative

**Routine Name:** deriveDef

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

Computes the derivative using the definition. The definition is \{ $$lim_{h\rightarrow0} {f(x+h)-f(x)}{h}$$ \}

## Input

Takes x, h, and the function desired as a lambda. Inputs x and h are typed by a template.

## Output

Outputs the approximate derivative of the function at the point x and desired h.

## Example

{% highlight c++ %}
#include <iostream>
#include "derivativeDefinition.cpp"

int main()
{
  for(double i=1;i>1e-10;i/=2)
  {
    std::cout << std::showpoint << std::fixed << deriveDef<double>(5,i,[](double x){ return x*x; }) << std::endl;
  }
}
{% endhighlight %}

## Result
```
11.000000
10.500000
10.250000
10.125000
10.062500
10.031250
10.015625
10.007812
10.003906
10.001953
10.000977
10.000488
10.000244
10.000122
10.000061
10.000031
10.000015
10.000008
10.000004
10.000002
10.000001
10.000000
10.000000
10.000000
10.000000
10.000000
10.000000
10.000000
10.000000
10.000000
10.000000
10.000000
10.000000
10.000000
```

## Code

{% highlight c++ %}
#include <functional>

template <typename T, typename F>
T deriveDef(T x, T h, F f)
{
  return (f(x+h) - f(x))/h;
}
{% endhighlight %}

Last Modified: September 2018
