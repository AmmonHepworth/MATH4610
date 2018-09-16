#include <iostream>
#include <fstream>
#include "../error/error.h"
#include "derivativeDefinition.cpp"

int main()
{
  double dx;
  double sindx;
  std::ofstream polygraph("polyGraph.txt");
  std::ofstream singraph("sinGraph.txt");
  polygraph << "# h f(x) ABS REL" << std::endl;
  singraph  << "# h f(x) ABS REL" << std::endl;
  for(double i=1;i>1e-10;i/=2)
  {
      dx = deriveDef<double>(15,i,[](double x){ return x*x+3*x; });
      polygraph << std::showpoint << std::fixed << i << " " << dx << " " << relativeError(33.0, dx) << " " << absoluteError(33.0, dx) << " "  << std::endl;

      sindx = deriveDef<double>(1,i,[](double x){ return std::sin(x); });
      singraph << std::showpoint << std::fixed << i << " " << sindx << " " << relativeError(0.54030230586, sindx) << " " << absoluteError(0.54030230586,sindx) << " " << std::endl;
  }
}
