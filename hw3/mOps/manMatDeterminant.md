---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Matrix Operations - Determinant

**Routine Name:** determinant

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This routine will find the determinant of a matrix, which exist only for square matrices. Determinants are often useful in solving linear systems.

## Input

A single square matrix. Type and size will be deduced and only square matrices are allowed (compile-time enforced)

## Output

The output will be the determinant of the matrix of whatever type the original matrix held.

## Example

{% highlight c++ %}
int main() 
{
  Matrix<double,4,4> a = {{ {1, 3, 5, 9},
                            {1, 3, 1, 7},
                            {4, 3, 9, 7},
                            {5, 2, 0, 9} }}; 

  std::cout << determinant(e) << std::endl;

}
{% endhighlight %}

## Result
```
-376
```

## Code

{% highlight c++ %}
template<typename T>
double \_det(std::vector<std::vector<T> > mat)
{
  T det = 0;
  if(mat.size() == 2)
    return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

  std::vector<std::vector<T>> newMat = mat;
  for(int i=0; i<mat.size(); ++i)
  {
    std::vector<std::vector<T> > lessCol = withoutCol(mat,i);
    std::vector<std::vector<T> > lessRow = withoutRow(lessCol,0);
    auto detStep = mat[0][i] * \_det(lessRow);
    det += (i%2==0) ? detStep : -detStep;
  }
}

template<typename T, std::size_t M>
double determinant(Matrix<T,M,M> mat)
{
  std::vector<std::vector<T> > newMat(M);
  for(int i=0; i<M; ++i)
  {
    newMat[i] = std::vector<T>(mat[i].begin(),mat[i].end());
  }

  return \_det(newMat);
}
{% endhighlight %}

Last Modified: November 2018
