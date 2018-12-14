---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Serial vs Parallel Condition Numbers

**Routine Name:** condition2, parallelCondition2

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++


## Description/Results

This timed the speed at which the serial and parallel versions of finding the 2-condition finshed. For its ease, openMP does a very good job for being such a simple implementation. Timings for the parallel versions were regularly about half of the serial version. I didn't expect that much speedup, to be honest.

## Example

{% highlight c++ %}
int main()
{

  auto A = genSymmetricDiagDominant<double,30>(-10,10);


  auto start = std::chrono::high_resolution_clock::now();
  auto c= condition2(A);
  auto end = std::chrono::high_resolution_clock::now();
  auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
  std::cout <<"Serial: " << dur << " ms" << std::endl;

  start = std::chrono::high_resolution_clock::now();
  c= parallelCondition2(A);
  end = std::chrono::high_resolution_clock::now();
  dur = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
  std::cout << "Parallel: " << dur << " ms" << std::endl;

}
{% endhighlight %}

## Result
```
Serial: 2944 ms
Parallel: 1198 ms
```

Last Modified: December 2018
