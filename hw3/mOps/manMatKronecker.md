---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Matrix Operations - Kronecker Product

**Routine Name:** kronecker

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description

This routine will compute the kronecker product of two matrices. Given two matrices with dimensions MxN and PxQ, the kronecker product will return a matrix of M\*PxN\*Q, where the resulting matrix is a block matrix consisting of each element of the first matrix multiplied as a scalar into the entire second matrix.

## Input

Two matrices of any operable types and of any size.

## Output

A block matrix of dimension M\*PxN\*Q of the type resulting from the multiplication of the two input types.

## Example

{% highlight c++ %}
int main() 
{

  Matrix<double,2,2> a = {{ {1, 2},
                            {3, 4} }}; 

  Matrix<double,2,2> b = {{ {0, 5},
                            {6, 7} }}; 

  Matrix<double,3,1> c = {{ {1},
                            {2},
                            {3} }}; 

  Matrix<double,1,2> d = {{ {0, 5} }};

  Matrix<double,3,2> e = {{ {1, 2},
                            {3, 4},
                            {1, 0} }}; 

  Matrix<double,2,3> f = {{ {0, 5, 2},
                            {6, 7, 3} }}; 

  std::cout << kronecker(a,b) << std::endl;
  std::cout << "Outer Product" << std::endl;
  std::cout << kronecker(c,d) << std::endl;
  std::cout << kronecker(e,f) << std::endl;

}
{% endhighlight %}

## Result
```
| 0 5 0 10 |
| 6 7 12 14 |
| 0 15 0 20 |
| 18 21 24 28 |

Outer Product
| 0 5 |
| 0 10 |
| 0 15 |

| 0 5 2 0 10 4 |
| 6 7 3 12 14 6 |
| 0 15 6 0 20 8 |
| 18 21 9 24 28 12 |
| 0 5 2 0 0 0 |
| 6 7 3 0 0 0 |
```

## Code

{% highlight c++ %}
  template<typename T, typename T2, typename R = decltype(T()*T2()), std::size_t M, std::size_t N, std::size_t P, std::size_t Q>
Matrix<R,M*P,N*Q> kronecker(Matrix<T,M,N> lh, Matrix<T2,P,Q> rh)
{
  Matrix<R,M*P,N*Q> ret;
  for(int i=0; i<M*P; ++i)
  {
    for(int j=0; j<N*Q; ++j)
    {
      ret[i][j] = lh[i/N][j/M] * rh[i%P][j%Q];
    }
  }
  return ret;
}
{% endhighlight %}

Last Modified: November 2018
