#pragma once
double mapToReal(int x, int imgWidth, double minR, double maxR);
double mapToImaginary(int y, int imgHeight, double minI, double maxI);
int findMandelbrot(double cr, double ci, int maxItr);
