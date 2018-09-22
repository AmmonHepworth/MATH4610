#include <cmath>
#include <iostream>

template <typename T, typename F>
T bisectionStep(T& a, T& b, T tol, F f)
{
  if(f(a) * f(b) > 0) 
  {
    std::cout << "ERROR: root not found, sign of a and b are the same" << std::endl;
    return 0;
  }

  T c = (a+b)/2;

  for(int i=0; i<4; ++i)
  {
    if(f(c)*f(a) > 0)
      a = c;
    else
      b = c;

    c = (a+b)/2;
  }

  return c;
}

template <typename T, typename F, typename F1>
T newtonStep(T guess, T tol, F f, F1 fp1)
{
  return guess - (f(guess)/fp1(guess));
}

template <typename T, typename F, typename FP>
T rootFindHybridBisectionNewton(T a, T b, T tol, int maxiter, F f, FP fp)
{
  T c =(a+b)/2;
  while(std::abs(f(c)) > tol && maxiter > 0 && f(c) != 0)
  {
    if(c>a && c<b)
    {
      c = newtonStep<T>(c, tol, f, fp);
    }
    else
    {
      c = bisectionStep<T>(a, b, tol, f);
    }
  }
  return c;

}
