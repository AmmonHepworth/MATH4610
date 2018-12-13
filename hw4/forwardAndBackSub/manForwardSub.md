---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Forward Substitution

**Routine Name:** forwardSubstitute

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This routine will perform a substitution on a lower triangular matrix and solution. In essence, this performs a very simple linear solve on a simplified system. If the resulting vector is 0s or close to it we have a good solution

## Input

Takes the lower triangular matrix as a matrix, and it is left up to the user to ensure that it is truly a lower triangular matrix. The second parameter is the solution matrix as a vector.

## Output

It will produce a vector of the same size as the input vector that contains an approximate x solving the equation Ax=b.

## Example

{% highlight c++ %}
int main() 
{

  Matrix<double,4,4> A ={ { {1, 0, 0, 0},
                            {1, 3, 0, 0},
                            {4, 3, 9, 0},
                            {5, 2, 0, 9} } }; 

  Matrix<double,4,1> b ={ { {1},
                            {2},
                            {8},
                            {3} } }; 

  auto sol = forwardSubstitute(A,b);
  std::cout << sol << std::endl;
  std::cout << "Ax-b: " << std::endl << A*sol - b << std::endl;
}
{% endhighlight %}

## Result
```
| 1 |
| 0.333333 |
| 0.333333 |
| -0.296296 |

Ax-b: 
| 0 |
| 0 |
| 0 |
| 0 |
```

## Code

{% highlight c++ %}
  template<typename T, std::size_t M, std::size_t N>
Matrix<double,M,1> forwardSubstitute(Matrix<T,M,N> L, Matrix<double,M,1> sol)
{
  Matrix<double,M,1> x;
  x[0][0] = sol[0][0];
  for(int i=0; i<M; ++i)
  {
    double sum = 0;
    for(int j=0; j<i; ++j)
    {
      sum += L[i][j]*x[j][0];
    }
    x[i][0] = (sol[i][0] - sum)/ L[i][i];
  }
  return x;
}
{% endhighlight %}

Last Modified: Novermber 2018
