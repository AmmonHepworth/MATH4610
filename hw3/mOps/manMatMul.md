---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Matrix Operations - Multiplication (matrix-matrix and matrix-vector)

**Routine Name:** operator\*

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This routine multiplies a matrix by another matrix, follwing the rules of linear algebra. Multiplication of matrices is NOT commutative, so your order of operands is significant. Since multiplying a matrix by a vector obeys the dimensional rules of matrix multiplication, this code works for both matrix-matrix and matrix-vector multiplication and are thus included together.

## Input

Since this is implemented as a c++ operator, the input will be the binary operands on either side. The left hand matrix is of dimension MxN, and thus the right hand matrix must be of dimension NxO, and of types that are operatable on each other. Remember that matrix multiplication is not commutative.

## Output

The output will be a matrix of dimension MxO and and of a type that results from the multiplication of the types of the input matrices. Therefore, operations between any operable types are permitted.

## Example

{% highlight c++ %}
int main() 
{

  Matrix<double,3,3> a ={ { {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9} } }; 

  Matrix<double,3,3> b ={ { {2, 8, 5},
                            {4, 1, 7},
                            {6, 3, 9} } }; 

  //vector
  Matrix<double,3,1> c ={ { {5},
                            {7},
                            {9} } }; 

  std::cout << a*b << std::endl;

  std::cout << a*c << std::endl;

}
{% endhighlight %}

## Result
```
| 28 19 46 |
| 64 55 109 |
| 100 91 172 |

| 46 |
| 109 |
| 172 |
```

## Code

{% highlight c++ %}
template<typename L, typename R, typename T = decltype(L()*R()), std::size_t M, std::size_t N, std::size_t O >
Matrix<T,M,O> operator*(const Matrix<L,M,N> lh, const Matrix<R,N,O> rh)
{
	Matrix<T,M,O> temp = genZeros<T,M,O>();
	for(int i=0; i<M; ++i)
	{
		for(int j=0; j<O; ++j)
		{
			for(int k=0; k<N; ++k)
			{
				temp[i][j] += lh[i][k] * rh[k][j];
			}
		}
	}
	return temp;
}
{% endhighlight %}

Last Modified: November 2018
