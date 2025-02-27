/*
	https://school.programmers.co.kr/learn/courses/30/lessons/1845?language=cpp
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{  
    int count = 0;
    
    vector<int> tempVector;
    
    for(int i = 0; i < nums.size(); i++) {
        if(count < nums.size() / 2) {
            // 가져간 포켓몬의 갯수가 전체의 1/2보다 적고
            if(find(tempVector.begin(), tempVector.end(), nums[i]) == tempVector.end()) {
                // 가져간 적이 없는 포켓몬(번호)면 가져간다
                tempVector.push_back(nums[i]);
                ++count;
            }
        }
        else {
            break;
        }
    }
    
    return count;
}