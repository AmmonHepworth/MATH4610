---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Combined Linear solver - Gauss Elimination and Back Substitution

**Routine Name:** solveSystemGaussian

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This routine will solve a linear system of equations using Gauss elimination and back substitution. This means that we no longer need special conditions for our matrices to be able to solve them. For the most part, we can just solve systems now. The method works by creating a rectangular matrix with the solution vector appended to the A matrix and then row reducing it with Gauss elimination. Then we remove the appended solution vector and use the newly reduced matrix and chopped solution vector to back substitue to find our x vector. We check with Ax-b to ensure that our solution was correct.

## Input

This method takes A matrix that will need to be square to be completely solved, but can be any size and type. It also takes a solution vector that is the same length as the dimensions of the matrix.

## Output

This will return the x vector for the system Ax=b, which has equal length to the passed solution vector and will be a vector of doubles.

## Example

{% highlight c++ %}
int main()
{
  Matrix<double,4,4> A = {{ {1, 2, 3, 4},
                            {4, 5, 6, 6},
                            {2, 5, 1, 2},
                            {7, 8, 9, 7} }}; 

  Matrix<double,4,1> b = {{ {31},
                            {58},
                            {49},
                            {76} }}; 

  auto sol = solveSystemGaussian(A,b);
  std::cout << sol << std::endl;
  std::cout << "Ax-b: " << std::endl << A\*sol - b << std::endl;
}
{% endhighlight %}

## Result
```
| 4 |
| 6 |
| -7 |
| 9 |

Ax-b: 
| 7.10543e-15 |
| 7.10543e-15 |
| 0 |
| 0 |
```

## Code

{% highlight c++ %}
template <typename T, std::size_t M, std::size_t N>
Matrix<T,M,1> solveSystemGaussian(Matrix<T,M,N> A, Matrix<T,M,1> b)
{
  Matrix<T,M,N+1> modifiedMat;
  for(int i=0; i<M; ++i)
    for(int j=0; j<M; ++j)
      modifiedMat[i][j] = A[i][j];

  for(int i=0; i<M; ++i)
    modifiedMat[i][N] = b[i][0];


  modifiedMat = rowReduce(modifiedMat);

  Matrix<T,M,N> noModMat;
  for(int i=0; i<M; ++i)
    for(int j=0; j<N; ++j)
      noModMat[i][j] = modifiedMat[i][j];

  Matrix<T,M,1> nb;
  for(int i=0; i<M; ++i)
    nb[i][0] = modifiedMat[i][N];

  auto sol = backSubstitute(noModMat,nb);
  return sol;
}
{% endhighlight %}

Last Modified: November 2018
