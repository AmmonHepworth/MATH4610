---
math: true
layout: default
---
{% include mathjax.html %}
<a href="https://ammonhepworth.github.io/MATH5620/index">HOME</a>

# Matrix Norms

**Routine Name:** oneNormMat and infNormMat

**Author:** Ammon Hepworth

**Language:** C++


## Description

These functions will find the one norm and infinity norm of a matrix. The one norm of a matrix is the maximum summed column and the infinity norm is the maximum summed row.

## Input

An MxN Matrix type of templated type as the first parameter is the only input for both methods. Both will deduce the type and size of your matrix.

## Output

Output for both methods is a double that is either the maximum column sum, for oneNormMat, or the maximum row sum for infNormMat.

## Code

{% highlight c++ %}
#include "../matrixlib/matrix.h"
#include <vector>
#include <algorithm>
#include <cmath>

template <typename T, size_t M, size_t N>
double oneNormMat(Matrix<T,M,N> mat)
{
	std::vector<double> sums(N,0);

	for(int j=0; j< M; ++j)
	{
		for(int i=0; i< N; ++i)
		{
			sums[i] += mat[j][i];
		}
	}
	return *std::max_element(sums.begin(),sums.end());
}


template <typename T, size_t M, size_t N>
double infNormMat(Matrix<T,M,N> mat) 
{
	std::vector<double> sums(M,0);
	for(int i=0; i<M; ++i)
	{
		sums[i] = std::accumulate(mat[i].begin(),mat[i].end(),0);
	}

	return *std::max_element(sums.begin(),sums.end());
}
{% endhighlight %}

## Example

{% highlight c++ %}
#include "../matrixlib/matrix.h"
#include "normMat.h"

int main() {
	Matrix<double,4,4> mat = { {
														 {1,2,3,4},
														 {5,6,7,8},
														 {9,5,2,3},
														 {7,2,1,1}
														 } };

	std::cout << oneNormMat(mat) << std::endl;

	std::cout << infNormMat(mat) << std::endl;
}
{% endhighlight %}

## Result
```
22
26
```

Last Modified: Feb 2018
