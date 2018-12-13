---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Vector Operations - Scalar Multiplication

**Routine Names:** operator*

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++ -std=c++17


## Description

This routines performs scalar multiplication with a vector. Conveniently, since the routine is written with template programming, this code is exactly the same for matrices and can be reused. In my libraries, vectors are simply matrices of dimension Mx1 which is useful for code reuse and type coersion.

## Input

Since these are implemented as c++ operators, the input will be the binary operands on either side. If the type of the scalar and the vector are different, the resulting type will be deduced by the compiler.

## Output

The output will be a vector of equal size to the input with the scalar multiplied into it.

## Example

{% highlight c++ %}
int main() 
{
  double a = 2;
  Matrix<double,2,1> b = {{ {9},
                            {7} }};

  std::cout << a*b << std::endl;
}
{% endhighlight %}

## Result
```
| 18 |
| 14 |
```

## Code

{% highlight c++ %}
template<typename L, typename R, typename T = decltype(L()*R()), std::size_t M, std::size_t N>
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
