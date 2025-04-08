#include<iostream>
#include<algorithm>

using namespace std;

int partition(int arr[], int left, int right)
{
	int pivot = arr[left];//�ǹ� �� ����
	int l = left;//���� �� l ����
	int r = right+1;//������ �� r ����

	while (true)
	{
		do {//�ּ� l�� �ѹ��� �÷��ְ�, l�� ó�� right�� ���ų� �۰�, �迭�ε��� l�� pivot���� ������,
			++l;//l�� ���
		} while (l <= right && arr[l] < pivot);

		do {//�ּ� r�� �ѹ��� �÷��ְ�, r�� ó�� left�� ���ų� ũ��, �迭�ε��� r�� pivot���� Ŭ��,
			--r;//r�� ���
		} while (r >= left && arr[r] > pivot);

		if (l >= r)break;//���� l�� r���� ũ�ų� ���ٸ�, while�� ����

		std::swap(arr[l], arr[r]);//l��° �ε����� r��° �ε��� swap
		//r�� l�� ���� ������ �ʾ�����, while�� ��� ����
	}

	std::swap(arr[left], arr[r]);//�ǹ��� r��° �ε��� swap

	return r;//r ����
}

void quick_sort(int arr[], int left, int right)
{
	if (left < right)//������ �����ʺ��� �۴ٸ�
	{
		int pivotIndex = partition(arr, left, right);//�ٲ� �ǹ� ����

		quick_sort(arr, left, pivotIndex - 1);//���� ����Լ�
		quick_sort(arr, pivotIndex + 1, right);//������ ����Լ�
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