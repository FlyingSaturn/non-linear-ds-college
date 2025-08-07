#define _USE_MATH_DEFINESS
#include <stdio.h>
#include <math.h>

void generate_hehehe(double amp, int steps, int cyc);
double calc_point(double theta, double amp);
double cycle_detector(double theta);
double increment(double theta, int step);

int cycles = 1;

int main(void)
{
	double amp;
	const int steps = 30;
	int cycl;
	printf("A: ");
	scanf("%lf", &amp);
	printf("Cycles: ");
	scanf("%d", &cycl);
	generate_hehehe(amp, steps, cycl);
}

void generate_hehehe(double amp, int steps, int cyc)
{
	double theta = 0;
	while (cycles <= cyc)
	{
		double point = calc_point(theta, amp);
		for (double i = -amp; i <= point; i += 1)
			printf(" ");
		printf("*\n");
		theta = increment(theta, steps);
	}
}

double calc_point(double theta, double amp)
{
	return amp * sin(theta);
}

// Make a new_theta angle, then check if they are equal,
// then increase cycles
double cycle_detector(double theta)
{
	if (theta >= 2 * M_PI)
		theta -= 2 * M_PI;
	return theta;
}

double increment(double theta, int step)
{
	double freq = (2 * M_PI) / step;
	theta += freq;
	double new_theta = cycle_detector(theta);
	if (theta != new_theta)
		cycles++;
	theta = new_theta;
	return theta;
}
