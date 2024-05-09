#include "quadratic_equation.h"
#include <stdio.h>
#include <string.h>

int main() {
	while (1) {
		char input[990];
		printf("Solving equation  ax^2 + bx + c = 0\nPlease, enter numbers a b c separated by comma\nYou can enter 'exit' to stop the program.\n");
		double a = 0, b = 0, c = 0;
		fgets(input, sizeof(input), stdin);
		if (strcmp(input, "exit\n") == 0 || strcmp(input, "exit") == 0) {
			break;
		}
		int k = sscanf(input, "%lf , %lf , %lf", &a, &b, &c);
		if (k == 3) {
			complex_pair result = solve_equation(a, b, c);
			if (result.first.Im == 0) {
				printf("\nRoots: %.10g, %.10g\n\n\n", result.first.Re, result.second.Re);
			}
			else {
				printf("\nRoots: %.10g+(%.10g)i, %.10g+(%.10g)i\n\n\n", result.first.Re, result.first.Im, result.second.Re, result.second.Im);
			}
		}
		else {
			printf("\nInput is incorrect. Try again.\n\n\n");
		}
	}
	return 0;
}
