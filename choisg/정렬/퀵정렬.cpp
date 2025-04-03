#include <iostream>
#include <algorithm> // std::swap ���
using namespace std;



// partition �Լ�
int partition(int arr[], int left, int right) {
    int pivot = arr[left]; //���� ���Ҹ� �ǹ����� ���� ����
    int i = left;
    int j = right + 1; //left�� right�� low�� high�� �θ��⵵ ��(�����)

    while (true) {

        // �ǹ����� ������ low�� ����
        do {
            i++;
        } while (i <= right && arr[i] < pivot);

        // �ǹ����� ũ�� high�� ����
        do {
            j--;
        } while (j >= left && arr[j] > pivot);

        // low�� high�� �������� �ʾ����� swap. �����ߴٸ� ��Ƽ�� ��
        if (i >= j)  break; 
        
       
        std::swap(arr[i], arr[j]);
        
       
    }

    // �ǹ��� list[high]�� ��ȯ
    std::swap(arr[left], arr[j]);

    // �ǹ��� ��ġ�� high ��ȯ
    return j;
}

// �� ����
void quick_sort(int arr[], int left, int right) {
    if (left < right) { //������ ���Ұ� 2�� �̻��� ��츸 ������

        // partitionPivot���� �ǹ� ����
        int pivotIndex = partition(arr, left, right);

        // �ǹ� ���� ����/���� �κ� �迭 ���� ����
        quick_sort(arr, left, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, right);
    }
}

int main() {
    
    int arr[] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // �� ����
    quick_sort(arr, 0, n - 1);

    // ��� ���
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
