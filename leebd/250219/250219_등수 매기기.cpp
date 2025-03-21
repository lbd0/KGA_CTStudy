/**************등수 매기기******************
문제 설명
영어 점수와 수학 점수의 평균 점수를 기준으로 학생들의 등수를 매기려고 합니다. 영어 점수와 수학 점수를 담은 2차원 정수 배열 score가 주어질 때, 영어 점수와 수학 점수의 평균을 기준으로 매긴 등수를 담은 배열을 return하도록 solution 함수를 완성해주세요.

제한사항
0 ≤ score[0], score[1] ≤ 100
1 ≤ score의 길이 ≤ 10
score의 원소 길이는 2입니다.
score는 중복된 원소를 갖지 않습니다.
*********************************************************/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    
    for(int i=0; i<score.size(); i++)
    {
        answer.push_back(1);
    }
    
    for(int i=0; i<score.size(); i++)
    {
        for(int j=0; j<score.size(); j++)
        {
            if(score[i][0]+score[i][1] > score[j][0]+score[j][1])
                answer[j]++;
        }
    }
    
    return answer;
}