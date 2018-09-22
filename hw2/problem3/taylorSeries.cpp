

#include <cmath>

unsigned long long int fact(int n)
{
  if(n==0) return 1;
  int product=1;
  for(int i=n; i>1 ; --i)
  {
    product *= i;
  }
  return product;
}


template <typename T>
T sinTaylorSeries(int terms, T x)
{
  T sum = 0;
  for(int i=0; i<terms; ++i)
  {
    sum += std::pow(-1,i) * (double)(std::pow(x,(2*i)+1))/(double)fact((2*i)+1);
  }
  return sum;
}
