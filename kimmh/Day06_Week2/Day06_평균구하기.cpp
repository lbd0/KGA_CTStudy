/*
	https://school.programmers.co.kr/learn/courses/30/lessons/12944
*/

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    int sum = 0;
    
    for(int i = 0; i < arr.size(); i ++) {
        sum += arr[i];
    }
    
    
    
    return double(sum) / arr.size();
}