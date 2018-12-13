---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# LU Factorization

**Routine Name:** LUSolveSystem

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This routine performs the forward and back substitution using the matrices from our luFactorize method to compute our x vector. This method combines all the pieces together to create a fully functional linear solver. We can see below that our system works, verified by getting a zero vector from Ax-b. Exciting!

## Input

This method will take in the matrix A, a square matrix of any type, and b, our solution vector used for forward/back substitution.

## Output

The result is the vector x that solves the system Ax=b

## Example

{% highlight c++ %}
int main()
{

  Matrix<double,4,4> A = {{ {1, 3, 5, 9},
                            {1, 3, 1, 7},
                            {4, 3, 9, 7},
                            {5, 2, 0, 9} }}; 

  Matrix<double,4,1> b = {{ {1},
                            {2},
                            {8},
                            {3} }}; 

  auto sol = LUSolveSystem(A,b);
  std::cout << "x" << std::endl << sol << std::endl;
  std::cout << "Ax-b" << std::endl << A\*sol - b << std::endl;
}
{% endhighlight %}

## Result
```
x
| 1.38298 |
| 2.375 |
| 0.231383 |
| -0.962766 |

Ax-b
| 0 |
| 0 |
| 0 |
| 0 |
```

## Code

{% highlight c++ %}
template <typename T, std::size_t M, std::size_t N>
Matrix<T,M,1> LUSolveSystem(Matrix<T,M,N> A, Matrix<T,M,1> b)
{
	//std::tuple<Matrix<double,M,N>, Matrix<double,M,N>, Matrix<double,M,N>> LUPieces = luFactorize(A);
	auto LUPieces = luFactorize(A);
  auto L = std::get<0>(LUPieces);
  auto U = std::get<1>(LUPieces);
  auto P = std::get<2>(LUPieces);
  Matrix<double,M,1> PB= P*b;
  Matrix<double,M,1> y = forwardSubstitute(L,PB);
  Matrix<double,M,1> x = backSubstitute(U,y);

  return x;
}
{% endhighlight %}

Last Modified: November 2018
