#pragma once
double mapToReal(const int& x,const int& imgWidth, const double& minR, const double& maxR);
double mapToImaginary(const int& y,const int& imgHeight,const double& minI,const double& maxI);
int findMandelbrot(const double& cr,const double& ci,const int& maxItr);
