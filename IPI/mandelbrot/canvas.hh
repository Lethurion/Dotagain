
#include <string>
#include "pgm.hh"

struct Complex
{
  double real;
  double imag;
};

class Canvas
{
public :
  // Konstruktor, erzeuge int* _pixels
  Canvas(double center_x, double center_y,
         double width, double height,
         int horPixels, int vertPixels);

  // Desktruktor, raeume int* _pixels auf
  // ~Canvas();

  // gibt die Breite des Bildes zurueck
  double width();

  // gibt die Hoehe des Bildes zurueck
  double height();

  // gibt die Anzahl an horizontalen Pixeln
  int horPixels();

  // gibt die Anzahl an vertikalen Pixeln
  int vertPixels();

  // gebe die Koordinaten des Pixels (i,j) als Complex zurueck
  Complex coord(int i, int j);

  // schreibe value an den Pixel (i,j)
  // Ueberlegen Sie wie aus (i,j) den flachen Index bei row-major bekommen
  void writePixel(int i, int j, int value);

  // Zugang zum Pixel (i,j) im 1D Array
  // Ueberlegen Sie wie aus (i,j) den flachen Index bei row-major bekommen
  int operator()(int i, int j);

  void Pixelcleaner();
  // schreibe Bild mit Dateinamen filename
  void write(std::string filename);
private :
  double _center_x;
  double _center_y;
  double _width;
  double _height;
  int _horPixels;
  int _vertPixels;
  int* _pixels;
};

// diese Methode ist bereits implementiert
void Canvas::write(std::string filename)
{
  write_pgm(_pixels,_horPixels,_vertPixels,filename);
}
double Canvas::width() {
  return(_width);
}

double Canvas::height() {
  return(_height);
}

int Canvas::horPixels() {
  return(_horPixels);
}

int Canvas::vertPixels() {
  return(_vertPixels);
}

Complex Canvas::coord(int i, int j) {
  Complex Koordinate;
  Koordinate.real =    0 - _width/2 + _center_x +  ((_height/_vertPixels)* i);
  Koordinate.imag =  0 -_height/2 + _center_y + (_width/_horPixels) * j;
  return(Koordinate);
}

int Canvas::operator()(int i, int j) {
  return( _vertPixels * i + j );
}
void Canvas::writePixel(int i, int j, int value) {
  //Diese Funktion ruft nach dem 360 mal eine Segfault herfor. Ist der Canvas insgesamt kleiner als 360 pixel, laeuft all
  //es ohne probleme.
  int Dimens = (i * _vertPixels) + j;
  _pixels[Dimens] = value;
 // std::cout << Dimens << std::endl;
}

Canvas::Canvas(double center_x, double center_y,
               double width, double height,
               int horPixels, int vertPixels) {
  _center_x = center_x;
  _center_y = center_y;
  _width = width;
  _height = height;
  _horPixels = horPixels;
  _vertPixels = vertPixels;
  //  for(int i = 0; i < horPixels * vertPixels; i++)
  //  _pixels[i] = 0;
}

