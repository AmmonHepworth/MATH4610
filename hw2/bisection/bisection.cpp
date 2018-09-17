#include <cmath>
#include <iostream>

template <typename T, typename F>
T rootFindBisection(T a, T b, T tol, int maxiter, F f)
{
  if(f(a) * f(b) > 0) 
  {
    std::cout << "ERROR: root not found, sign of a and b are the same" << std::endl;
    return 0;
  }

  T c = (a+b)/2;

  while(std::abs(f(c)) > tol && maxiter > 0 && f(c) != 0)
  {
    --maxiter;
    if(f(c)*f(a) > 0)
      a = c;
    else
      b = c;

    c = (a+b)/2;
  }
  if(maxiter == 0)
    std::cout << "ERROR: root not found, maxiter exceeded" << std::endl;

  return c;
}
