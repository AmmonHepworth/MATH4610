---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Steepest Descent

**Routine Name:** steepestDescent

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This method attemps to solve a linear system through a method of gradients. The algorithm is quite simple, just find the gradient through a negative residual follow it for a computed step size. This is probably the simplest of all the iterative methods. The intuition behind this algorithm is that we are on a "hill", and must roll down to find the lowest point, which will solve our system the best.

## Input

Takes a single square matrix of any size and type and a solution vector of equal lenghth and type.

## Output

Returns a solution vector of the same length and type as the input, containg the x for the system Ax=b.

## Example

{% highlight c++ %}
int main()
{
  Matrix<double,4,4> mat = genSymmetricDiagDominant<double,4>(-10,10);
  Matrix<double,4,1> sol = genRightHand(mat);

  std::cout << "A" << std::endl << mat << std::endl;
  std::cout << "b" << std::endl << sol << std::endl;

  std::cout << "x" << std::endl << steepestDescent(mat,sol) << std::endl;
}
{% endhighlight %}

## Result
```
A
| 12.5085 4.16839 -4.06347 0.765338 |
| 4.16839 12.3275 2.22793 -4.01631 |
| -4.06347 2.22793 17.2556 -7.56521 |
| 0.765338 -4.01631 -7.56521 14.278 |

b
| 13.3788 |
| 14.7075 |
| 7.85482 |
| 3.46186 |

x
| 1 |
| 1 |
| 1 |
| 1 |
```

## Code

{% highlight c++ %}
template <typename T, std::size_t M>
Matrix<double,M,1> steepestDescent(Matrix<T,M,M> A, Matrix<T,M,1> b)
{
  const int iter = 1000;
  Matrix<T,M,1> x = genRandoms<T,M,1>();
  Matrix<T,M,1> r = b-A*x;

  auto bot = transpose(r)*A*r;
  auto top = (transpose(r)*r);
  auto a = top[0][0]/bot[0][0];
  Matrix<T,M,1> xnew = x;
  int i=0;
  do{
    ++i;
    x = xnew;
    r = b-A*x;
    bot = transpose(r)*A*r;
    top = (transpose(r)*r);
    a = top[0][0]/bot[0][0];
    xnew = x + a*r;
  }while(!allClose(x,xnew) && i < iter);
  return x;


}
{% endhighlight %}

Last Modified: November 2018
