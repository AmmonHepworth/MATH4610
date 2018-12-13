---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Parallel Matrix Multiply with OMP

**Routine Name:** parallelMult

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++ -fopenmp


## Description

These methods simply perform matrix multiplication in parallel using openMP. In our example here, we use matrices of dimension 300x300 so that they take long enough to see a difference. OpenMP does a fairly good job, reducing the amount of time by more than half. These time savings can be significant since matrix multiplication is an O(n^3) algorithm, especially with how easy OMP is to implement. Two types of parallelism are used here, regular OMP pragma for and one with collapse(3). They seemed equivalent from my testing.

## Input

Two valid, multipliable matrices

## Output

The result of the multiplication.

## Example

{% highlight c++ %}
int main() 
{

  const int i = 300;

  Matrix<double,i,i> a = genRandoms<double,i,i>();
  Matrix<double,i,i> b = genRandoms<double,i,i>();

  auto start = std::chrono::high_resolution_clock::now();
  Matrix<double,i,i> temp =  parallelMult(a,b);
  auto stop = std::chrono::high_resolution_clock::now();
  auto pduration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 

  start = std::chrono::high_resolution_clock::now();
  temp = a*b;
  stop = std::chrono::high_resolution_clock::now();
  auto sduration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 

  start = std::chrono::high_resolution_clock::now();
  temp = parallelMult2(a,b);
  stop = std::chrono::high_resolution_clock::now();
  auto p2duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 
  std::cout << "serial:   " << (double)sduration.count() << "ms" << std::endl;
  std::cout << "parallel: " << pduration.count() << "ms" << std::endl;
  std::cout << "parallel with collapse: " << p2duration.count() << "ms" << std::endl;

}

{% endhighlight %}

## Result
```
serial:   949ms
parallel: 403ms
parallel with collapse: 403ms
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

template<typename L, typename R, typename T = decltype(L()*R()), std::size_t M, std::size_t N, std::size_t O >
Matrix<T,M,O> parallelMult2(const Matrix<L,M,N> lh, const Matrix<R,N,O> rh)
{
  Matrix<T,M,O> temp = genZeros<T,M,O>();
#pragma omp parallel
  {
#pragma omp for collapse(3)
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
