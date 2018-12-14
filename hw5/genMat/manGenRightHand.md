---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Generate Right Hand Solution

**Routine Name:** genRightHand

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This routine will generate the right hand side of a system of equations, where the matrix has been multipled by a vector of 1s. This is useful for generating test functions for evaluating linear solvers.

## Input

A square matrix of any size and type.

## Output

A vector of equal length and type to the input matrix, holding the product of the matrix and a vector of 1s.

## Example

{% highlight c++ %}
int main() 
{
  auto mat = genSymmetricDiagDominant<int,5>(-10,10);
  std::cout << mat << std::endl;

  std::cout << genRightHand(mat) << std::endl;
}
{% endhighlight %}

## Result
```
| 11 2 4 2 2 |
| 2 19 -8 -8 0 |
| 4 -8 25 3 6 |
| 2 -8 3 23 9 |
| 2 0 6 9 19 |

| 21 |
| 5 |
| 30 |
| 29 |
| 36 |
```

## Code

{% highlight c++ %}
template<typename T, std::size_t M>
Matrix<T,M,1> genRightHand(Matrix<T,M,M> mat)
{
  Matrix<T,M,1> ones;
  for(int i=0; i<M; ++i)
    ones[i][0] = 1;
  return mat*ones;
}
{% endhighlight %}

Last Modified: November 2018
