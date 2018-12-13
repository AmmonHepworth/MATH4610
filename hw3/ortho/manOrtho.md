---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Orthogonal Basis

**Routine Name:** orthoBasis

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This routine will find an orthogonal pair of normalized basis vectors with respect to two given vectors. An orthogonal basis for an inner product space V is a basis for V whose vectors are mutually orthogonal. If the vectors of an orthogonal basis are normalized, the resulting basis is an orthonormal basis. We can check that vectors are orthogonal if the dot product is 0.

## Input

Two vectors of any operable types, the types will be deduced by the template engine.

## Output

Gives a std::pair of vectors that are the orthogonal vectors. They will be of whatever type the template engine deduces from the operation. We can check to see if the resulting vectors are orthogonal by checking their dot product, seen below. It will either be 0 or close to it.

## Example

{% highlight c++ %}
int main() 
{
  Matrix<double,2,1> a = {{ {2},
                            {5} }}; 
  Matrix<double,2,1> b = {{ {6},
                            {5} }}; 


  auto basis = orthoBasis(a,b);
  std::cout << basis.first << " " << basis.second << " " << std::endl;
  std::cout << "dot: " << dot(basis.first, basis.second) << std::endl;
}
{% endhighlight %}

## Result
```
| 0.768221 |
| 0.640184 |

| -0.640184 |
| 0.768221 |
 
 dot: -5.55112e-17
```

## Code

{% highlight c++ %}
template <typename T, std::size_t M>
std::pair<Matrix<T,M,1>, Matrix<T,M,1> > orthoBasis(Matrix<T,M,1> v1, Matrix<T,M,1> v2)
{

  auto b1 = v2 / pNorm(v2,2);

  auto b2 = v1 - (dot(v1,b1) * b1);
  b2 = b2 / pNorm(b2,2);
  return std::pair<Matrix<T,M,1>, Matrix<T,M,1> >(b1,b2);
}
{% endhighlight %}

Last Modified: November 2018
