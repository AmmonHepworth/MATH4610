#include <functional>

template <typename T, typename F>
T deriveDef(T x, T h, F f)
{
  return (f(x+h) - f(x))/h;
}


