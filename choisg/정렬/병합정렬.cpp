#include <iostream>
#include <vector>

using namespace std;


void Merge(vector<int>& arr, int left, int mid, int right)
{
    // 왼쪽 부분 배열 크기, 오른쪽 부분 배열 크기
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 임시 배열 생성
    vector<int> L(n1);
    vector<int> R(n2);

    // 임시 배열에 복사 (왼쪽 구간)
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];

    // 임시 배열에 복사 (오른쪽 구간)
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // 머지 작업
    int i = 0, j = 0;      // 왼쪽, 오른쪽 임시 배열 인덱스
    int k = left;         // 실제 arr에 머지해 넣을 인덱스

    // 두 배열 모두 원소가 남아있을 동안 비교/삽입
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

    // 왼쪽 배열에 남은 원소가 있으면 전부 복사
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 오른쪽 배열에 남은 원소가 있으면 전부 복사
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

// 분할(Divide) 단계 + 재귀 호출
void MergeSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        // 왼쪽, 오른쪽 구간으로 나누어 정렬
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        // 정복(Conquer) 단계: 상위함수가 좌측 정렬과 우측정렬을 모든 모든 경우 두 구간을 합침
        Merge(arr, left, mid, right);
    }

}

int main()
{
   vector<int> arr = { 12, 11, 13, 5, 6, 7 };

    // 머지소트 실행
    MergeSort(arr, 0, arr.size() - 1);

    // 결과 출력
    cout << "Sorted array: ";
    for (int x : arr) {
        cout << x << " ";
    }
   cout << endl;

    return 0;

}