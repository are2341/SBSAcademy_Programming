#include "Practice_01.h"

#define PT_01
//#define PT_02
//#define PT_03
//#define PT_04
//#define PT_05

void Practice_01(const int argc, const char ** args) {
#if defined PT_01
	int nNumLines = 0;

	printf("라인 개수 입력 : ");
	scanf("%d", &nNumLines);

	for(int i = 0; i < nNumLines; ++i) {
		for(int j = 0; j <= i; ++j) {
			printf("*");
		}

		printf("\n");
	}
#elif defined PT_02
	int nNumLines = 0;

	printf("라인 개수 입력 : ");
	scanf("%d", &nNumLines);

	for(int i = nNumLines - 1; i >= 0; --i) {
		for(int j = 0; j <= i; ++j) {
			printf("*");
		}

		printf("\n");
	}
#elif defined PT_03
	int nNumLines = 0;

	printf("라인 개수 입력 : ");
	scanf("%d", &nNumLines);

	for(int i = 0; i < nNumLines; ++i) {
		for(int j = 0; j < nNumLines; ++j) {
			int nCenter = nNumLines / 2;
			int nOffset = (i <= nNumLines / 2) ? i : nNumLines - (i + 1);

			printf("%c", (j >= nCenter - nOffset && j <= nCenter + nOffset) ? '*' : ' ');
		}

		printf("\n");
	}
#elif defined PT_04
	int nSumValue = 0;
	int nNumValues = 0;

	printf("개수 입력 : ");
	scanf("%d", &nNumValues);

	for(int i = 0; i < nNumValues; ++i) {
		int nValue = 0;

		printf("%d 번째 수 입력 : ", i + 1);
		scanf("%d", &nValue);

		nSumValue += nValue;
	}

	printf("\n합계 : %d\n", nSumValue);
	printf("\n평균 : %f\n", nSumValue / (float)nNumValues);
#elif defined PT_05
	int nNumValues = 0;
	int anValues[100] = { 0 };

	printf("개수 입력 : ");
	scanf("%d", &nNumValues);

	int nOddIdx = 0;
	int nEvenIdx = nNumValues - 1;

	for(int i = 0; i < nNumValues; ++i) {
		int nValue = 0;

		printf("%d 번째 수 입력 : ", i + 1);
		scanf("%d", &nValue);

		// 홀수 일 경우
		if(nValue % 2 != 0) {
			anValues[nOddIdx++] = nValue;
		} else {
			anValues[nEvenIdx--] = nValue;
		}
	}

	printf("\n결과 : ");

	for(int i = 0; i < nNumValues; ++i) {
		printf("%d, ", anValues[i]);
	}

	printf("\n");
#endif			// #if defined PT_01
}
