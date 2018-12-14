---
math: true
layout: default
---

{% include mathjax.html %}
<a href="https://ammonhepworth.github.io/MATH5620/index">HOME</a>

# Jacobi Iteration

**Routine Name:** jacobi

**Author:** Ammon Hepworth

**Language:** C++


## Description

This algorithm implements jacobi iteration. Jacobi iteration solves for x in an Ax=b system, where A is a diagonal matrix. The matrix iterates until it either hits the maximum iteration count and terminates, or the error becomes small enough to be negligible, and an answer is returned. Running a time analysis shows that the algorithm seems to have a complexity of O(n^2). 

## Input

This algorithm takes two Matrices as parameters. The first parameter is and MxM matrix of template type T, and represents the A matrix in the system. Next is passed in a Mx1 solution vector as a matrix, which is the b in Ax=b. The solution vector is of type double.

## Output

The output is a Mx1 matrix of doubles, representing the solve for x in our equation.

## Example

{% highlight c++ %}
int main()
{
  Matrix<double,4,4> mat = genSymmetricDiagDominant<double,4>(-10,10);
  Matrix<double,4,1> sol = genRightHand(mat);

  std::cout << "A" << std::endl << mat << std::endl;
  std::cout << "b" << std::endl << sol << std::endl;

  std::cout << "Serial x:" << std::endl << jacobi(mat,sol) << std::endl;
  std::cout << "Parallel x:" << std::endl << parallelJacobi(mat,sol) << std::endl;
}
{% endhighlight %}

## Result
```
A
| 12.8301 -0.402173 -4.38169 -3.14442 |
| -0.402173 15.0894 4.37165 -9.75741 |
| -4.38169 4.37165 19.8643 -6.70903 |
| -3.14442 -9.75741 -6.70903 21.3632 |

b
| 4.90184 |
| 9.30143 |
| 13.1452 |
| 1.75231 |

Serial x:
| 1 |
| 1 |
| 1 |
| 1 |

Parallel x:
| 1 |
| 1 |
| 1 |
| 1 |
```

## Code

{% highlight c++ %}
template <typename T, std::size_t M>
Matrix<double,M,1> parallelJacobi(Matrix<T,M,M> A, Matrix<double,M,1> b)
{
  const int maxiter = 1000;
  Matrix<double,M,1> x = genZeros<double,M,1>();

  for(int n=0; n<maxiter; ++n)
  {
    auto xnew = genZeros<double,M,1>();
#pragma omp parallel for
    for(int i=0; i<M; ++i)
    {
      double sum = 0;
      for(int j=0; j<M; ++j)
      {
        if(j != i)
        {
          sum += A[i][j] * x[j][0];
        }
      }
      xnew[i][0] = (b[i][0] - sum) / A[i][i];
    }

    if(allClose(x,xnew)) break;

    x = xnew;
  }
  return x;
}
{% endhighlight %}

Last Modified: November 2018
