---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Generate Square Symmetric Diagonally Dominant Matrix

**Routine Name:** genSymmetricDiagDominant

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This method will create and return a matrix that is square, symmetric, and diagonally dominant. It can be of any size and type. The entries will be random between a range that you pick, except for the diagonally dominant ones, which will be larger to ensure diagonal dominance.

## Input

The inputs are given as template arguments and arguments to the function. The template arguments will determine the number type of the martrix and the size of the square matrix. The function arguments will be the bounds of the elements in the matrix and can be any number desired of the type given in the template.

## Output

The output will be a matrix of the given size and type, that is symmetric and diagonally dominant with upper and lower triangle elements between the given bounds.

## Example

{% highlight c++ %}
int main() 
{
  auto mat = genSymmetricDiagDominant<int,5>(-10,10);
  std::cout << mat << std::endl;
}
{% endhighlight %}

## Result
```
| 34 7 9 -7 7 |
| 7 30 -8 -6 7 |
| 9 -8 28 5 -4 |
| -7 -6 5 19 -1 |
| 7 7 -4 -1 20 |
```

## Code

{% highlight c++ %}
template<typename T, std::size_t M>
Matrix<T,M,M> genSymmetricDiagDominant(T a, T b)
{
  Matrix<T,M,M> ret = genZeros<T,M,M>();
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(a,b);

  for(int i=0; i<M; ++i)
  {
    for(int j=i+1; j<M; ++j) 
    { 
      //produces a uniform distribution of real numbers
      ret[i][j] = (T)(dis(gen));
    }
  }

  for(int i=0; i<M; ++i)
  {
    for(int j=i; j<M; ++j) 
    { 
      ret[j][i] = ret[i][j];
    }
  }

  //diagonal dominance
  for(int i=0; i<M; ++i)
  {
    auto rowSum = std::accumulate(ret[i].begin(), ret[i].end(), 0.0, [](T a, T b){ return a + std::abs(b); });
    ret[i][i] = rowSum + std::abs(dis(gen))/2;
  }

  return ret;
}
{% endhighlight %}

Last Modified: November 2018
