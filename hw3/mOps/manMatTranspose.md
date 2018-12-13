---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Matrix Operations - Transpose

**Routine Name:** transpose

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This routine takes the transpose of a matrix, where a matrix is "flipped over its diagonal." More formally, the ith row becomes the jth column and vice versa.

## Input

The input is a single matrix of any type and size.

## Output

The output will be a transposed matrix with the same type as the input and of dimensions opposite to the input matrix.

## Example

{% highlight c++ %}
int main() 
{

  Matrix<double,3,2> a = {{ {1, 2},
                            {3, 4},
                            {5, 6} }}; 

  std::cout << transpose(a) << std::endl;
}
{% endhighlight %}

## Result
```
| 1 3 5 |
| 2 4 6 |
```

## Code

{% highlight c++ %}
template <typename T, size_t M, size_t N>
Matrix<T,N,M> transpose(Matrix<T,M,N> mat)
{
  Matrix<T,N,M> ret;
  for(int i=0; i<M; ++i)
  {
    for(int j=0; j<N; ++j)
    {
      ret[j][i] = mat[i][j];
    }
  }
  return ret;
}
{% endhighlight %}

Last Modified: November 2018
