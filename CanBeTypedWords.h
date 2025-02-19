//hello world
#include <stdbool.h>
int canBeTypedWords(char* text, char* brokenLetters) {
	int words = 0;

	char* wordBegin = text;
	char* wordEnd = text;
	char* temp = brokenLetters;
	int length = 0;
	while (*text != '\0')
	{
		while (*text != ' ' && *text != '\0')
		{
			text++;
			length++;
		}

		bool found = false;
		int temp2 = length;
		while (*brokenLetters != '\0')
		{
			while (length-- > 0)
			{
				if (*wordBegin++ == *brokenLetters)
				{
					found = true;
					break;
				}
			}

			wordBegin = wordEnd;
			length = temp2;
			brokenLetters++;
		}
		brokenLetters = temp;

		if (!found)
			words++;

		while (*text == ' ')
		{
			text++;
		}

		wordBegin = text;
		wordEnd = text;
		length = 0;
	}

	return words;
}