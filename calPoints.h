#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include<ctype.h>

//如果是数字，那么代表本局得分
//如果是"+"，代表本局得分是前两局的和
//如果是"C"，代表上一轮的得分是无效的
//如果是"D"，代表本轮得分是上一轮的二倍
//["5","2","C","D","+"]

//bool isdigit(char* s)
//{
//	return (strspn(s, "0123456789") == strlen(s));
//}
//"36","28","70","65","C","+","33","-46","84","C"
int calPoints(char** operations, int operationsSize) {
	int a[1000] = { 0 };
	int p = 0;

	for (int i = 0; i < operationsSize; i++)
	{
		if (strcmp("C", operations[i]) == 0)
		{
			p--;
		}
		else if (strcmp("D", operations[i]) == 0)
		{
			a[p] = a[p - 1] * 2;
			p++;
		}
		else if (strcmp("+", operations[i]) == 0)
		{
			a[p] = a[p - 1] + a[p - 2];
			p++;
		}
		else
		{
			int d = atoi(operations[i]);
			a[p++] = d;
		}
	}
	p--;
	int sum = 0;

	while (p >= 0)
	{
		sum += a[p];
		p--;
	}

	return sum;
}