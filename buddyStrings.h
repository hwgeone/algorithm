#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

//first frist
bool buddyStrings(char* s, char* goal) {
	int l1 = strlen(s);
	int l2 = strlen(goal);

	if (l1 != l2)
		return false;

	int hash1[26] = { 0 };
	int hash2[26] = { 0 };
	int sum = 0;
	for (int i = 0; i < l1; i++)
	{
		hash1[s[i] - 'a']++;
		hash2[goal[i] - 'a']++;
		if (s[i] != goal[i])
			sum++;
	}

	bool ok = false;
	for (int i = 0; i < 26; i++)
	{
		if (hash1[i] != hash2[i])
			return false;

		if (hash1[i] > 1)
			ok = true;
	}
	//特殊情况，当s和goal完全一模一样的时候，只有其中有重复的字母，才能一次交换成功
	return sum == 2 || (sum == 0 && ok);
}