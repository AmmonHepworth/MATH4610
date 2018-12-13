---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Cholesky Linear Solving

**Routine Name:** choleskySolveSystem

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

Cholesky factorization uses characteristics of positive definite symmetric matrices to make linear solving easier. Specifically, these specific matrices can be split into R^TR, and then you can solve each of them separately with substitution. Finding them is not too difficult either, making this a nice choice if your matrices have the correct characteristics.

## Input

Takes a single, square matrix of any type and a solution vector of the same length as the matrix

## Output

Outputs x satisfying Ax=b, where x is a vector of the same length and type as b.

## Example

{% highlight c++ %}
int main()
{
  Matrix<double,5,5> e = {{ {1, 7, 2, 1, 5},
                            {7, 74, 29, -3, 75},
                            {2, 29, 38, 6, 64},
                            {1, -3, 6, 25, -15},
                            {5, 75, 64, -15, 190} }}; 

  Matrix<double,5,1> b = {{ {2},
                            {5},
                            {-1},
                            {2},
                            {8} }};

  auto sol = choleskySolveSystem(e, b);
  std::cout << sol << std::endl;
  std::cout << e\*sol - b << std::endl;
}
{% endhighlight %}

## Result
```
x
| 5.46849 |
| -0.559967 |
| -0.156449 |
| -0.0684694 |
| 0.166531 |

Ax-b
| 0 |
| 7.99361e-15 |
| 1.77636e-15 |
| 8.88178e-16 |
| 0 |
```

## Code

{% highlight c++ %}
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
