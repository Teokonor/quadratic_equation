#pragma once
#include "complex_number.h"
#include <math.h>

#define DEFAULT_VALUE_OF_permissible_error_of_discriminant 0.0000000001

/* This function change global static variable permissible_error_of_discriminant.
   Default value of permissible_error_of_discriminant is 10^(-10). If discriminant == 0.00000000011, it won't be considered == 0.
   If you want to change that, specify permissible_error_of_discriminant with that function */
void change_permissible_error_of_discriminant(double new_value);

/* Solve equation   a * x ^ 2 + b * x + c = 0   (a or b must be != 0)
   Return pair of complex numbers. If numbers is real, first.Re <= second.Re, else first.Im <= second.Im */
complex_pair solve_equation(double a, double b, double c);