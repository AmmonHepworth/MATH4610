#ifndef MACEPS_H
#define MACEPS_H
template <typename T>
T getMacEps()
{
	T value = 1;
	T litOne = 1.0;
	T litHalf = 0.5;
	int precCount = 0;
	while(litOne + litHalf*value != 1)
	{
		++precCount;
		value *= litHalf;
	}
	return value;
}
	
#endif
