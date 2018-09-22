#include <random>
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

template <typename T, typename F>
T rootFindHybridBisectionSecant(T a, T b, T tol, int maxiter, F f)
{
  T c =(a+b)/2;
  T x1 = (a+b)/2;
  static std::random_device rd;
  static std::mt19937 mt(rd());
  std::uniform_real_distribution<> dist(a,b);
  T x2 = dist(mt);
  T xk;

  while(std::abs(f(c)) > tol && maxiter > 0 && f(c) != 0)
  {
    if(c>a && c<b)
    {
      xk = x1 - f(x1) * (x1-x2)/(f(x1)-f(x2));
      x1=x2;
      x2=xk;
      c = xk;
    }
    else
    {
      c = bisectionStep<T>(a, b, tol, f);
    }
  }
  return c;

}
