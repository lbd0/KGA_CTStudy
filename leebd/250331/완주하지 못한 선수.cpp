/**************완주하지 못한 선수******************
문제 설명
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

제한사항
마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
completion의 길이는 participant의 길이보다 1 작습니다.
참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
참가자 중에는 동명이인이 있을 수 있습니다.
*********************************************************/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> umap;        // 해시 테이블로 구현된 unordered map

    for (auto p : participant)              // 참가자를 맵에 다 넣음
    {
        umap[p]++;
    }

    for (auto c : completion)               // 완주한 사람들도 맵에 다 넣음
    {
        umap[c]++;
    }

    for (auto i = umap.begin(); i != umap.end(); ++i)
    {
        if (i->second % 2 != 0)         // 맵을 돌면서 value 값이 짝수가 아니라면 완주하지 못한 선수임!!
        {
            answer = i->first;
            break;
        }
    }
    
    return answer;
}