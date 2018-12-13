---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Vector Operations - Addition and Subraction

**Routine Names:** operator+,operator-

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++ -std=c++17


## Description

These two routines perform simple addition and subtraction between two vectors. Conveniently, since the routines are written with template programming, this code is exactly the same for matrices and can be reused. In my libraries, vectors are simply matrices of dimension Mx1 which is useful for code reuse and type coersion.

## Input

Since these are implemented as c++ operators, the input will be the binary operands on either side. The vectors must be of equal dimension, and of types that are operatable on each other.

## Output

The output will be a vector of equal dimensions and type with the result of the addition/subtraction. If the types are the same, the resulting type will be deduced. Therefore, operations between number systems resulting in any other number system are supported.

## Example

{% highlight c++ %}
int main() 
{
  Matrix<double,2,1> a = { { {1},
                            {3} } };
  Matrix<double,2,1> b = { { {9},
                            {7} } };

  std::cout << a+b << std::endl << a-b;
}
{% endhighlight %}

## Result
```
| 10 |
| 10 |

| -8 |
| -4 |
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
