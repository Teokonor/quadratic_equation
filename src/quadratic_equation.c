#include "quadratic_equation.h"

static double permissible_error_of_discriminant = DEFAULT_VALUE_OF_permissible_error_of_discriminant;

void change_permissible_error_of_discriminant(double new_value) {
	permissible_error_of_discriminant = new_value;
	if (new_value < 0) {
		permissible_error_of_discriminant = -new_value;
	}
}

complex_pair solve_equation(double a, double b, double c) {
	double firstRe = 0, firstIm = 0, secondRe = 0, secondIm = 0;
	if (isnan(a) || isinf(a) || isnan(b) || isinf(b) || isnan(c) || isinf(c) || (a == 0 && b == 0)) {
		firstRe = NAN;  firstIm = NAN;  secondRe = NAN;  secondIm = NAN;
	}
	else if (a == 0) {
		// Calculations by discriminant consist division into a. If equation is linear, it will be solve here.
		firstRe = (-c) / b;  firstIm = 0.;  secondRe = (-c) / b;  secondIm = 0.;
	}
	else if (c * c <= permissible_error_of_discriminant) {
		// If c and b is very small, discriminant will be considered == 0, and calculated roots will be -b/2a and -b/2a.
		// This block is for such cases
		firstRe = 0.;  firstIm = 0.;  secondRe = (-b) / a;  secondIm = 0.;
	}
	else {
		// This block for default cases when we can calculate discriminant and roots by it
		double discriminant = b * b - 4 * a * c;
		if (discriminant <= permissible_error_of_discriminant && discriminant >= -permissible_error_of_discriminant) {
			firstRe = (-b) / (2 * a); secondRe = firstRe;
		}
		else if (discriminant > 0) {
			firstRe = (-b - sqrt(discriminant)) / (2 * a);
			secondRe = (-b + sqrt(discriminant)) / (2 * a);
		}
		else {
			firstRe = (-b) / (2 * a);
			firstIm = (-sqrt(-discriminant)) / (2 * a);
			secondRe = (-b) / (2 * a);
			secondIm = (sqrt(-discriminant)) / (2 * a);
		}
	}
	if (firstRe > secondRe) {
		double temporary = firstRe; firstRe = secondRe; secondRe = temporary;
		temporary = firstIm; firstIm = secondIm; secondIm = temporary;
	}
	else if (firstRe == secondRe && firstIm > secondIm) {
		double temporary = firstIm; firstIm = secondIm; secondIm = temporary;
	}
	complex_number first = { firstRe, firstIm }, second = { secondRe, secondIm };
	complex_pair pair = { first, second };
	return pair;
}
