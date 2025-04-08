#include<iostream>
#include<vector>

using namespace std;

void Merge(vector<int>& arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;//���� ũ��
	int n2 = right - mid;//������ ũ��

	vector<int> L(n1);//���� L�� n1ũ�⸸ŭ �ʱ�ȭ
	vector<int> R(n2);//���� R�� n2ũ�⸸ŭ �ʱ�ȭ

	for (int i = 0; i < n1; ++i)
	{
		L[i] = arr[left + i];//���� L�� i��° �ε������ٰ� �迭arr�� �������κ��� i��° �ֱ�
	}

	for (int i = 0; i < n2; ++i)
	{
		R[i] = arr[mid + 1 + i];//���� R�� i��° �ε������ٰ� �迭arr�� �߰��������� i��° �ֱ�
	}

	int i = 0, j = 0;
	int k = left;

	while (i < n1 && j < n2)//i�� j�� ��� ����,������ ũ�⸸ŭ Ŀ��������
	{
		if (L[i] <= R[j])//L�� i��° �ε����� R�� j��° �ε������� �۰ų� ������
		{
			arr[k] = L[i];//arr k��° �ε���(����)�� L�� i��° �ε��� �ֱ�
			++i;//i����
		}
		else//L�� i��° �ε����� R�� j��° �ε������� ũ�ٸ�
		{
			arr[k] = R[j];//arr k��° �ε���(����)�� L�� j��° �ε��� �ֱ�
			++j;//j����
		}
		++k;//k�ε��� ����
	}

	while (i < n1)//i�� n1ũ�⺸�� ����������
	{
		arr[k] = L[i];//arr k��° �ε���(����)�� L�� i��° �ε��� �ֱ�
		++i;//i����
		++k;//k�ε��� ����
	}

	while (j < n2)//j�� n2ũ�⺸�� ����������
	{
		arr[k] = R[j];//arr k��° �ε���(����)�� L�� j��° �ε��� �ֱ�
		++j;//j����
		++k;//k�ε��� ����
	}

}

void MergeSort(vector<int>& arr, int left, int right)
{
	if (left < right)//������ �����ʺ��� �۴ٸ�
	{
		int mid = (left + right) / 2;//���� ������ ���ؼ� ���� ���� �߰������� ����

		MergeSort(arr, left, mid);//���� ����Լ�
		MergeSort(arr, mid + 1, right);//������ ����Լ�

		Merge(arr, left, mid, right);//����Լ� ��� ��ġ�� ����
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