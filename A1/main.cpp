#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  std::cout << "A1 alive!\n";
  point_t pos = {5.0, -9.5};
  Shape* sas = new Rectangle(3.0, 4.0, pos);
  std::cout << "Rectangle area: " << sas->getArea() << std::endl;
  sas->getFrameRect();
  std::cout << "Moving rectangle to point" << std::endl;
  point_t past = {19.0, 84.0};
  sas->move(past);
  std::cout << "Moving rectangle regarding to its position" << std::endl;
  sas->move(1.0, 0.0);
  std::cout << std::endl;
  Shape* sos = new Circle(7.0, pos);
  std::cout << "Circle area: " << sos->getArea() << std::endl;
  sos->getFrameRect();
  std::cout << "Moving circle regarding to its position" << std::endl;
  sos->move(14.0, 93.5);
  std::cout << "Moving circle to point" << std::endl;
  point_t future = {20.0, 84.0};
  sos->move(future);
  delete sas;
  delete sos;
  return 0;
}
