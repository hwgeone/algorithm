#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

int binaryGap(int n) {
	int index = 0;
	int priviousPos = -1;
	int maxGap = 0;
	while (n > 0)
	{
		int bit = n % 2;

		if (bit == 1)
		{
			if (priviousPos == -1)
			{
				priviousPos = index;
			}
			else
			{
				maxGap = fmax(maxGap, index - priviousPos);
				priviousPos = index;
			}
		}

		index++;
		n = n / 2;
	}

	return maxGap;
}
