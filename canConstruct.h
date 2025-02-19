#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

//aa aab
bool canConstruct(char* ransomNote, char* magazine) {
	//hash
	int maxLength = 26;
	int* hash = (int*)malloc(maxLength * sizeof(int));

	if (!hash)
		exit(1);

	memset(hash,0,sizeof(int) * maxLength);

	int index = 0;
	while (magazine[index] != '\0')
	{
		hash[magazine[index] - 'a']++;
		index++;
	}

    index = 0;
	while (ransomNote[index] != '\0')
	{
		hash[ransomNote[index]-'a']--;
		index++;
	}

	bool canC = true;
	for (int i = 0; i < maxLength; i++)
	{
		if (hash[i] < 0)
		{
			canC = false;
			break;
		}
	}

	if (hash)
		free(hash);
	hash = NULL;

	return canC;
}