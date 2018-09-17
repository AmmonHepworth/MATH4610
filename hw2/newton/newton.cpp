#include <cmath>

template <typename T, typename F, typename F1>
T rootFindNewton(T guess, T tol, int maxiter, F f, F1 fp1)
{
  for(int i=0; i<maxiter && std::abs(f(guess)) > tol ; ++i)
  {
    guess = guess - (f(guess)/fp1(guess));
  }
  return guess;
}
