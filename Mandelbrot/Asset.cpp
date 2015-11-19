#include "Asset.hpp"

double mapToReal(int x, int imgWidth, double minR, double maxR)
{
	double range = maxR - minR;
	return x * (range / imgWidth) + minR;
}

double mapToImaginary(int y, int imgHeight, double minI, double maxI)
{
	double range = maxI - minI;
	return y * (range / imgHeight) + minI;
}

int findMandelbrot(double cr, double ci, int maxItr)
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
