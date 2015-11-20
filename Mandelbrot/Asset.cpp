#include "Asset.hpp"

double mapToReal(const int& x, const int& imgWidth, const double& minR, const double& maxR)
{
	double range = maxR - minR;
	return x * (range / imgWidth) + minR;
}

double mapToImaginary(const int& y, const int& imgHeight, const double& minI, const double& maxI)
{
	double range = maxI - minI;
	return y * (range / imgHeight) + minI;
}

int findMandelbrot(const double& cr, const double& ci, const int& maxItr)
{
	int i = 0;
	double zr = 0.0, zi = 0.0;
	while (i < maxItr && zr * zr + zi * zi < 4.0)
	{
		double temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return i;
}
