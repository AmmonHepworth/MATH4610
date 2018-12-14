---
math: true
layout: default
---

{% include mathjax.html %}
<a href="https://ammonhepworth.github.io/MATH5620/index">HOME</a>

# Parallel 2-Condition Number

**Routine Name:** parallelCondition2

**Author:** Ammon Hepworth

**Language:** C++


## Description

This is the parallel version of the 2-condition. It was parallelized using openMP directives. The parallelization occurs in the power and inverse power methods, both of which use an openMP directive on their for loops for parallelization.

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
  std::cout << "Parallel Condition Number: " << ParallelCondition2(A) << std::endl;
}
{% endhighlight %}

## Result
```
A
| 19.2331 -0.287977 2.27869 8.23844 -8.04786 |
| -0.287977 13.2241 -6.58835 0.493323 -5.3707 |
| 2.27869 -6.58835 16.7654 3.53184 -2.2579 |
| 8.23844 0.493323 3.53184 17.5012 -2.94747 |
| -8.04786 -5.3707 -2.2579 -2.94747 21.9274 |

Parallel Condition Number: 6.64822
```

## Code

{% highlight c++ %}
template <typename T, size_t M, size_t N>
double parallelCondition2(Matrix<T,M,N> A)
{
  auto max = parallelPowerIteration(A);
  auto min = parallelInversePowerIteration(A);
  return std::abs(max/min);
}
{% endhighlight %}

Last Modified: December 2018
