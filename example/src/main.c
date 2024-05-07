#include "quadratic_equation.h"
#include <stdio.h>

int main() {
	while (1) {
		printf("Solving equation  ax^2 + bx + c = 0\nPlease, enter numbers a, b, c: ");
		double a = 0, b = 0, c = 0;
		scanf("%lf", &a);
		scanf("%lf", &b);
		scanf("%lf", &c);
		complex_pair result = solve_equation(a, b, c);
		if (result.first.Im == 0) {
			printf("\nRoots: %.10g, %.10g\n\n\n", result.first.Re, result.second.Re);
		}
		else {
			printf("\nRoots: %.10g+(%.10g)i, %.10g+(%.10g)i\n\n\n", result.first.Re, result.first.Im, result.second.Re, result.second.Im);
		}
	}
}