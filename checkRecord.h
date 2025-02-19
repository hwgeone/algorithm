#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

//'A': Absent.
//'L': Late.
//'P' : Present.
bool checkRecord(char* s) {
	int aCount = 0;
	int lCount = 0;

	char* p = s;
	while (*p)
	{
		if (*p == 'A')
			aCount++;

		if (*p == 'L')
			lCount++;

		if (*p != 'L' && lCount < 3)
			lCount = 0;

		p++;
	}

	if (lCount >= 3 || aCount >= 2)
		return false;
	return true;
}