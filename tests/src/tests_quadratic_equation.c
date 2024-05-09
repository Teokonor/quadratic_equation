#include "tests_quadratic_equation.h"
#include "tests_interface.h"
#include "quadratic_equation.h"
#include <float.h>
#include <wchar.h>


const double permissible_error = 0.00001;
int equal(double first, double second) {
	return (first - second <= permissible_error && first - second >= -permissible_error);
}


#define SOLVE_AND_CHECK_NAN(a, b, c) {																	\
	complex_pair res = solve_equation(NAN, 0, 0);														\
	ASSERT(isnan(res.first.Re) && isnan(res.first.Im) && isnan(res.second.Re) && isnan(res.second.Im));	\
	}


#define EQUAL_COMPLEX_PAIRS(res, expected_res)																\
	(equal((res).first.Re, (expected_res).first.Re)  &&  equal((res).first.Im, (expected_res).first.Im)  &&	\
	equal((res).second.Re, (expected_res).second.Re)  &&  equal((res).second.Im, (expected_res).second.Im))	\


#define SOLVE_AND_COMPARE(a, b, c, expected_1_Re, expected_1_Im, expected_2_Re, expected_2_Im){					\
	complex_pair expected_res = { { (expected_1_Re), (expected_1_Im) }, { (expected_2_Re), (expected_2_Im) } },	\
		res = solve_equation((a), (b), (c));																	\
	ASSERT(EQUAL_COMPLEX_PAIRS(res, expected_res))																\
	}


#define ROOTS_ARE_IDENTICAL(_res) ((_res).first.Re == (_res).second.Re && (_res).first.Im == (_res).second.Im)







BEGIN_TEST(NAN_a)
{
	SOLVE_AND_CHECK_NAN(NAN, 0, 0);
	SOLVE_AND_CHECK_NAN(NAN, 1, 1);
	SOLVE_AND_CHECK_NAN(NAN, -14.869, 56784);
	SOLVE_AND_CHECK_NAN(NAN, 5.9191, -12345);
}
END_TEST

BEGIN_TEST(NAN_b)
{
	SOLVE_AND_CHECK_NAN(0, NAN, 0);
	SOLVE_AND_CHECK_NAN(1.00000, NAN, 1);
	SOLVE_AND_CHECK_NAN(-432890.643582, NAN, 99.0000000);
	SOLVE_AND_CHECK_NAN(0.0000001, NAN, -0.0000001);
}
END_TEST

BEGIN_TEST(NAN_c)
{
	SOLVE_AND_CHECK_NAN(0, 0, NAN);
	SOLVE_AND_CHECK_NAN(1., 1., NAN);
	SOLVE_AND_CHECK_NAN(94.5, -0.00000863746387493343567865, NAN);
	SOLVE_AND_CHECK_NAN(9384753984759847539487593847598374, 0.8, NAN);
}
END_TEST

BEGIN_TEST(Inf_a)
{
	SOLVE_AND_CHECK_NAN(INFINITY, -0, -0.000000);
	SOLVE_AND_CHECK_NAN(INFINITY, -1., -1);
	SOLVE_AND_CHECK_NAN(INFINITY, 0.00000863746387493343567865, -99.0000000);
	SOLVE_AND_CHECK_NAN(INFINITY, -0.8, 0.0000001);
}
END_TEST

BEGIN_TEST(Inf_b)
{
	SOLVE_AND_CHECK_NAN(0, INFINITY, 0);
	SOLVE_AND_CHECK_NAN(-1., INFINITY, -1);
	SOLVE_AND_CHECK_NAN(94.5, INFINITY, -56784);
	SOLVE_AND_CHECK_NAN(-9384753984759847539487593847598374, INFINITY, 12345);
}
END_TEST

BEGIN_TEST(Inf_c)
{
	SOLVE_AND_CHECK_NAN(-0., -0, INFINITY);
	SOLVE_AND_CHECK_NAN(-1.00000, -1, INFINITY);
	SOLVE_AND_CHECK_NAN(-432890.643582, 14.869, INFINITY);
	SOLVE_AND_CHECK_NAN(-0.0000001, -5.9191, INFINITY);
}
END_TEST

