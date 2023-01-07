#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
// Datentyp Complex in der Datei canvas.hh
#include "canvas.hh"

// Summiert zwei komplexe Zahlen z und c und schreibt das Ergebnis in z
void add_complex( Complex& z, Complex c )
{z.real += c. real;
	z.imag += c.imag;
}

// Multipliziert zwei komplexe Zahlen z und c und schreibt das Ergebnis in z
void multiply_complex( Complex& z, Complex c)
{Complex buffer;
	buffer.real = (z.real * c.real - z.imag * c.imag);
	buffer.imag = (z.real * c.imag + c.real * z.imag);
	z = buffer;
}

// Betrag einer komplexen Zahl
double betrag(Complex z)
{
	return (std::sqrt((z.real*z.real) + (z.imag*z.imag)) );
	// TODO Nutzen Sie std::sqrt zur Wurzelberechnung
}

// TODO Funktion mandelbrot()
void mandelbrot(Canvas& canvas, double threshold, int maxIt, std::string filename) {

	int counter = 0;
			for (int i = 0;i<canvas.vertPixels();i++) {
		for (int j = 0;j<canvas.horPixels();j++) {
			Complex c = canvas.coord(j,i);
			Complex z;
			counter = 0;
			z.real = 0;
			z.imag = 0;
			while(counter < maxIt) {
				multiply_complex(z,z);
				add_complex(z,c);
				//std::cout << z.real << " " << z.imag << std::endl;
				counter++;
				if(betrag(z) > threshold) {
					break;
				}
			}
			if (betrag(z) <= threshold){
				//canvas.writePixel(i,j,0);
				std::cout << 0 << " ";
			} else {
				std::cout <<  (int)( std::log(counter) * 100) << " ";
				//canvas.writePixel(i,j,(std::log(counter) * 100));
			}
			//std::cout <<"Value und Pixel: " << " " << i  << "," << j << std::endl;
		}
		std::cout << std::endl;
	}
		//std::cout << "Beginne bild malen: " << std::endl;
		//canvas.write(filename);

}
int main()
{
	std::cout << "P2" << std::endl;
	std::cout << 10000  << " " << 8000 << std::endl;
	std::cout << 852 << std::endl;
	Canvas canvas(-1,0, 5,4, 10000,8000);
	mandelbrot(canvas, 100000, 5000, "mandelbrot.pgm");
	return(0);
}
