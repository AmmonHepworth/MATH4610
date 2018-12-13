---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Cholesky Factorization

**Routine Name:** choleskyFactorize

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

Cholesky factorization uses characteristics of positive definite symmetric matrices to make linear solving easier. Specifically, these specific matrices can be split into R^TR, and then you can solve each of them separately with substitution. Finding them is not too difficult either, making this a nice choice if your matrices have the correct characteristics.

## Input

Takes a single, square matrix of any type.

## Output

Outputs R, a matrix of equal size and type to the input. This matrix can be multiplied by its transpose to obtain the original matrix again.

## Example

{% highlight c++ %}
int main()
{
  Matrix<double,5,5> e ={ { {1, 7, 2, 1, 5},
                            {7, 74, 29, -3, 75},
                            {2, 29, 38, 6, 64},
                            {1, -3, 6, 25, -15},
                            {5, 75, 64, -15, 190} } };
  
  auto R =  choleskyFactorize(e);
  std::cout << "R" << std::endl << R << std::endl;
  std::cout << "RxR^T" << std::endl << R * transpose(R) << std::endl;

}
{% endhighlight %}

## Result
```
R
| 1 6.95294e-310 6.95294e-310 4.94066e-324 6.95294e-310 |
| 7 5 0 0 6.92895e-310 |
| 2 3 5 0 0 |
| 1 -2 2 4 0 |
| 5 8 6 -4 7 |

RxR^T
| 1 7 2 1 5 |
| 7 74 29 -3 75 |
| 2 29 38 6 64 |
| 1 -3 6 25 -15 |
| 5 75 64 -15 190 |
```

## Code

{% highlight c++ %}
template <typename T, std::size_t M>
Matrix<T,M,M> choleskyFactorize(Matrix<T,M,M> A)
{
  Matrix<T,M,M> ret;
	for (int i=0; i<M; i++)
	{
		for (int j=0; j<(i + 1); j++)
		{
			double s=0;
			for (int k = 0; k < j; k++)
			{
				s += ret[i][k] * ret[j][k];
			}
			if (i == j)
			{
				ret[i][j] = std::sqrt(A[i][i] - s);
			}
			else
			{
				ret[i][j] = 1.0 / ret[j][j] * (A[i][j] - s);
			}
		}
	}
	return ret;
}
{% endhighlight %}

Last Modified: November 2018
