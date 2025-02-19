#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

//Input: num1 = "11", num2 = "123"
//Output : "134"
char* addStrings(char* num1, char* num2) {
	int isCarry = 0;

	int len1 = strlen(num1);
	int len2 = strlen(num2);

	if (len1 < len2)
	{
		char* temp = num2;
		num2 = num1;
		num1 = temp;

		int t = len2;
		len2 = len1;
		len1 = t;
	}


	char* res = (char*)malloc(sizeof(char) * len1 + 1);
	if (!res)
		exit(1);
	res[len1] = '\0';

	len2--; len1--;
	int truelen = 0;
	while (len2 >= 0)
	{
		char sum = (num1[len1]) + (num2[len2] - '0') + isCarry;

		if (isCarry >= 1)
			isCarry--;

		if (sum > '9')
		{
			//456 77
			isCarry++;
			sum = sum - 10;
		}

		res[len1] = sum;
		len2--;
		len1--;
		truelen++;
	}

	while (len1 >= 0)
	{
		char sum = num1[len1] + isCarry;

		if (sum > '9')
		{
			sum = sum - 10;
			if (sum == '0')
			{
			}
			else
				isCarry--;

		}
		else
		{
			if (isCarry > 0)
				isCarry--;
		}
		res[len1] = sum;
		len1--;
		truelen++;
	}

	if (isCarry)
	{
		truelen++;
	}
	char* trueRes = (char*)malloc(sizeof(char) * (truelen + 1));
	trueRes[truelen] = '\0';

	int index = 0;
	if (isCarry)
	{
		trueRes[0] = '1';
		index++;
	}

	char* p = res;
	while (*p != '\0')
	{
		trueRes[index] = *p;
		p++;
		index++;
	}

	if (res)
		free(res);
	return trueRes;
}