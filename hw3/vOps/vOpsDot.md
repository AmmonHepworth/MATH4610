---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Vector Operations - Dot Product (Inner Product)

**Routine Names:** dot

**Author:** Ammon Hepworth

**Language:** C++ compiled with g++ -std=c++17


## Description

This routine gives the dot product between two vectors. The dot product gives us the cosine of the angle between the vectors multiplied by their magnitudes. This can be a convenient as a way to find the angle between vectors as finding the dot product is very simple, just the summation of the product of equal indices in the vectors.

## Input

The inputs are two vectors of any length of any operable types.

## Output

The output will be a double scalar that is the dot product of the two vectors.

## Example

{% highlight c++ %}
int main() 
{
  Matrix<double,3,1> a = {{ {1},
                            {2},
                            {3} }};

  Matrix<double,3,1> b = {{ {1},
                            {5},
                            {7} }};

  std::cout << dot(a,b) << std::endl;
}
{% endhighlight %}

## Result
```
32
```

## Code

{% highlight c++ %}
template <typename T, size_t M>
double dot(Matrix<T,M,1> mat1, Matrix<T,M,1> mat2)
{
	double sum=0;
	for(int i=0; i<M; ++i)
	{
		sum += mat1[i][0]*mat2[i][0];
	}
	return sum;
}
{% endhighlight %}

Last Modified: November 2018
