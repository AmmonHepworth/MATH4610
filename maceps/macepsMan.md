---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH5620/index">HOME</a>

{% include mathjax.html %}

# Machine Epsilon

**Routine Name:** getMacEps

**Author:** Ammon Hepworth

**Language:** C++


## Description

This routine finds the machine epsilon of a data type. The machine epsilon is essentially the smallest representable number by a data type.

## Input

No arguments are taken as parameters, simply give the type to be examined as a template argument.

## Output

A number that is the machine epsilon of the chosen type.

## Code

{% highlight c++ %}
template <typename T>
T getMacEps()
{
	T value = 1;
	T litOne = 1.0;
	T litHalf = 0.5;
	int precCount = 0;
	while(litOne + litHalf*value != 1)
	{
		++precCount;
		value *= litHalf;
	}
	return value;
}
{% endhighlight %}

## Example

{% highlight c++ %}
#include "maceps.h"
#include <iostream>

int main()
{
	std::cout << getMacEps<double>() << std::endl;
	std::cout << getMacEps<float>() << std::endl;
}
{% endhighlight %}

## Result
```
2.22045e-16
1.19209e-07
```
Last Modified: Jan 2018
