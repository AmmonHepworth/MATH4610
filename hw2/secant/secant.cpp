#include <cmath>

template <typename T, typename F>
T rootFindSecant(T x1, T x2, T tol, int maxiter, F f)
{
  T xk;
  for(int i=0; i<maxiter && std::abs(f(x1)) > tol ; ++i)
  {
    xk = x1 - f(x1) * (x1-x2)/(f(x1)-f(x2));
    x1=x2;
    x2=xk;
  }
  return xk;
}
