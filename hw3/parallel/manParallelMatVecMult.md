---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Parallel Matrix-Vector Multiply with OMP

**Routine Name:** parallelMult

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++ -fopenmp


## Description

This routine simply performs matrix-vector multiplication in parallel using openMP. In our example here, we use a matrix of dimension 700x700 and vector size of 700x1. OpenMP does well, but not quite as well as full matrix-matrix multiplication in general.

## Input

Two valid, multipliable matrices

## Output

The result of the multiplication.

## Example

{% highlight c++ %}
int main() 
{

  const int i = 720;

  Matrix<double,i,i> a = genRandoms<double,i,i>();
  Matrix<double,i,1> b = genRandoms<double,i,1>();

  auto start = std::chrono::high_resolution_clock::now();
  Matrix<double,i,1> temp =  parallelMult(a,b);
  auto stop = std::chrono::high_resolution_clock::now();
  auto pduration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 

  start = std::chrono::high_resolution_clock::now();
  temp = a*b;
  stop = std::chrono::high_resolution_clock::now();
  auto sduration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 

  std::cout << "serial:   " << (double)sduration.count() << "ms" << std::endl;
  std::cout << "parallel: " << pduration.count() << "ms" << std::endl;

}

{% endhighlight %}

## Result
```
serial:   17ms
parallel: 9ms
```

## Code

{% highlight c++ %}
template<typename L, typename R, typename T = decltype(L()*R()), std::size_t M, std::size_t N, std::size_t O >
Matrix<T,M,O> parallelMult(const Matrix<L,M,N> lh, const Matrix<R,N,O> rh)
{
  Matrix<T,M,O> temp = genZeros<T,M,O>();
#pragma omp parallel
  {
#pragma omp for
    for(int i=0; i<M; ++i)
    {
      for(int j=0; j<O; ++j)
      {
        for(int k=0; k<N; ++k)
        {
          temp[i][j] += lh[i][k] * rh[k][j];
        }
      }
    }
  }
  return temp;
}
{% endhighlight %}

Last Modified: November 2018
