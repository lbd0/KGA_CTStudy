/*
2.리스트 자르기
정수 n과 정수 3개가 담긴 리스트 slicer 그리고 정수 여러 개가 담긴 리스트 num_list가 주어집니다. slicer에 담긴 정수를 차례대로 a, b, c라고 할 때, n에 따라 다음과 같이 num_list를 슬라이싱 하려고 합니다.

n = 1 : num_list의 0번 인덱스부터 b번 인덱스까지
n = 2 : num_list의 a번 인덱스부터 마지막 인덱스까지
n = 3 : num_list의 a번 인덱스부터 b번 인덱스까지
n = 4 : num_list의 a번 인덱스부터 b번 인덱스까지 c 간격으로
올바르게 슬라이싱한 리스트를 return하도록 solution 함수를 완성해주세요.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> SliceVector(int a, int b, int c, vector<int> list)
{
    vector<int> answer;
    if(c == 0)
    {
        for(int i = a;i <= b; ++i)
        {
            answer.push_back(list.at(i));        
        }
    }
    else
    {
        for(int i = a; i <= b; i += c)
        {
            answer.push_back(list.at(i));
        }
    }
    
    return answer;
}

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    
    switch(n)
    {
        case 1:
            answer = SliceVector(0,slicer.at(1), 0, num_list);
            break;
        case 2:
            answer = SliceVector(slicer.at(0), num_list.size()-1, 0, num_list);    
            break;
        case 3:
            answer = SliceVector(slicer.at(0), slicer.at(1), 0, num_list);
            break;
        case 4:
            answer = SliceVector(slicer.at(0), slicer.at(1), slicer.at(2), num_list);
            break;
    }
    
