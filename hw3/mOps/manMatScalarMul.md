---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Matrix Operations - Scalar Multiplication

**Routine Name:** operator\*

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This routine multiplies a matrix by a scalar, linearly scaling each value in the matrix.

## Input

Since this is implemented as a c++ operator, the input will be the binary operands on either side. The matrices must be of equal dimension, and of types that are operatable on each other. The operands can be in any order you desire.

## Output

The output will be a matrix of equal dimensions and type with the result of the scalar multiplication. If the types are the same, the resulting type will be deduced. Therefore, operations between number systems resulting in any other number system are supported.

## Example

{% highlight c++ %}
int main() 
{

  Matrix<double,2,2> a = { { {1, 2},
                             {3, 4} } }; 

  std::cout << a * 2 << std::endl;

}
{% endhighlight %}

## Result
```
| 2 4 |
| 6 8 |
```

## Code

{% highlight c++ %}
template<typename L, typename R, typename T = decltype(L()\*R()), std::size_t M, std::size_t N>
Matrix<T,M,N> operator*(const R rh, const Matrix<L,M,N> lh)
{
	Matrix<T,M,N> temp = genZeros<T,M,N>();
	for(int i=0; i<M; ++i)
	{
		for(int j=0; j<N; ++j)
		{
			temp[i][j] = lh[i][j] * rh;
		}
	}
	return temp;
}
{% endhighlight %}

Last Modified: November 2018
