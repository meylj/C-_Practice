#include <iostream>
#include <cmath>
using namespace std;

#define ARR_LEN 10


void selectSort(int n, int *arr)
{
	int min, tmp;
	
	for (int i = 0; i < n-1; ++i)
	{
        min = arr[i];
		for (int j = i+1; j < n; ++j)
		{
			if (arr[j] < min)
			{
				min = arr[j];
			}
		}

		if (min != arr[i])
		{
			tmp = min;
			min = arr[i];
			arr[i] = min;
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[ARR_LEN] = {4,2,4,5,5,6,2,3,8,7};
	for (int i = 0; i < ARR_LEN; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	int *arrtemp = arr;
        selectSort(ARR_LEN,arrtemp);
	for (int i = 0; i < ARR_LEN; ++i)
	{
		cout << arr[i] << " ";
	}
        cout << endl;
    
	return 0;
}
