---
math: true
layout: default
---

{% include mathjax.html %}
<a href="https://ammonhepworth.github.io/MATH5620/index">HOME</a>

# 2-Condition Number

**Routine Name:** condition2

**Author:** Ammon Hepworth

**Language:** C++


## Description

The condition number is the ratio of the largest and smallest eigenvalues of a matrix. Generally, the condition number is a measurement of sensitivity of a matrix. This how much the solution of a linear system using that matrix will change with a perturbation in the matrix itself. Matrices with high condition numbers are considered ill-conditioned, and are not good for using in linear solvers.

## Input

A square matrix of any type is taken as input.

## Output

The output is a single double that is the condition number for the matrix.

## Example

{% highlight c++ %}

int main()
{

  auto A = genSymmetricDiagDominant<double,5>(-10,10);


  std::cout <<"A" << std::endl<< A << std::endl;
  std::cout << "Condition Number: " << condition2(A) << std::endl;
}
{% endhighlight %}

## Result
```
A
| 30.8837 -9.70537 3.18498 -5.18757 -9.47436 |
| -9.70537 28.5849 6.96622 -9.48843 1.07869 |
| 3.18498 6.96622 19.7614 -8.81335 0.518061 |
| -5.18757 -9.48843 -8.81335 33.6902 -5.94129 |
| -9.47436 1.07869 0.518061 -5.94129 17.918 |

Condition Number: 6.33827
```

## Code

{% highlight c++ %}
template <typename T, size_t M, size_t N>
double condition2(Matrix<T,M,N> A)
{
  auto max = powerIteration(A);
  auto min = inversePowerIteration(A);
  return std::abs(max/min);
}
{% endhighlight %}

Last Modified: December 2018