BEGIN_TEST(Inf_a_Inf_b)
{
	SOLVE_AND_CHECK_NAN(-INFINITY, -INFINITY, 0.);
	SOLVE_AND_CHECK_NAN(INFINITY., INFINITY, -1);
	SOLVE_AND_CHECK_NAN(INFINITY, -INFINITY, -56784);
	SOLVE_AND_CHECK_NAN(-INFINITY, INFINITY, 18.10009);
}
END_TEST

BEGIN_TEST(NAN_b_NAN_c)
{
	SOLVE_AND_CHECK_NAN(0, -NAN, NAN);
	SOLVE_AND_CHECK_NAN(1.00000, NAN, -NAN);
	SOLVE_AND_CHECK_NAN(432890.643582, -NAN, -NAN);
	SOLVE_AND_CHECK_NAN(-0.0000001, NAN, -NAN);
}
END_TEST

BEGIN_TEST(NAN_a_Inf_c)
{
	SOLVE_AND_CHECK_NAN(NAN, -0, INFINITY);
	SOLVE_AND_CHECK_NAN(-NAN, 1, -INFINITY);
	SOLVE_AND_CHECK_NAN(-NAN, 143.869, INFINITY);
	SOLVE_AND_CHECK_NAN(NAN, -55569.9191, -INFINITY);
}
END_TEST

BEGIN_TEST(Every_NAN_or_Inf)
{
	SOLVE_AND_CHECK_NAN(NAN, -NAN, NAN);
	SOLVE_AND_CHECK_NAN(-INFINITY, INFINITY, INFINITY);
}
END_TEST

BEGIN_TEST(Every_nulls)
{
	SOLVE_AND_CHECK_NAN(0, 0, 0);
	SOLVE_AND_CHECK_NAN(0., 0, 0.);
	SOLVE_AND_CHECK_NAN(0, 0.00000000000000000000000000000000000000000000, 0);
	SOLVE_AND_CHECK_NAN(0.00, 0.00, 0.00);
}
END_TEST

BEGIN_TEST(a_and_b_nulls)
{
	SOLVE_AND_CHECK_NAN(0, 0, -4);
	SOLVE_AND_CHECK_NAN(0., 0, 121.);
	SOLVE_AND_CHECK_NAN(0, 0.00000000000000000000000000000000000000000000, 46384782);
	SOLVE_AND_CHECK_NAN(0.00, 0.00, -412.56);
}
END_TEST

BEGIN_GROUP(Invalid_inputs)
ADD_TEST(NAN_a)
ADD_TEST(NAN_b)
ADD_TEST(NAN_c)
ADD_TEST(Inf_a)
ADD_TEST(Inf_b)
ADD_TEST(Inf_c)
ADD_TEST(Inf_a_Inf_b)
ADD_TEST(NAN_b_NAN_c)
ADD_TEST(NAN_a_Inf_c)
ADD_TEST(Every_NAN_or_Inf)
ADD_TEST(Every_nulls)
ADD_TEST(a_and_b_nulls)
END_GROUP





BEGIN_TEST(a_and_c_is_null)
{
	SOLVE_AND_COMPARE(0, -564, 0, 0, 0, 0, 0);
	SOLVE_AND_COMPARE(0, 0.063986583720957, 0, 0, 0, 0, 0);
}
END_TEST

BEGIN_TEST(a_is_null)
{
	SOLVE_AND_COMPARE(0, 10, 13, -1.3, 0, -1.3, 0);
	SOLVE_AND_COMPARE(0, -23, 12096, 525.91304, 0, 525.91304, 0);
	SOLVE_AND_COMPARE(0, -93450.181828, -71.043815, -0.00076, 0, -0.00076, 0);
	SOLVE_AND_COMPARE(-000000.000000000, -00000093450.1818280000000000, -00000071.043815000000000, -0.00076, 0, -0.00076, 0);
	SOLVE_AND_COMPARE(0, 0.003487162, -195.9, 56177.4876, 0, 56177.4876, 0);
}
END_TEST

BEGIN_TEST(b_and_c_is_null)
{
	SOLVE_AND_COMPARE(-564, 0, 0, 0, 0, 0, 0);
	SOLVE_AND_COMPARE(0.063986583720957, 0., 0.0, 0, 0, 0, 0);
}
END_TEST

