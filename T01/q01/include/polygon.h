#ifndef POLYGON_H
#define POLYGON_H

typedef struct _Dot {
	double x;
	double y;
}Dot;

typedef struct _Quadrilateral _Quadrilateral, Quadrilateral;
struct _Quadrilateral {
	Dot *dots;
	int numOfDots;
	int maxDots;

	int (*push)(Quadrilateral**, Dot*);

};

int init_quadrilateral(Quadrilateral **self);

int quadrilateral_push(Quadrilateral **self, Dot *dot);
Dot * newDot(double x, double y);
#endif
