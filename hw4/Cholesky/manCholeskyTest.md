---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Cholesky Tests

**Routine Name:** N/A

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description/Results

The cholesky factorization is fairly fast. The program below generates a 400x400 matrix for it to solve and it does so in less than a quarter of a second on my old laptop. This makes it already slightly faster than LU factorization. Unfortunately the matrix market did not have any good matrices to test with that fit the criteria and werent unusably large, that is why I have randoms being generated.

## Input

Takes a single, square matrix of any type and a solution vector of the same length as the matrix

## Output

Outputs x satisfying Ax=b, where x is a vector of the same length and type as b.

## Example

{% highlight c++ %}
int main()
{
  const int i= 400;
  Matrix<double,i,i> A = genRandoms<double,i,i>();
  Matrix<double,i,1> x = genRandoms<double,i,1>();

  auto start = std::chrono::high_resolution_clock::now();
  auto sol = choleskySolveSystem(A, x);
  auto end = std::chrono::high_resolution_clock::now();
  auto dur = std::chrono::duration<double,std::milli>(end-start).count();
  std::cout << "time: " << dur << " ms" << std::endl;
}
{% endhighlight %}

## Result
```
time: 272.115 ms
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

template <typename T, std::size_t M>
Matrix<T,M,1> choleskySolveSystem(Matrix<T,M,M> A, Matrix<T,M,1> b)
{
  auto R = choleskyFactorize(A);
  auto y = forwardSubstitute(R,b);
  auto x = backSubstitute(transpose(R),y);
  return x;

}
{% endhighlight %}

Last Modified: November 2018
