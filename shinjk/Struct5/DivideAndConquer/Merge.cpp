#include<iostream>
#include<vector>

using namespace std;

void Merge(vector<int>& arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;//왼쪽 크기
	int n2 = right - mid;//오른쪽 크기

	vector<int> L(n1);//벡터 L을 n1크기만큼 초기화
	vector<int> R(n2);//벡터 R을 n2크기만큼 초기화

	for (int i = 0; i < n1; ++i)
	{
		L[i] = arr[left + i];//벡터 L의 i번째 인덱스에다가 배열arr의 왼쪽으로부터 i번째 넣기
	}

	for (int i = 0; i < n2; ++i)
	{
		R[i] = arr[mid + 1 + i];//벡터 R의 i번째 인덱스에다가 배열arr의 중간기점으로 i번째 넣기
	}

	int i = 0, j = 0;
	int k = left;

	while (i < n1 && j < n2)//i와 j가 모두 왼쪽,오른쪽 크기만큼 커질때까지
	{
		if (L[i] <= R[j])//L의 i번째 인덱스가 R의 j번째 인덱스보다 작거나 같으면
		{
			arr[k] = L[i];//arr k번째 인덱스(왼쪽)에 L의 i번째 인덱스 넣기
			++i;//i증가
		}
		else//L의 i번째 인덱스가 R의 j번째 인덱스보다 크다면
		{
			arr[k] = R[j];//arr k번째 인덱스(왼쪽)에 L의 j번째 인덱스 넣기
			++j;//j증가
		}
		++k;//k인덱스 증가
	}

	while (i < n1)//i가 n1크기보다 작을때까지
	{
		arr[k] = L[i];//arr k번째 인덱스(왼쪽)에 L의 i번째 인덱스 넣기
		++i;//i증가
		++k;//k인덱스 증가
	}

	while (j < n2)//j가 n2크기보다 작을때까지
	{
		arr[k] = R[j];//arr k번째 인덱스(왼쪽)에 L의 j번째 인덱스 넣기
		++j;//j증가
		++k;//k인덱스 증가
	}

}

void MergeSort(vector<int>& arr, int left, int right)
{
	if (left < right)//왼쪽이 오른쪽보다 작다면
	{
		int mid = (left + right) / 2;//왼쪽 오른쪽 더해서 나눈 값을 중간값으로 설정

		MergeSort(arr, left, mid);//왼쪽 재귀함수
		MergeSort(arr, mid + 1, right);//오른쪽 재귀함수

		Merge(arr, left, mid, right);//재귀함수 모두 마치고 정렬
	}
}


int main()
{
	vector<int> arr = { 12,15,3,9,6,5 };

	MergeSort(arr, 0, arr.size() - 1);

	cout << "Sorted array: ";
	for (int x : arr)
	{
		cout << x << " ";
	}
	cout << endl;

	return 0;
}