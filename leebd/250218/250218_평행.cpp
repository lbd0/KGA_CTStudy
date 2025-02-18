/**************평행******************
문제 설명
점 네 개의 좌표를 담은 이차원 배열  dots가 다음과 같이 매개변수로 주어집니다.

[[x1, y1], [x2, y2], [x3, y3], [x4, y4]]
주어진 네 개의 점을 두 개씩 이었을 때, 두 직선이 평행이 되는 경우가 있으면 1을 없으면 0을 return 하도록 solution 함수를 완성해보세요.

제한사항
dots의 길이 = 4
dots의 원소는 [x, y] 형태이며 x, y는 정수입니다.
0 ≤ x, y ≤ 100
서로 다른 두개 이상의 점이 겹치는 경우는 없습니다.
두 직선이 겹치는 경우(일치하는 경우)에도 1을 return 해주세요.
임의의 두 점을 이은 직선이 x축 또는 y축과 평행한 경우는 주어지지 않습니다.
*********************************************************/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> dots) {

    vector<double> Len;
    
    for(int i=0; i<dots.size()-1; i++)
    {
        for(int j=i+1; j<dots.size(); j++)
        {
            Len.push_back((double)abs(dots[i][1] - dots[j][1])/(double)abs(dots[i][0] - dots[j][0]));   
        }
    }
    
    for(int i=0; i<Len.size()/2; i++)
    {
        if(Len[i]==Len[Len.size()-1-i]) return 1;
    }
    
    return 0;
}