BEGIN_TEST(equal_int_roots)
{
	SOLVE_AND_COMPARE(1, -2, 1, 1, 0, 1, 0);
	SOLVE_AND_COMPARE(-284, 568, -284, 1, 0, 1, 0);

	SOLVE_AND_COMPARE(1, 12, 36, -6, 0, -6, 0);
	SOLVE_AND_COMPARE(5, 60, 180, -6, 0, -6, 0);

	SOLVE_AND_COMPARE(1, -1710, 731025, 855, 0, 855, 0);
	SOLVE_AND_COMPARE(0.549, -938.79, 401332.725, 855, 0, 855, 0);

	SOLVE_AND_COMPARE(1, -7000000, 12250000000000, 3500000, 0, 3500000, 0);
	SOLVE_AND_COMPARE(10000, -70000000000, 122500000000000000, 3500000, 0, 3500000, 0);
	SOLVE_AND_COMPARE(1, 7000000, 12250000000000, -3500000, 0, -3500000, 0);
	SOLVE_AND_COMPARE(10000, 70000000000, 122500000000000000, -3500000, 0, -3500000, 0);
}
END_TEST

BEGIN_TEST(equal_positive_non_int_roots)
{
	SOLVE_AND_COMPARE(1, -1051.82608, 276584.5256420416, 525.91304, 0, 525.91304, 0);
	SOLVE_AND_COMPARE(-50, 52591.304, -13829226.28210208, 525.91304, 0, 525.91304, 0);

	SOLVE_AND_COMPARE(1, -0.00762, 0.0000145161, 0.00381, 0, 0.00381, 0);
	SOLVE_AND_COMPARE(86, -0.65532, 0.0012483846, 0.00381, 0, 0.00381, 0);

	SOLVE_AND_COMPARE(1, -82.36, 1695.7924, 41.18, 0, 41.18, 0);
	SOLVE_AND_COMPARE(2.9371, -241.899556, 4980.71185804, 41.18, 0, 41.18, 0);
}
END_TEST

BEGIN_TEST(equal_negative_non_int_roots)
{
	SOLVE_AND_COMPARE(1, 2.6, 1.69, -1.3, 0, -1.3, 0);
	SOLVE_AND_COMPARE(481.00652, 1250.616952, 812.9010188, -1.3, 0, -1.3, 0);

	SOLVE_AND_COMPARE(1, 0.00762, 0.0000145161, -0.00381, 0, -0.00381, 0);
	SOLVE_AND_COMPARE(86, 0.65532, 0.0012483846, -0.00381, 0, -0.00381, 0);

	SOLVE_AND_COMPARE(1, 82.36, 1695.7924, -41.18, 0, -41.18, 0);
	SOLVE_AND_COMPARE(2.9371, 241.899556, 4980.71185804, -41.18, 0, -41.18, 0);
}
END_TEST

BEGIN_GROUP(Equal_roots)
ADD_TEST(a_and_c_is_null)
ADD_TEST(a_is_null)
ADD_TEST(b_and_c_is_null)
ADD_TEST(equal_int_roots)
ADD_TEST(equal_positive_non_int_roots)
ADD_TEST(equal_negative_non_int_roots)
END_GROUP





BEGIN_TEST(Permissible_errors_of_discriminant_less_default)
{
	// Default 0.0000000001
	complex_pair res = solve_equation(1, -0.1, 0.002500000025);
	ASSERT(ROOTS_ARE_IDENTICAL(res));
	res = solve_equation(1, -0.1, 0.0025000000250001);
	ASSERT(!ROOTS_ARE_IDENTICAL(res));

	change_permissible_error_of_discriminant(-0.000000000001);
	res = solve_equation(1, -0.01, 0.00002500000025);
	ASSERT(ROOTS_ARE_IDENTICAL(res));
	res = solve_equation(1, -0.01, 0.000025000000250001);
	ASSERT(!ROOTS_ARE_IDENTICAL(res));

	change_permissible_error_of_discriminant(0.000000000000100000001);
	res = solve_equation(1, -0.01, 0.000025000000025);
	ASSERT(ROOTS_ARE_IDENTICAL(res));
	res = solve_equation(1, -0.01, 0.00002500000002500001);
	ASSERT(!ROOTS_ARE_IDENTICAL(res));

	change_permissible_error_of_discriminant(-0.0000000000004);
	res = solve_equation(1, -0.01, 0.0000250000001);
	ASSERT(ROOTS_ARE_IDENTICAL(res));
	res = solve_equation(1, -0.01, 0.000025000000100001);
	ASSERT(!ROOTS_ARE_IDENTICAL(res));

	change_permissible_error_of_discriminant(DEFAULT_VALUE_OF_permissible_error_of_discriminant);
}
END_TEST

