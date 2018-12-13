---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Gaussian Elimination - Square

**Routine Name:** rowReduce

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This routine will coerce a given square matrix into its row echelon form. It will perform the operation in place, and will not return a value. Gaussian elimination, otherwise known as row reduction, is useful for solving linear systems as it puts them into a form in which solving for variables is easy.

## Input

A single square matrix of any computable type.

## Output

The routine will perform the elimination in place, meaning it will directly edit the given matrix and does not return a value.

## Example

{% highlight c++ %}
int main()
{
  Matrix<double,3,3> a = {{ {1, 2, 3},
                            {3, 5, 7},
                            {1, 5, 7} }}; 
  rowReduce(a);
  std::cout << a << std::endl;
}
{% endhighlight %}

## Result
```
| 3 5 7 |
| 0 3.333 4.667 |
| 0 0 0.2 |
```

## Code

{% highlight c++ %}
template<typename T, std::size_t M, std::size_t N>
Matrix<double,M,N> rowReduce(Matrix<T,M,N>& ret)
{

  //for each column
  for(int j=0; j<N; ++j)
  {
    //find highest row value
    int max = j;
    for(int i=j; i<M; ++i)
    {
      if(std::abs(ret[i][j]) > std::abs(ret[max][j])) max = i;
    }
    //swap to top
    std::swap(ret[j], ret[max]);

    T pivot = ret[j][j];
    //reduce with all rows below
    for(int k=j+1; k<M; ++k)
    {
      T killer = ret[k][j] / pivot;
      for(int l=j; l<N; ++l)
      {
        ret[k][l] = ret[k][l] - (killer*ret[j][l]);
      }
    }
  }
}
{% endhighlight %}

Last Modified: November 2018
