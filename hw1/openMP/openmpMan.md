---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH5620/index">HOME</a>

{% include mathjax.html %}

# OpenMP Example

**Routine Name:** N/A

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++ -fopenmp


## Description

This is an introductory example to using OpenMP

## Input

No arguments are taken.

## Output

The number of threads and a hello world from each.

## Example

{% highlight c++ %}
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {

  int nthreads, tid;

#pragma omp parallel private(nthreads, tid)
  {

    tid = omp_get_thread_num();
    printf("Hello World from thread = %d\n", tid);

    if (tid == 0) 
    {
      nthreads = omp_get_num_threads();
      printf("Number of threads = %d\n", nthreads);
    }
  }
}
{% endhighlight %}

## Result
```
Hello World from thread = 2
Hello World from thread = 0
Number of threads = 4
Hello World from thread = 1
Hello World from thread = 3
```
Last Modified: September 2018
