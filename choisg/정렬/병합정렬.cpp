#include <iostream>
#include <vector>

using namespace std;


void Merge(vector<int>& arr, int left, int mid, int right)
{
    // ���� �κ� �迭 ũ��, ������ �κ� �迭 ũ��
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // �ӽ� �迭 ����
    vector<int> L(n1);
    vector<int> R(n2);

    // �ӽ� �迭�� ���� (���� ����)
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];

    // �ӽ� �迭�� ���� (������ ����)
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // ���� �۾�
    int i = 0, j = 0;      // ����, ������ �ӽ� �迭 �ε���
    int k = left;         // ���� arr�� ������ ���� �ε���

    // �� �迭 ��� ���Ұ� �������� ���� ��/����
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // ���� �迭�� ���� ���Ұ� ������ ���� ����
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // ������ �迭�� ���� ���Ұ� ������ ���� ����
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

// ����(Divide) �ܰ� + ��� ȣ��
void MergeSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        // ����, ������ �������� ������ ����
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        // ����(Conquer) �ܰ�: �����Լ��� ���� ���İ� ���������� ��� ��� ��� �� ������ ��ħ
        Merge(arr, left, mid, right);
    }

}

int main()
{
   vector<int> arr = { 12, 11, 13, 5, 6, 7 };

    // ������Ʈ ����
    MergeSort(arr, 0, arr.size() - 1);

    // ��� ���
    cout << "Sorted array: ";
    for (int x : arr) {
        cout << x << " ";
    }
   cout << endl;

    return 0;

}