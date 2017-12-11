#include "stdafx.h"//

#ifndef EXAM_POINT_11_H
#define EXAM_POINT_11_H

#include <iostream>
using namespace std;

class point_11 {
public:
	point_11(double _x, double _y) :x(_x), y(_y) {}
	virtual void print() { cout << "x: " << x << endl << "y: " << y << endl; }
protected:
	double x, y;
};


class Point_3d_11 : public point_11 {
public:
	Point_3d_11(double _x, double _y, double _z) : point_11(_x, _y) { z = _z; }
	virtual void print() {
		point_11::print();
		cout << "z: " << z << endl;
	}
protected:
	double z;
};
void main()
{
cout <<endl << "=====11.1=====" <<endl;
point_11 j(7.28, 234);
j.print();
cout << endl << "=====11.2=====" <<endl;
Point_3d_11 k(154, 124, 134);
k.print_3d();
cout << endl << "=====11.3=====" << endl;
point_11 *l = new point_11(123, 123);
(*l).print();
cout <<endl << "=====11.4=====" << endl;
Point_3d_11* m = new Point_3d_11(1, 2, 3);
l = new Point_3d_11(234, 234, 234);
l->print();
}
#endif //EXAM_POINT_11_H
