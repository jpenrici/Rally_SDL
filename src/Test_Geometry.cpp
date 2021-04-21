/*
 *   Compile:
 *      g++ Test_Vector2D.cpp -o Test_Vector2D
 *
 *   Run:
 *      ./Test_Vector2D
*/
#include "Geometry.h"
#include <iostream>
#include <cassert>

int main(int argc, char const *argv[])
{
	
	Vector2D v1;
	Vector2D v2(1, 1);
	Vector2D v3(2, 2);

	v1.show();
	v2.show();

	v1 = v2;
	v1.show();

	v1 = v2 + v3;
	v1.show();

	Vector2D v4(10, 10);
	v4.show();
	
	cout << "Test Rectangle.contain(point) ... ";
	
	Rectangle r1(v4, 40, 90);
	assert(r1.area() == (40 * 90));
	assert(r1.contains(Vector2D()) == false);
	assert(r1.contains(Vector2D(10, 10)) == true);
	assert(r1.contains(Vector2D(10, 100))== true);
	assert(r1.contains(Vector2D(50, 10)) == true);
	assert(r1.contains(Vector2D(50, 100))== true);
	assert(r1.contains(Vector2D(50, 100))== true);
	assert(r1.contains(Vector2D(15, 20)) == true);
	assert(r1.contains(Vector2D(55, 20)) == false);

	Rectangle r2(v4, -20, 20);
	assert(r2.area() == -1);					// Error: area < 0
	assert(r2.contains(Vector2D()) == false);	// Error: w < 0 or h < 0

	Vector2D v5 = v4 + Vector2D(-20, -20);
	assert(v5.getX() == -10);
	assert(v5.getY() == -10);

	Rectangle r3(v5, 20, 20);
	assert(r3.area() == 400);
	assert(r3.contains(Vector2D()) == true);
	assert(r3.contains(Vector2D(10, 10)) == true);

	cout << "Finished\n";

	return 0;
}