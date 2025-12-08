#include "util.h"

double clampd(double d, double min, double max)
{
	const double t = d < min ? min : d;
	return t > max ? max : t;
}