BEGIN_TEST(Permissible_errors_of_discriminant_more_default_less_1)
{
	change_permissible_error_of_discriminant(0.00000001);
	complex_pair res = solve_equation(1, -0.1, 0.0025000025);
	ASSERT(ROOTS_ARE_IDENTICAL(res));
	res = solve_equation(1, -0.1, 0.0025000025001);
	ASSERT(!ROOTS_ARE_IDENTICAL(res));

	change_permissible_error_of_discriminant(-0.001);
	res = solve_equation(1, -10, 25.00024999);
	ASSERT(ROOTS_ARE_IDENTICAL(res));
	res = solve_equation(1, -10, 25.00025);
	ASSERT(!ROOTS_ARE_IDENTICAL(res));

	change_permissible_error_of_discriminant(0.55874836832);
	res = solve_equation(1, -10, 25.1);
	ASSERT(ROOTS_ARE_IDENTICAL(res));
	res = solve_equation(1, -10, 25.2);
	ASSERT(!ROOTS_ARE_IDENTICAL(res));

	change_permissible_error_of_discriminant(DEFAULT_VALUE_OF_permissible_error_of_discriminant);
}
END_TEST

BEGIN_TEST(Permissible_errors_of_discriminant_1_or_more)
{
	change_permissible_error_of_discriminant(1);
	complex_pair res = solve_equation(1, -10, 25.25);
	ASSERT(ROOTS_ARE_IDENTICAL(res));
	res = solve_equation(1, -10, 25.26);
	ASSERT(!ROOTS_ARE_IDENTICAL(res));

	change_permissible_error_of_discriminant(12345.11194);
	res = solve_equation(1, -10000, 25003086);
	ASSERT(ROOTS_ARE_IDENTICAL(res));
	res = solve_equation(1, -10000, 25003087);
	ASSERT(!ROOTS_ARE_IDENTICAL(res));

	change_permissible_error_of_discriminant(DEFAULT_VALUE_OF_permissible_error_of_discriminant);
}
END_TEST

BEGIN_GROUP(Different_permissible_errors_of_discriminant)
ADD_TEST(Permissible_errors_of_discriminant_less_default)
ADD_TEST(Permissible_errors_of_discriminant_more_default_less_1)
ADD_TEST(Permissible_errors_of_discriminant_1_or_more)
END_GROUP





BEGIN_TEST(b_is_null_real_roots)
{
	SOLVE_AND_COMPARE(1, 0, -24.6, -sqrt(24.6), 0, sqrt(24.6), 0);
	SOLVE_AND_COMPARE(259.18, 0, -24.6, -sqrt(24.6 / 259.18), 0, sqrt(24.6 / 259.18), 0);
	SOLVE_AND_COMPARE(-259.18, 0, 24.6, -sqrt(24.6 / 259.18), 0, sqrt(24.6 / 259.18), 0);
	SOLVE_AND_COMPARE(-5, 0, 94761723843, -sqrt(94761723843 / 5), 0, sqrt(94761723843 / 5), 0);
	SOLVE_AND_COMPARE(5, 0, -0.000010000543, -sqrt(0.000010000543 / 5), 0, sqrt(0.000010000543 / 5), 0);
}
END_TEST

BEGIN_TEST(c_is_null)
{
	SOLVE_AND_COMPARE(1, -18.032, 0, 0, 0, 18.032, 0);
	SOLVE_AND_COMPARE(1, 18.032, 0, -18.032, 0, 0, 0);
	SOLVE_AND_COMPARE(1, 18.032, 0, -18.032, 0, 0, 0.00000000000000000000000001);
	SOLVE_AND_COMPARE(125.521, -0.16, 0, 0, 0, 0.16 / 125.521, 0);
	SOLVE_AND_COMPARE(0.00000000000000000000000000000000000000000000000000000000000000232434, 0.000000000000000000000000000000000000000000000000000000000000007576, 0, -3.25942, 0, 0, 0);
	SOLVE_AND_COMPARE(-0.00000000000000000000000000000000000000000000000000000000000000232434, 0.000000000000000000000000000000000000000000000000000000000000007576, 
		0.0000000000000000000000000008756, 0, 0, 3.25942, 0);
}
END_TEST

