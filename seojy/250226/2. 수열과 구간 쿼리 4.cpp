/*
2. 수열과 구간 쿼리 4
정수 배열 arr와 2차원 정수 배열 queries이 주어집니다. queries의 원소는 각각 하나의 query를 나타내며, [s, e, k] 꼴입니다.

각 query마다 순서대로 s ≤ i ≤ e인 모든 i에 대해 i가 k의 배수이면 arr[i]에 1을 더합니다.

위 규칙에 따라 queries를 처리한 이후의 arr를 return 하는 solution 함수를 완성해 주세요.

*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(vector<int> vec : queries)
    {
        for(int i = vec.at(0);i <= vec.at(1);i++)
        {
            if(i % vec.at(2) == 0)
            {
                arr[i] = arr[i] + 1;
            }
        }
    }
    
    answer = arr;
    
    return answer;
}
