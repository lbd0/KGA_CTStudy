#include<iostream>
#include<algorithm>

using namespace std;

int partition(int arr[], int left, int right)
{
	int pivot = arr[left];//피벗 값 설정
	int l = left;//왼쪽 값 l 설정
	int r = right+1;//오른쪽 값 r 설정

	while (true)
	{
		do {//최소 l값 한번은 올려주고, l이 처음 right와 같거나 작고, 배열인덱스 l가 pivot보다 작을때,
			++l;//l값 상승
		} while (l <= right && arr[l] < pivot);

		do {//최소 r값 한번은 올려주고, r이 처음 left와 같거나 크고, 배열인덱스 r이 pivot보다 클때,
			--r;//r값 상승
		} while (r >= left && arr[r] > pivot);

		if (l >= r)break;//만약 l이 r보다 크거나 같다면, while문 종료

		std::swap(arr[l], arr[r]);//l번째 인덱스와 r번째 인덱스 swap
		//r과 l이 아직 만나지 않았으니, while문 계속 실행
	}

	std::swap(arr[left], arr[r]);//피벗과 r번째 인덱스 swap

	return r;//r 리턴
}

void quick_sort(int arr[], int left, int right)
{
	if (left < right)//왼쪽이 오른쪽보다 작다면
	{
		int pivotIndex = partition(arr, left, right);//바뀐 피벗 저장

		quick_sort(arr, left, pivotIndex - 1);//왼쪽 재귀함수
		quick_sort(arr, pivotIndex + 1, right);//오른쪽 재귀함수
	}
}



int main()
{
	int arr[] = { 5,4,2,3,9,8,6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	quick_sort(arr, 0, n - 1);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << endl;
	}

	return 0;
}