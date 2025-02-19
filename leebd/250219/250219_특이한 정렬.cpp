/**************특이한 정렬******************
문제 설명
정수 n을 기준으로 n과 가까운 수부터 정렬하려고 합니다. 이때 n으로부터의 거리가 같다면 더 큰 수를 앞에 오도록 배치합니다. 정수가 담긴 배열 numlist와 정수 n이 주어질 때 numlist의 원소를 n으로부터 가까운 순서대로 정렬한 배열을 return하도록 solution 함수를 완성해주세요.

제한사항
1 ≤ n ≤ 10,000
1 ≤ numlist의 원소 ≤ 10,000
1 ≤ numlist의 길이 ≤ 100
numlist는 중복된 원소를 갖지 않습니다.
*********************************************************/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int big[10001];
int small[10001];
vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    
    for(auto num:numlist)
    {
        if(num == n)
        {
            answer.push_back(num);
        }
        else if(num > n)
        {
            big[num-n] = num;
        }
        else 
        {
            small[n-num] = num;
        }
    }
    
    for(int i=0; i<10001; i++)
    {
        if(big[i] != 0) answer.push_back(big[i]);
        if(small[i] != 0) answer.push_back(small[i]);
        
    }
    
    return answer;
}