#include "tests_interface.h"



void ___running_group(___res(*group)()) {
	___res result = group();
	if (result.total == result.successfully) {
		printf("-");
	}
	printf("\nTests run: %d. Successfully: %d. Failed: %d.\n\n", result.total, result.successfully, result.total - result.successfully);
}
