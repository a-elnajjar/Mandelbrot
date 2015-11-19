#include<iostream>
#include<fstream>
#include "Asset.hpp"
using namespace std;


int main()
{
	ifstream readFile("input.txt");
	int imgWidth, imgHeight, maxN;
	double minR, maxR, minI, maxI;

	if (!readFile)
	{
		cout << "could't read the file" << endl;
		cin.ignore();
		return 0;
	}

	readFile >> imgWidth >> imgHeight >> maxN;
	readFile >> minR >> maxR >> minI >> maxI;
	readFile.close();

	ofstream writeFile("output_img.ppm");
	writeFile << "P3" << endl;
	writeFile << imgWidth << " " << imgHeight << endl;
	writeFile << "256" << endl;

	for (int y = 0; y < imgHeight; y++)
	{
		for (int x = 0; x < imgWidth; x++)
		{
			double cr = mapToReal(x, imgWidth, minR, maxR);
			double ci = mapToImaginary(y, imgHeight, minI, maxI);

			int n = findMandelbrot(cr, ci, maxN);

			int r = (n % 256);
			int g = (n % 256);
			int b = (n % 256);

			writeFile << r << " " << g << " " << b << " ";
		}
		writeFile << endl;
	}
	writeFile.close();
	cout << "finished " << endl;

	return 0;
}
