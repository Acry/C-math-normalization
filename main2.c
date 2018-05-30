#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Switching back to the dataset range.
 * 
 * With the function named normalize_C one can switch back and forth
 * between scales.
 * 
 * Function A and B are different
 * 
 * To switch back to the dataset range
 * -> new range value xr to the dataset range value or scaling
 * 
 * Solutions:
 * 
 * A
 * with x = xr * x_max;
 * you renormalize your x back to [0,x_max].
 * 
 * B
 * with x = x_max * (xr - r_min) / (r_max - r_min);
 * you renormalize your x back to [0,x_max].
 */

double normalize_A(double);
double normalize_B(double);

double back_A(double);
double back_B(double);

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	
	// an RGB value
	int 	g  =127;
	printf("g:%d\n",g);
	double 	gr;
	
	// normalized to to the range [0][1]
	gr=normalize_A(g);
	printf("gr:%.2f\n",gr);
	int g2;
	g2=roundf(back_A(gr));
	printf("g2:%d\n",g2);

	// 3 OpenGL x-coordinates in screen space value
	// screen width is 800
	int x1, x2, x3;
	x1 	   =   0;
	x2 	   = 400;
	x3 	   = 800;
	printf("x1:%d x2:%d x3:%d\n",x1, x2, x3);
	
	double x1r, x2r, x3r;
	x1r=normalize_B(x1);
	x2r=normalize_B(x2);
	x3r=normalize_B(x3);
	printf("x1r:%.2f x2r:%.2f x3r:%.2f\n",x1r, x2r, x3r);
	
	int xa1, xa2, xa3;
	xa1=roundf(back_B(x1r));
	xa2=roundf(back_B(x2r));
	xa3=roundf(back_B(x3r));
	printf("xa1:%d xa2:%d xa3:%d\n",xa1, xa2, xa3);
	return EXIT_SUCCESS;
}

double normalize_A(double x)
{
	return (x - 0) / (255 - 0);
}

double normalize_B(double x)
{
	return (2 * (x - 0) / (800 - 0))-1;
}


double back_A(double xr)
{

	// renormalize x in range of [0,255].
	// was normalized [0,1].

	// xr * x_max
	double x_max=255;
	double x;
	x = xr * x_max;
	return x;
}

double back_B(double xr)
{
	// renormalize x in range of [0,800].
	// was normalized [-1,1].
	
	// Since the normalized value was in the range
	// between -1 to 1 it is not as simple as back_A
	
	// Equation was:
	// xr = (r_max-r_min) * (x - x_min) / (x_max - x_min) + r_min;
	// switching r range with x range

	// flipped back it is:
	// x = (x_max-x_min) * (xr - r_min) / (r_max - r_min) + x_min;
	double x, x_max=800, x_min=0, r_min=-1, r_max=1;

	// x_min is 0, so remove it to simplify the equation.
	(void)x_min;
	x = x_max * (xr - r_min) / (r_max - r_min);
	return x;
}


