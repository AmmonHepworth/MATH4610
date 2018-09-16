---
math: true
layout: default
---

{% include mathjax.html %}
<a href="https://ammonhepworth.github.io/MATH5620/index">HOME</a>

# Absolute and Relative Error

**Routine Name:** absoluteError AND relativeError

**Author:** Ammon Hepworth

**Language:** C++


## Description

These functions find the absolute and relative error of a number when the exact solution is already known as well as your approximation. Absolute error is the raw difference between the two, and relative is weighted in relation to the proximity of the two numbers.

## Input

The first argument is the exact solution. The second is the approximated solution.

## Output

A number of the type of the arguments that is the absolute or relative error.

## Example

{% highlight c++ %}
#include "error.h"
#include <iostream>

int main()
{
	std::cout << "Absolute error between 101.1 approx and 100 exact: " << absoluteError<double>(100,101.1) << std::endl;
	std::cout << "Relative error between 101.1 approx and 100 exact: " << relativeError<double>(100,101.1) << std::endl;
}
{% endhighlight %}

## Result
```
Absolute error between 101.1 approx and 100 exact: 1.1
Relative error between 101.1 approx and 100 exact: 0.011
```
## Code

{% highlight c++ %}
#include<cmath>

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
{% endhighlight %}

Last Modified: Sept 2018
