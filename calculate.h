#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}

int calculate(char* s) {
	int n = strlen(s);
	int* stk = (int*)malloc(sizeof(int) * n);
	int  top = 0;
	char preSign = '+';
	int num = 0;
	for (int i = 0; i < n; ++i) {
		if (isdigit(s[i])) {
			num = num * 10 + (int)(s[i] - '0');
		}
		if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
			switch (preSign) {
			case '+':
				stk[top++] = num;
				break;
			case '-':
				stk[top++] = -num;
				break;
			case '*':
				stk[top - 1] *= num;
				break;
			default:
				stk[top - 1] /= num;
			}
			preSign = s[i];
			num = 0;
		}
	}
	int ret = 0;
	for (int i = 0; i < top; i++) {
		ret += stk[i];
	}
	return ret;
}
