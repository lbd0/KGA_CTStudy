#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Merge(vector<int>& arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;	 // 왼쪽 배열 크기
	int n2 = right - mid;		// 오른쪽 배열 크기

	// 임시 배열 생성
	vector<int> leftArr(n1), RightArr(n2);

	for (int i = 0; i < n1; i++)
	{
		leftArr[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++)
	{
		RightArr[j] = arr[mid + 1 + j];
	}

	// 두 임시 배열을 병합하여 원본 배열에 저장
	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= RightArr[j])
		{
			arr[k++] = leftArr[i++];
		}
		else
		{
			arr[k++] = RightArr[j++];
		}
	}

	//왼쪽 배열에 남은 원소들 복사
	while (i < n1)
	{
		arr[k++] = leftArr[i++];
	}

	// 오른쪽 배열에 남은 원소들 복사
	while (j < n2)
	{
		arr[k++] = RightArr[j++];
	}
}

// 재귀적으로 배열을 분할하고, merge 함수를 호출하는 병합 정렬 함수
void mergeSort(vector<int>& arr, int left, int right)
{
	// 배열의 길이가 1이면 이미 정렬된 상태
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		//왼쪽 부분 정렬
		mergeSort(arr, left, mid);

		//오른쪽 부분 배열 정렬
		mergeSort(arr, mid + 1, right);

		// 정렬된 두 부분 배열을 병합
		Merge(arr, left, mid, right);
	}
}

int main()
{
	vector<int> arr = { 38, 27, 43, 3, 9, 82, 10 };

	cout << "정렬 전 배열 ";

	for (int num : arr)
	{
		cout << num << " ";
	}

	cout << endl;

	// 병합 정렬
	mergeSort(arr, 0, arr.size() - 1);

	// 정렬 후 배열 출력
	cout << "정렬 후 배열 : ";
	for (int num : arr)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}
