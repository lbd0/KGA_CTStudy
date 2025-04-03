#include <iostream>
#include <algorithm> // std::swap 사용
using namespace std;



// partition 함수
int partition(int arr[], int left, int right) {
    int pivot = arr[left]; //왼쪽 원소를 피벗으로 임의 설정
    int i = left;
    int j = right + 1; //left와 right는 low와 high로 부르기도 함(통상적)

    while (true) {

        // 피벗보다 작으면 low를 증가
        do {
            i++;
        } while (i <= right && arr[i] < pivot);

        // 피벗보다 크면 high를 감소
        do {
            j--;
        } while (j >= left && arr[j] > pivot);

        // low와 high가 교차하지 않았으면 swap. 교차했다면 파티션 끝
        if (i >= j)  break; 
        
       
        std::swap(arr[i], arr[j]);
        
       
    }

    // 피벗을 list[high]와 교환
    std::swap(arr[left], arr[j]);

    // 피벗의 위치인 high 반환
    return j;
}

// 퀵 정렬
void quick_sort(int arr[], int left, int right) {
    if (left < right) { //정렬할 원소가 2개 이상인 경우만 퀵정렬

        // partitionPivot으로 피벗 구분
        int pivotIndex = partition(arr, left, right);

        // 피벗 제외 앞쪽/뒤쪽 부분 배열 각각 정렬
        quick_sort(arr, left, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, right);
    }
}

int main() {
    
    int arr[] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // 퀵 정렬
    quick_sort(arr, 0, n - 1);

    // 결과 출력
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
