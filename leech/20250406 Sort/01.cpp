#include <iostream>
#include <algorithm>

using namespace std;

// partition 함수
int partition(int arr[], int left, int right)
{
	// 왼쪽 원소를 pivot으로 임의 설정
	int pivot = arr[left];
	int i = left;
	int j = right + 1;

	while (true)
	{
		// pivot보다 작으면 low를 증가
		do
		{
			++i;
		} while (i <= right && arr[i] < pivot);

		// pivot보다 크면 high를 감소
		do
		{
			--j;
		} while (j >= left && arr[i] > pivot);

		// low와 high가 교차하지 않았으면 swap. 교차했다면 partition 종료
		if (i >= j) break;

		std::swap(arr[i], arr[j]);
	}

	// pivot을 list[high]와 교환
	std::swap(arr[left], arr[right]);

	// pivot의 위치인 high 반환
	return j;
}

// quick sort
void quick_sort(int arr[], int left, int right)
{
	// 정렬할 원소가 2개 이상인 경우만 quick sort
	if (left < right)
	{
		//partition을 통해 pivot 구분
		int pivotIdx = partition(arr, left, right);

		//pivot 제외 앞, 뒤쪽 부분 배열 각각 정렬
		quick_sort(arr, left, pivotIdx - 1);
		quick_sort(arr, pivotIdx + 1, right);
	}
}

int main()
{
	int arr[] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// quick sort
	quick_sort(arr, 0, n - 1);

	// 결과 출력
	for (const auto& a : arr)
	{
		cout << a << endl;
	}

	return 0;
}