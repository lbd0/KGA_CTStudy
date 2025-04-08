#include <iostream>
#include <algorithm>

using namespace std;

// partition �Լ�
int partition(int arr[], int left, int right)
{
	// ���� ���Ҹ� pivot���� ���� ����
	int pivot = arr[left];
	int i = left;
	int j = right + 1;

	while (true)
	{
		// pivot���� ������ low�� ����
		do
		{
			++i;
		} while (i <= right && arr[i] < pivot);

		// pivot���� ũ�� high�� ����
		do
		{
			--j;
		} while (j >= left && arr[i] > pivot);

		// low�� high�� �������� �ʾ����� swap. �����ߴٸ� partition ����
		if (i >= j) break;

		std::swap(arr[i], arr[j]);
	}

	// pivot�� list[high]�� ��ȯ
	std::swap(arr[left], arr[right]);

	// pivot�� ��ġ�� high ��ȯ
	return j;
}

// quick sort
void quick_sort(int arr[], int left, int right)
{
	// ������ ���Ұ� 2�� �̻��� ��츸 quick sort
	if (left < right)
	{
		//partition�� ���� pivot ����
		int pivotIdx = partition(arr, left, right);

		//pivot ���� ��, ���� �κ� �迭 ���� ����
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

	// ��� ���
	for (const auto& a : arr)
	{
		cout << a << endl;
	}

	return 0;
}