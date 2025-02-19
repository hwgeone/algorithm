//[3,5,1]
void sort(int* arr, int arrSize)
{
	int temp;
	for (int i = 0;i < arrSize;i++)
	{
		for (int j = arrSize-1;j > i;j--)
		{
			if (arr[j] < arr[j - 1])
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}

}
bool canMakeArithmeticProgression(int* arr, int arrSize) {
	if (arrSize <= 2)
		return true;

	sort(arr, arrSize);

	int minu = arr[1] - arr[0];
	for (int i = 2;i < arrSize;i++)
	{
		if (minu == (arr[i] - arr[i - 1]))
		{
		}
		else
		{
			return false;
		}
	}

	return true;
}