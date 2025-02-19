//Input: a = "11", b = "11"
//Output: "100"
#include<stdlib.h>
#include <stdbool.h>

//a小b大
char* addBinary(char* a, char* b) {
	int len = 0;

	while (*a++ != '\0')
		len++;
	int len2 = 0;
	while (*b++ != '\0')
		len2++;

	char* temp = NULL;
	if (len > len2)
	{
		temp = b;
		b = a;
		a = temp;
	}


	int maxLen = len > len2 ? len : len2;
	int minLen = len > len2 ? len2 : len;
	char* newStr = (char*)malloc(sizeof(char) * (maxLen + 1));
	if (!newStr)
	{
		//异常退出，告诉操作系统，程序出错了
		exit(1);
	}
	newStr[maxLen] = '\0';
	a--;b--;
	a--;b--;
	bool isStep = false;
	bool first = true;
	int tenpLen = maxLen;
	while (maxLen > 0)
	{
		if (minLen > 0)
		{
			int step = ((int)*a - 48) + ((int)*b - 48);

			if (first && (*a) == (*b) == 1)
			{

			}
			else if (!first && isStep)
			{
				step += 1;
			}
			if (step >= 2)
				isStep = true;
			else
				isStep = false;
			if (step == 3)
				step = 1;
			else if (step == 2)
				step = 0;
			else
				step = 1;

			newStr[maxLen - 1] = (char)(step + 48);


			first = false;

			minLen--;
			b--;
			a--;
		}
		else
		{
			int step = ((int)*b - 48);

			if (!first && isStep)
			{
				step += 1;
			}
			if (step >= 2)
				isStep = true;
			else
				isStep = false;

			if (step == 3)
				step = 1;
			else if (step == 2)
				step = 0;
			else
				step = 1;

			newStr[maxLen - 1] = (char)(step + 48);


			first = false;
			b--;
		}
		maxLen--;
	}

	if (isStep)
	{
		*(newStr + tenpLen + 1) = '\0';
		char* tempp = newStr;
		newStr = (char*)malloc(sizeof(char) * (tenpLen + 2));
		if (!newStr)
			exit(1);
		newStr[0] = '1';
		int loop = 0;
		while (*(tempp + loop) != '\0')
		{
			*(newStr + loop + 1) = *tempp;
			loop++;
		}
		*(newStr + loop + 1) = '\0';

		free(tempp);
	}
	else
	{
		*(newStr + tenpLen) = '\0';
	}

	return newStr;
}
