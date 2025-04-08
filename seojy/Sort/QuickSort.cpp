#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Partition(int arr[], int low, int high)
{
	// 정렬한 원소가 2개 이상인 경우에만 퀵 정렬
	int pivot = arr[low];
	int i = low;
	int j = high + 1;

	while (true)
	{
		// 왼쪽에서 pivot 이상인 원소를 찾을 때 까지 + 1
		do
		{
			i++;
		} while (i <= high && arr[i] < pivot);

		do
		{
			j--;
		} while (j >= low && arr[j] > pivot);

		// 교차 or 엇갈림 발생 -> 파티션 끝
		if (i >= j) break;

		// 교환
		std::swap(arr[i], arr[j]);
	}

	//j는 피벗이 들어갈 위치
	swap(arr[low], arr[j]);

	return j;
	
}

void QuickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		//정렬한 원소가 2개 이상일 때만 정렬
		
		int pivotIndex = Partition(arr, low, high);

		// 피벗 기준 왼쪽, 오른쪽을 반복적으로 정렬
		QuickSort(arr, low, pivotIndex - 1);
		QuickSort(arr, pivotIndex + 1, high);

	}
}

int main()
{
	int arr[] = { 5,3,8,4,9,1,6,2,7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	QuickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
	return 0;

}
