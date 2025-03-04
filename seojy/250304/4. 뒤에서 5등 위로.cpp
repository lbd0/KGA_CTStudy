/*
4. 뒤에서 5등 위로
정수로 이루어진 리스트 num_list가 주어집니다. num_list에서 가장 작은 5개의 수를 제외한 수들을 오름차순으로 담은 리스트를 return하도록 solution 함수를 완성해주세요.

*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int temp = 0;
    
    for(int i = 0; i < num_list.size();i++)
    {
        for(int n = 0; n < num_list.size();n++)
        {
            if(num_list.at(i) < num_list.at(n))
            {
                temp = num_list.at(i);
                num_list.at(i) = num_list.at(n);
                num_list.at(n) = temp;
            }
        }
    }
    
    for(int i = 5; i < num_list.size();i++)
    {
        answer.push_back(num_list.at(i));
    }
    
    
    return answer;
}