BEGIN_TEST(No_null_args_real_roots_1)
{
	SOLVE_AND_COMPARE(1, 5, 6, -3, 0, -2, 0);
	SOLVE_AND_COMPARE(-1, -5, -6, -3, 0, -2, 0);
	SOLVE_AND_COMPARE(1, -5, 6, 2, 0, 3, 0);
	SOLVE_AND_COMPARE(-1, 5, -6, 2, 0, 3, 0);
	SOLVE_AND_COMPARE(1, -5, -6, -1, 0, 6, 0);
	SOLVE_AND_COMPARE(-1, 5, 6, -1, 0, 6, 0);
	SOLVE_AND_COMPARE(12.4, -62, -74.4, -1, 0, 6, 0);
}
END_TEST

BEGIN_TEST(No_null_args_real_roots_2)
{
	SOLVE_AND_COMPARE(18.70056, 0.02365, -9, -0.69437, 0, 0.69310, 0);
	SOLVE_AND_COMPARE(-18.70056, -0.02365, 9, -0.69437, 0, 0.69310, 0);
	SOLVE_AND_COMPARE(18.70056, -0.02365, -9, -0.69310, 0, 0.69437, 0);
	SOLVE_AND_COMPARE(-18.70056, 0.02365, 9, -0.69310, 0, 0.69437, 0);
}
END_TEST

BEGIN_TEST(No_null_args_real_roots_3)
{
	SOLVE_AND_COMPARE(579374.34, 2343345.218, 0823465.001, -3.65584, 0, -0.388776, 0);
	SOLVE_AND_COMPARE(-579374.34, -2343345.218, -0823465.001, -3.65584, 0, -0.388776, 0);
	SOLVE_AND_COMPARE(579374.34, 2343345.218, -0823465.001, -4.36986, 0, 0.325251, 0);
	SOLVE_AND_COMPARE(-579374.34, -2343345.218, 0823465.001, -4.36986, 0, 0.325251, 0);
	SOLVE_AND_COMPARE(579374.34, -2343345.218, 0823465.001, 0.388776, 0, 3.65584, 0);
	SOLVE_AND_COMPARE(-579374.34, 2343345.218, -0823465.001, 0.388776, 0, 3.65584, 0);
	SOLVE_AND_COMPARE(579374.34, -2343345.218, -0823465.001, -0.325251, 0, 4.36986, 0);
	SOLVE_AND_COMPARE(-579374.34, 2343345.218, 0823465.001, -0.325251, 0, 4.36986, 0);
}
END_TEST

BEGIN_GROUP(Different_real_roots)
ADD_TEST(b_is_null_real_roots)
ADD_TEST(c_is_null)
ADD_TEST(No_null_args_real_roots_1)
ADD_TEST(No_null_args_real_roots_2)
ADD_TEST(No_null_args_real_roots_3)
END_GROUP





BEGIN_TEST(b_is_null_imaginary_roots)
{
	SOLVE_AND_COMPARE(1, 0, 24.6, 0, -sqrt(24.6), 0, sqrt(24.6));
	SOLVE_AND_COMPARE(259.18, 0, 24.6, 0, -sqrt(24.6 / 259.18), 0, sqrt(24.6 / 259.18));
	SOLVE_AND_COMPARE(-259.18, 0, -24.6, 0, -sqrt(24.6 / 259.18), 0, sqrt(24.6 / 259.18));
	SOLVE_AND_COMPARE(5, 0, 94761723843, 0, -sqrt(94761723843 / 5), 0, sqrt(94761723843 / 5));
	SOLVE_AND_COMPARE(-5, 0, -0.000010000543, 0, -sqrt(0.000010000543 / 5), 0, sqrt(0.000010000543 / 5));
}
END_TEST

