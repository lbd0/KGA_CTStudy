/************퀵정렬****************
피벗을 설정하고, 피벗과 비교하여 작으면 왼쪽, 크면 오른쪽
************************************/
#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int i = left;
	int j = right + 1;

	while (true)
	{
		do
		{
			i++;
		} while (i <= right && arr[i] < pivot);

		do
		{
			j--;
		} while (j >= left && arr[j] > pivot);

		if (i >= j) break;

		swap(arr[i], arr[j]);
	}

	swap(arr[left], arr[j]);

	return j;
}

void quick_sort(int arr[], int left, int right)
{
	if (left < right)
	{
		int pivotIndex = partition(arr, left, right);

		quick_sort(arr, left, pivotIndex - 1);
		quick_sort(arr, pivotIndex + 1, right);
	}
}

int main()
{
	int arr[] = { 5, 3, 8, 4, 9,1, 6, 2, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	quick_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}