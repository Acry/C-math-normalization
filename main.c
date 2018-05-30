#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Normalization is the process of changing the scale of the data range.
 * 
 * We need to consider...
 * A data set minimum and maximum: 		x_min,x_max
 * A normalized scale minimum and maximum:	r_min, r_max
 * A value in the data set:			x
 * A normalized value: 				xr
 * 
 * -> old value x in new range xr
 * 
 * Solutions:
 * 
 * A
 * with xr = (x - x_min)/ (x_max - x_min);
 * you normalize your x in [0,1].
 * 
 * B
 * with xr = (2 * (x - x_min) / (x_max - x_min)) -1;
 * you normalize your x in [-1,1].
 * 
 * C
 * In general, you can always get a new variable xr in
 * [r_min,r_max] when you provide the Dataset [x_min,x_max]
 *
 * xr = (r_max-r_min) * (x - x_min) / (x_max - x_min) + r_min;
 */

double normalize_A(double);
double normalize_B(double);
double normalize_C(double, double, double, double, double);

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	
	// an RGB value
	int 	g  =127;
	double 	gr;
	
	// normalized to to the range [0][1]
	gr=normalize_A(g);
	printf("gr: %.2f\n",gr);
	
	// 3 OpenGL x-coordinates in screen space value
	// screen width is 800
	int x1, x2, x3;
	x1 	   =   0;
	x2 	   = 400;
	x3 	   = 800;
	double x1r, x2r, x3r;
	x1r=normalize_B(x1);
	x2r=normalize_B(x2);
	x3r=normalize_B(x3);
	
	printf("x1r: %.2f x2r: %.2f x3r: %.2f\n",x1r, x2r, x3r);
	
	gr=normalize_C(g, 0, 255, 0, 1);
	
	printf("gr: %.2f\n",gr);
	
	x1r=normalize_C(x1, 0, 800, -1, 1);
	x2r=normalize_C(x2, 0, 800, -1, 1);
	x3r=normalize_C(x3, 0, 800, -1, 1);
	
	printf("x1r: %.2f x2r: %.2f x3r: %.2f\n",x1r, x2r, x3r);
	
	gr=normalize_C(gr, 0, 1,0 ,255);
	
	printf("gr: %.2f\n",gr);
	return EXIT_SUCCESS;
}

double normalize_A(double x)
{
	// with xr = (x - x_min) / (x_max - x_min);
	// you normalize your x in [0,1].
	
	double xr;
	xr = (x - 0) / (255 - 0);
	return xr;
}

double normalize_B(double x)
{
	// with xr = (2 * (x - x_min) / (x_max - x_min)) -1;
	// you normalize your x in [-1,1].
	
	double xr;
	xr = (2 * (x - 0) / (800 - 0))-1;
	return xr;
}

double normalize_C(double x, double x_min, double x_max, double r_min, double r_max )
{
	// In general, you can always get a new variable xr in
	// [r_min,r_max] when you provide the Dataset [x_min,x_max]

	// xr = (r_max-r_min) * (x - x_min) / (x_max - x_min) + r_min;
	
	double xr;
	xr = (r_max-r_min) * (x - x_min) / (x_max - x_min) + r_min;
	return xr;
}
