#include <cmath>

template <typename T, typename F>
T rootFindFunctionIteration(T guess, T tol, int maxiter, F f)
{
  T x;
  while(maxiter>0)
  {
    --maxiter;
    x = f(guess);
    if(std::abs(x-guess) < tol) return x;
    guess = x;
  }
  return guess;

}
