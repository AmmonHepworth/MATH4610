#include<cmath>

template <typename T>
T absoluteError(T exact, T approx)
{
	return std::abs(exact-approx);
}

template <typename T>
T relativeError(T exact, T approx)
{
	return absoluteError<T>(exact,approx) / exact;
}

