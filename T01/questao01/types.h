#ifndef TYPES_H
#define TYPES_H

struct _Dot{
	double x;
	double y;
};
typedef struct _Dot Dot;

struct _Quadrilateral{
	Dot one;
	Dot two;
	Dot tree;
	Dot four;
};
typedef struct _Quadrilateral Quadrilateral;

#endif