BEGIN_TEST(No_null_args_complex_roots_1)
{
	SOLVE_AND_COMPARE(1, 8, 17, -4, -1, -4, 1);
	SOLVE_AND_COMPARE(-1, -8, -17, -4, -1, -4, 1);
	SOLVE_AND_COMPARE(1, -8, 17, 4, -1, 4, 1);
	SOLVE_AND_COMPARE(-1, 8, -17, 4, -1, 4, 1);
	SOLVE_AND_COMPARE(-118.57, 948.56, -2015.69, 4, -1, 4, 1);
}
END_TEST

BEGIN_TEST(No_null_args_complex_roots_2)
{
	SOLVE_AND_COMPARE(18.70056, 0.02365, 9, -0.00063, -0.69374, -0.00063, 0.69374);
	SOLVE_AND_COMPARE(-18.70056, -0.02365, -9, -0.00063, -0.69374, -0.00063, 0.69374);
	SOLVE_AND_COMPARE(18.70056, -0.02365, 9, 0.00063, -0.69374, 0.00063, 0.69374);
	SOLVE_AND_COMPARE(-18.70056, 0.02365, -9, 0.00063, -0.69374, 0.00063, 0.69374);
}
END_TEST

BEGIN_TEST(No_null_args_complex_roots_3)
{
	SOLVE_AND_COMPARE(7295.5609, 987654.1111, 237663472.9273, -67.6887, -167.31614, -67.6887, 167.31614);
	SOLVE_AND_COMPARE(-7295.5609, -987654.1111, -237663472.9273, -67.6887, -167.31614, -67.6887, 167.31614);
	SOLVE_AND_COMPARE(7295.5609, -987654.1111, 237663472.9273, 67.6887, -167.31614, 67.6887, 167.31614);
	SOLVE_AND_COMPARE(-7295.5609, 987654.1111, -237663472.9273, 67.6887, -167.31614, 67.6887, 167.31614);
	SOLVE_AND_COMPARE(7295.5609 * 0.231, 987654.1111 * 0.231, 237663472.9273 * 0.231, -67.6887, -167.31614, -67.6887, 167.31614);
}
END_TEST

BEGIN_GROUP(Different_complex_roots)
ADD_TEST(b_is_null_imaginary_roots)
ADD_TEST(No_null_args_complex_roots_1)
ADD_TEST(No_null_args_complex_roots_2)
ADD_TEST(No_null_args_complex_roots_3)
END_GROUP





BEGIN_TEST(Input_unsigned_long_long)
{
	unsigned long long num = 17472313498683285243ULL;
	SOLVE_AND_COMPARE(num, num, num, -0.5, -0.86603, -0.5, 0.86603);
	SOLVE_AND_COMPARE(1, num, 0, -(double)num, 0, 0, 0);
}
END_TEST

BEGIN_TEST(Input_char)
{
	char ASCII_sym = 'h';
	wchar_t Unicode_sym = 'Þ';
	complex_pair expected_res_1 = solve_equation(1, 1, (double)ASCII_sym), expected_res_2 = solve_equation(1, 1, (double)Unicode_sym);
	ASSERT(EQUAL_COMPLEX_PAIRS(solve_equation(1, 1, ASCII_sym), expected_res_1));
	ASSERT(EQUAL_COMPLEX_PAIRS(solve_equation(1, 1, Unicode_sym), expected_res_2));
	expected_res_1 = solve_equation(1, (double)ASCII_sym, (double)ASCII_sym); expected_res_2 = solve_equation(1, (double)Unicode_sym, (double)Unicode_sym);
	ASSERT(EQUAL_COMPLEX_PAIRS(solve_equation(1, ASCII_sym, ASCII_sym), expected_res_1));
	ASSERT(EQUAL_COMPLEX_PAIRS(solve_equation(1, Unicode_sym, Unicode_sym), expected_res_2));
	expected_res_1 = solve_equation((double)Unicode_sym, (double)ASCII_sym, 1);
	ASSERT(EQUAL_COMPLEX_PAIRS(solve_equation(Unicode_sym, ASCII_sym, 1), expected_res_1));
}
END_TEST

