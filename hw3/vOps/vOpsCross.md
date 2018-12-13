---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Vector Operations - Cross Product

**Routine Names:** cross

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++ -std=c++17


## Description

This routine will perform the cross product between two vectors. This will give a vector orthogonal to both of the input vectors according to the right hand rule.

## Input

The inputs are two vectors with 3 elements (3x1 matrices for library purposes) of any operable types.

## Output

The output will be a third vector of length 3 that is orthogonal to the input vectors. The type will of equal type to the input vectors.

## Example

{% highlight c++ %}
int main() 
{
  Matrix<double,3,1> a = { { {1},
                            {2},
                            {3} } };

  Matrix<double,3,1> b = { { {1},
                            {5},
                            {7} } };

  std::cout << cross(a,b) << std::endl;
}
{% endhighlight %}

## Result
```
| -1 |
| -4 |
| 3 |
```

## Code

{% highlight c++ %}
template <typename T, size_t M>
Matrix<T,3,1> cross(Matrix<T,3,1> mat1, Matrix<T,3,1> mat2)
{
  Matrix<T,3,1> res = { {mat1[1][0]*mat2[2][0] - mat1[2][0]*mat2[1][0]},
                        {mat1[2][0]*mat2[0][0] - mat1[0][0]*mat2[2][0]},
                        {mat1[0][0]*mat2[1][0] - mat1[1][0]*mat2[0][0]} };
  return res;
}
{% endhighlight %}

Last Modified: November 2018
