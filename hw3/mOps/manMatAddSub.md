---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

#  Matrix Operations - Addition and Subtraction

**Routine Name:** operator+,operator-

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

These two routines perform simple addition and subtraction between two matrices

## Input

Since these are implemented as c++ operators, the input will be the binary operands on either side. The matrices must be of equal dimension, and of types that are operatable on each other.

## Output

The output will be a matrix of equal dimensions and type with the result of the addition/subtraction. If the types are the same, the resulting type will be deduced. Therefore, operations between number systems resulting in any other number system are supported.

## Example

{% highlight c++ %}
int main() 
{
  Matrix<double,2,2> a = {{ {1, 2},
                            {3, 4} }};
  Matrix<double,2,2> b = {{ {9, 8},
                            {7, 6} }};

  std::cout << a+b << std::endl << a-b;
}
{% endhighlight %}

## Result
```
| 10 10 |
| 10 10 |

| -8 -6 |
| -4 -2 |
```

## Code

{% highlight c++ %}
template<typename L, typename R, typename T = decltype(L()+R()), std::size_t M, std::size_t N >
Matrix<T,M,N> operator+(const Matrix<L,M,N> lh, const Matrix<R,M,N> rh)
{
	//TODO: Replace with M
  Matrix<T,M,N> ret = lh;
	for(int i=0; i<lh.size(); ++i)
	{
		//TODO: Replace with N
		if(lh[i].size() != rh[i].size()) return lh;
		for(int j=0; j<lh[i].size(); ++j)
		{
			ret[i][j] += rh[i][j];
		}
	}
	return ret;
}

template<typename L, typename R, typename T = decltype(L()+R()), std::size_t M, std::size_t N >
Matrix<T,M,N> operator-(Matrix<L,M,N> lh, Matrix<R,M,N> rh)
{
	if(lh.size() != rh.size()) return lh;
	for(int i=0; i<lh.size(); ++i)
	{
		if(lh[i].size() != rh[i].size()) return lh;
		for(int j=0; j<lh[i].size(); ++j)
		{
			lh[i][j] -= rh[i][j];
		}
	}
	return lh;
}
{% endhighlight %}

Last Modified: November 2018
