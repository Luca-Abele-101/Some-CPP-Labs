#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
using namespace lutsaj;
using ShapePtr = std::shared_ptr < lutsaj::Shape >;

int main()
{
  std::cout << "A3 alive!\n";
  using CmpShapePtr = std::shared_ptr< CompositeShape >;
  point_t posRectangle = {5.0, 5.0};
  point_t posCircle = {8.5, -9.0};
  const int shapesSize = 3;
  CompositeShape::ArrayType shapes = std::make_unique< Shape::ShapePtr[] >(shapesSize);
  shapes[0] = std::make_shared< Rectangle >(2.0, 4.0, posRectangle);
  shapes[1] = std::make_shared< Circle >(3.5, posCircle);
  CmpShapePtr cmpShp(std::make_shared< CompositeShape >(shapes[0]));
  cmpShp->addShape(shapes[1]);
  shapes[2] = cmpShp;
  std::cout << "\nScaling Shapes\n";
  for (int i = 0; i < shapesSize; i++)
  {
    shapes[i]->scale(2);
  }
  std::cout << "\nMoving Shapes\n";
  for (int i = 0; i < shapesSize; i++)
  {
    shapes[i]->move(7.0, 6.0);
  }
  return 0;
}
