#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double x)
{
	return 1/((1+x)*sqrt(x));
}


double rectangles(double a, double b, double h)
{
	double sum = 0;
	double x;
	

	for(x = a + h * 0.5; x < b; x += h)
		sum += f(x);
	sum *= h;
	
	return sum;
}

int main(int argc, char ** argv)
{  ofstream fout("ans1.dat");
	double a = 0.0, b = 1.0; 
    double h = 0.5; 
	double errrect;
	do {
		double rect = rectangles(a, b, h);
		
		h /= 2;
		
		double divrect = rectangles(a, b, h); 
		
		errrect = abs(rect - divrect)/3.; 
	} while (errrect > 1e-4);
	cout << "Integ=" << rectangles(a, b, h) << " " <<"Error=" << errrect;
	fout << rectangles(a, b, h) << " " << errrect;
    fout.close();
	return 0;
}