BEGIN_TEST(Too_large_args)
{
	SOLVE_AND_CHECK_NAN(1, DBL_MAX * 1.0000000000001, 1);
	SOLVE_AND_CHECK_NAN(1, DBL_MAX + DBL_MAX / 1000000000000000, 1);
	SOLVE_AND_CHECK_NAN(1, -DBL_MAX * 1.0000000000001, 1);
	SOLVE_AND_CHECK_NAN(1, -DBL_MAX - DBL_MAX / 1000000000000000, 1);
	ASSERT(!EQUAL_COMPLEX_PAIRS(solve_equation(1, DBL_MAX, 1), solve_equation(1, INFINITY, 1)));

	SOLVE_AND_CHECK_NAN(DBL_MAX * 1.0000000000001, 1, 1);
	SOLVE_AND_CHECK_NAN(DBL_MAX + DBL_MAX / 1000000000000000, 1, 1);
	SOLVE_AND_CHECK_NAN(-DBL_MAX * 1.0000000000001, 1, 1);
	SOLVE_AND_CHECK_NAN(-DBL_MAX - DBL_MAX / 1000000000000000, 1, 1);
	ASSERT(!EQUAL_COMPLEX_PAIRS(solve_equation(DBL_MAX, 1, 1), solve_equation(INFINITY, 1, 1)));

	SOLVE_AND_CHECK_NAN(1, 1, DBL_MAX * 1.0000000000001);
	SOLVE_AND_CHECK_NAN(1, 1, DBL_MAX + DBL_MAX / 1000000000000000);
	SOLVE_AND_CHECK_NAN(1, 1, -DBL_MAX * 1.0000000000001);
	SOLVE_AND_CHECK_NAN(1, 1, -DBL_MAX - DBL_MAX / 1000000000000000);
	ASSERT(!EQUAL_COMPLEX_PAIRS(solve_equation(1, 1, DBL_MAX), solve_equation(1, 1, INFINITY)));

}
END_TEST

BEGIN_TEST(Max_args_to_result_not_inf_when_c_is_null)
{
	complex_pair res = solve_equation(1, DBL_MAX, 0);
	ASSERT(!isinf(res.first.Re) && !isinf(res.second.Re));
	res = solve_equation(0.999999999999, DBL_MAX, 0);
	ASSERT(isinf(res.first.Re) && (res.second.Re == 0));

	res = solve_equation(1, -DBL_MAX, 0);
	ASSERT(!isinf(res.first.Re) && !isinf(res.second.Re));
	res = solve_equation(0.999999999999, -DBL_MAX, 0);
	ASSERT((res.first.Re == 0) && isinf(res.second.Re));
}
END_TEST

BEGIN_TEST(Max_args_to_result_not_inf_when_b_is_null)
{
	complex_pair res = solve_equation(1, 0, -DBL_MAX);
	ASSERT(isinf(res.first.Re) && isinf(res.second.Re));
	res = solve_equation(0.25, 0, -DBL_MAX);
	ASSERT(!isinf(res.first.Re) && !isinf(res.second.Re));
	res = solve_equation(0.250001, 0, -DBL_MAX);
	ASSERT(isinf(res.first.Re) && isinf(res.second.Re));

	res = solve_equation(1, 0, DBL_MAX);
	ASSERT(isinf(res.first.Im) && isinf(res.second.Im));
	res = solve_equation(0.25, 0, DBL_MAX);
	ASSERT(!isinf(res.first.Im) && !isinf(res.second.Im));
	res = solve_equation(0.250001, 0, DBL_MAX);
	ASSERT(isinf(res.first.Im) && isinf(res.second.Im));



	res = solve_equation(sqrt(DBL_MAX), 0, -sqrt(DBL_MAX));
	ASSERT(isinf(res.first.Re) && isinf(res.second.Re));
	res = solve_equation(sqrt(DBL_MAX), 0, -sqrt(DBL_MAX) / 4);
	ASSERT(!isinf(res.first.Re) && !isinf(res.second.Re));
	res = solve_equation(sqrt(DBL_MAX), 0, -sqrt(DBL_MAX) / 3.99999999);
	ASSERT(isinf(res.first.Re) && isinf(res.second.Re));
}
END_TEST

