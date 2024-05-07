#pragma once
#include <stdio.h>



// Describe your test after this macro. Identifier test_name must be unique for everyone tests
#define BEGIN_TEST(test_name)	\
	int test_name() {			\
		int result = 1;

// Can be used only between BEGIN_TEST and END_TEST! If expression == 0, this test becoming failure, else nothing happens
#define ASSERT(expression)		\
		if (!(expression)) {	\
		result = 0;				\
		}

// Finish your test description by this macro
#define END_TEST				\
		return result;			\
	}




typedef struct ___res {
	int total, successfully;
} ___res;


// Describe your tests group after this macro. Identifier group_name must be unique for everyone groups
#define BEGIN_GROUP(group_name)				\
char* str_test_name;						\
	___res group_name() {					\
		___res result = { 0, 0 };			\
		int one_result = 0;					\
		printf("\nFailed tests: ");

// Can be used only between BEGIN_GROUP and END_GROUP! Add one test using identifier to this group
#define ADD_TEST(test_name)					\
		one_result = test_name();			\
		result.total++;						\
		result.successfully += one_result;	\
		if (!one_result) 					\
			printf("\n    "#test_name);		

// Finish your group description by this macro
#define END_GROUP							\
		return result;						\
	}




void ___running_group(___res(*group)());

/* Use this macro in your functions to run tests group and get testing report in console */
#define RUN_TESTS_GROUP(group_name)				\
	printf("\nRun tests group  " #group_name);	\
	___running_group(group_name);
