#include <iostream>
#include <complex>
#include <utility>
template <typename A, typename B, typename C>
std::pair<std::complex<double>,std::complex<double> > quadratic(A a, B b, C c)
{
  std::pair<std::complex<double>,std::complex<double> > ret;
  ret.first = (-b + std::sqrt(b*b-4*a*c))/(2*a);
  ret.second = (-b - std::sqrt(b*b-4*a*c))/(2*a);
  return ret;
}


int main() 
{
  std::cout << quadratic(1,-1,-6).first << std::endl;
  std::cout << quadratic(1,-1,-6).second << std::endl;
}
