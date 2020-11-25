//
//  Example_02.c
//  Example
//
//  Created by 이상동 on 2020/11/25.
//

#include "Example_02.h"

#define EXAMPLE_TYPE_VARIABLE					1
#define EXAMPEL_TYPE_DATA_INPUT_OUTPUT			2

#define EXAMPLE_TYPE			EXAMPLE_TYPE_VARIABLE

//! Example 2
void Example_02(const int argc, const char **args) {
#if EXAMPLE_TYPE == EXAMPLE_TYPE_VARIABLE
	short nShortA = 10;
	unsigned short nShortB = 20u;
	
	int nIntA = 10;
	unsigned int nIntB = 20u;
	
	long nLongA = 10l;
	unsigned long nLongB = 20ul;
	
	long long nLongLongA = 10ll;
	unsigned long long nLongLongB = 20ull;
	
	printf("===== 정수 출력 =====\n");
	printf("short: %d, %u, %ld\n", nShortA, nShortB, sizeof(nShortA));
	printf("short: %d, %u, %ld\n", nIntA, nIntB, sizeof(nIntA));
	printf("short: %ld, %lu, %ld\n", nLongA, nLongB, sizeof(nLongA));
	printf("short: %lld, %llu, %ld\n", nLongLongA, nLongLongB, sizeof(nLongLongA));
#elif EXAMPLE_TYPE == EXAMPEL_TYPE_DATA_INPUT_OUTPUT
	
#endif			// #if EXAMPLE_TYPE == EXAMPLE_TYPE_VARIABLE
}