BEGIN_TEST(Max_args_to_result_not_inf_when_a_is_null)
{
	SOLVE_AND_COMPARE(0, DBL_MAX, 0, 0, 0, 0, 0);
	SOLVE_AND_COMPARE(0, -DBL_MAX, 0, 0, 0, 0, 0);

	SOLVE_AND_COMPARE(0, DBL_MAX, 1234567890, 0, 0, 0, 0);
	SOLVE_AND_COMPARE(0, -DBL_MAX, 1234567890, 0, 0, 0, 0);

	SOLVE_AND_COMPARE(0, DBL_MAX, DBL_MAX / 100, -0.01, 0, -0.01, 0);
	SOLVE_AND_COMPARE(0, -DBL_MAX, DBL_MAX / 100, 0.01, 0, 0.01, 0);
}
END_TEST

BEGIN_TEST(Max_args_to_result_not_inf_when_no_null_args)
{
	ASSERT(EQUAL_COMPLEX_PAIRS(solve_equation(1, sqrt(DBL_MAX), 0), solve_equation(1, sqrt(DBL_MAX), -1123456789000000000)));
	ASSERT(EQUAL_COMPLEX_PAIRS(solve_equation(1, sqrt(DBL_MAX), 0), solve_equation(1, sqrt(DBL_MAX), 1123456789000000000)));

	complex_pair res = solve_equation(sqrt(DBL_MAX), sqrt(DBL_MAX), -sqrt(DBL_MAX));
	ASSERT(isinf(res.first.Re) && isinf(res.second.Re));
	res = solve_equation(sqrt(DBL_MAX) / 8, sqrt(DBL_MAX / 2), -sqrt(DBL_MAX));
	ASSERT(!isinf(res.first.Re) && !isinf(res.second.Re));
	res = solve_equation(sqrt(DBL_MAX) / 7.999999999, sqrt(DBL_MAX / 2), -sqrt(DBL_MAX));
	ASSERT(isinf(res.first.Re) && isinf(res.second.Re));
	res = solve_equation(sqrt(DBL_MAX) / 8, sqrt(DBL_MAX / 1.9999999), -sqrt(DBL_MAX));
	ASSERT(isinf(res.first.Re) && isinf(res.second.Re));
}
END_TEST

BEGIN_TEST(Min_a_to_result_not_inf_when_no_null_args)
{
	complex_pair res = solve_equation(1 / DBL_MAX, 1, 2);
	ASSERT(isinf(res.first.Re) && res.second.Re == 0);
	res = solve_equation(1.000000001 / DBL_MAX, 1, 2);
	ASSERT(!isinf(res.first.Re) && !isinf(res.second.Re));

	res = solve_equation(-1 / DBL_MAX, 1, 2);
	ASSERT(res.first.Re == 0 && isinf(res.second.Re));
	res = solve_equation(-1.000000001 / DBL_MAX, 1, 2);
	ASSERT(!isinf(res.first.Re) && !isinf(res.second.Re));
}
END_TEST

BEGIN_TEST(Too_small_args)
{
	ASSERT(DBL_MIN / 1000000000000000. != 0);
	ASSERT(DBL_MIN / 10000000000000000. == 0);
	ASSERT(solve_equation(1, 0, -DBL_MIN).first.Re == 0); // Because permissible error of discriminant == 0
	ASSERT(solve_equation(0, 1, -DBL_MIN).first.Re != 0);
	ASSERT(solve_equation(0, 1, -DBL_MIN / 1000000000000000).first.Re != 0);
	ASSERT(solve_equation(0, 1, -DBL_MIN / 10000000000000000).first.Re == 0);
}
END_TEST

BEGIN_GROUP(Input_limits)
ADD_TEST(Input_unsigned_long_long)
ADD_TEST(Input_char)
ADD_TEST(Too_large_args)
ADD_TEST(Max_args_to_result_not_inf_when_c_is_null)
ADD_TEST(Max_args_to_result_not_inf_when_b_is_null)
ADD_TEST(Max_args_to_result_not_inf_when_a_is_null)
ADD_TEST(Max_args_to_result_not_inf_when_no_null_args)
ADD_TEST(Min_a_to_result_not_inf_when_no_null_args)
ADD_TEST(Too_small_args)
END_GROUP





void tests_quadratic_equation() {
	RUN_TESTS_GROUP(Invalid_inputs);
	RUN_TESTS_GROUP(Equal_roots);
	RUN_TESTS_GROUP(Different_permissible_errors_of_discriminant);
	RUN_TESTS_GROUP(Different_real_roots);
	RUN_TESTS_GROUP(Different_complex_roots);
	RUN_TESTS_GROUP(Input_limits);
}