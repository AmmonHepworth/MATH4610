---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Matrix Operations - Trace

**Routine Name:** trace

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This routine finds the trace of a matrix, defined as the sum of the diagonals in a square matrix. It is also the sum of the eigenvalues.

## Input

A single square matrix. Type and size will be deduced and only square matrices are allowed (compile-time enforced)

## Output

The output will be the trace of the matrix of whatever type the original matrix held.

## Example

{% highlight c++ %}
int main() 
{
  Matrix<double,3,3> a ={ { {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9} } };

  std::cout << trace(a) << std::endl;
}
{% endhighlight %}

## Result
```
15
```

## Code

{% highlight c++ %}
template <typename T, size_t M>
T trace(Matrix<T,M,M> mat)
{
  T ret = 0;
  for(int i=0; i<M; ++i)
  {
    ret += mat[i][i];
  }
  return ret;
}
{% endhighlight %}

Last Modified: November 2018
