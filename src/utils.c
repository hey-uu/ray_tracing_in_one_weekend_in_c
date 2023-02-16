
#include <limits.h>
#include <math.h>

double	deg_to_rad(double degrees)
{
	return (degrees * M_PI / 180.0);
}

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

// https://svijaykoushik.github.io/blog/2019/10/04/three-awesome-ways-to-generate-random-number-in-javascript/
// https://en.wikipedia.org/wiki/Xorshift

int	xorshift(void)
{
	static int	seed = 1;

	seed ^= seed << 13;
	seed ^= seed >> 17;
	seed ^= seed << 5;
	if (seed < 0)
		return (~seed + 1);
	else
		return (seed);
}

// Returns a random real in [0, 1)
double	random_double(void)
{
	return (xorshift() / (INT_MAX + 1.0));
}

// Returns a random real in [min, max)
double	random_double_interval(double min, double max)
{
	return (min + (max - min) * random_double());
}
