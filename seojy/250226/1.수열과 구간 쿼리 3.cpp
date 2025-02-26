/*
1.수열과 구간 쿼리 3
정수 배열 arr와 2차원 정수 배열 queries이 주어집니다. queries의 원소는 각각 하나의 query를 나타내며, [i, j] 꼴입니다.

각 query마다 순서대로 arr[i]의 값과 arr[j]의 값을 서로 바꿉니다.

위 규칙에 따라 queries를 처리한 이후의 arr를 return 하는 solution 함수를 완성해 주세요.

*/#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(vector<int> v : queries)
    {
        int temp = arr.at(v.at(0));
        arr.at(v.at(0)) = arr.at(v.at(1));
        arr.at(v.at(1)) = temp;
    }
    
    answer = arr;
    
    return answer;
}
