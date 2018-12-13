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

This routine will perform a substitution on an upper triangular matrix and solution. In essence, this performs a very simple linear solve on a simplified system. We check to see that our solution was good by plugging into the system Ax-b. If the resulting vector is 0s or close to it we have a good solution

## Input

Takes the upper triangular matrix as a matrix, and it is left up to the user to ensure that it is truly a lower triangular matrix. The second parameter is the solution matrix as a vector.

## Output

It will produce a vector of the same size as the input vector that contains an approximate x solving the equation Ax=b.

## Example

{% highlight c++ %}
int main() 
{

  Matrix<double,4,4> A ={ { {4, -1, 2, 3},
                            {0, -2, 7, -4},
                            {0, 0, 6, 5},
                            {0, 0, 0, 3} } }; 

  Matrix<double,4,1> b ={ { {20},
                            {-7},
                            {4},
                            {6} } }; 

  auto sol = backSubstitute(A,b);
  std::cout << sol << std::endl;
  std::cout << "Ax-b: " << std::endl << A\*sol - b << std::endl;

}
{% endhighlight %}

## Result
```
| 3 |
| -4 |
| -1 |
| 2 |

Ax-b: 
| 0 |
| 0 |
| 0 |
| 0 |
```

## Code

{% highlight c++ %}
  template<typename T, std::size_t M, std::size_t N>
Matrix<double,M,1> backSubstitute(Matrix<T,M,N> U, Matrix<double,M,1> b)
{
  Matrix<double,M,1> x = genZeros<double,M,1>();

  for(int i=(int)M-1;i>=0;--i)
  {
    double sum = 0;
    for(int j=(int)i+1; j<(int)M; ++j)
    {
      sum += U[i][j]*x[j][0];
    }
    x[i][0] = (b[i][0] - sum) / U[i][i];
  }
  return x;
}
{% endhighlight %}

Last Modified: Novermber 2018
