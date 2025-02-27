/*
Q. 수열과 구간 쿼리 2

정수 배열 arr와 2차원 정수 배열 queries이 주어집니다. 
queries의 원소는 각각 하나의 query를 나타내며, [s, e, k] 꼴입니다.

각 query마다 순서대로 s ≤ i ≤ e인 모든 i에 대해 k보다 크면서 가장 작은 arr[i]를 찾습니다.

각 쿼리의 순서에 맞게 답을 저장한 배열을 반환하는 solution 함수를 완성해 주세요.
단, 특정 쿼리의 답이 존재하지 않으면 -1을 저장합니다.
*/

#include <vector>

std::vector<int> solution(std::vector<int> arr, std::vector<std::vector<int>> queries) {
    std::vector<int> answer;
    
    for(int i = 0; i < queries.size(); ++i) {
        std::vector<int> arr1;
        
        for (int j = queries[i][0]; j <= queries[i][1]; ++j) {
                arr1.push_back(arr[j]);
        }
        int temp = 1000000;
        for (int j = 0; j < arr1.size(); ++j) {
            arr1[j] > queries[i][2] ? arr1[j] < temp ? temp = arr1[j] : 0 : 0;
        }
        if (temp > queries[i][2])
        {
            if (temp == 1000000) answer.push_back(-1);
            else answer.push_back(temp);
        }
    }
    
    return answer;
}