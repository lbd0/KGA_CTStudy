/**************A로 B 만들기******************
문제 설명
문자열 before와 after가 매개변수로 주어질 때, before의 순서를 바꾸어 after를 만들 수 있으면 1을, 만들 수 없으면 0을 return 하도록 solution 함수를 완성해보세요.

제한사항
0 < before의 길이 == after의 길이 < 1,000
before와 after는 모두 소문자로 이루어져 있습니다.
*********************************************************/
#include <string>
#include <vector>
#include <map>

using namespace std;


int solution(string before, string after) {

    map<int,int> mb;
    map<int,int> ma;
    pair<map<int,int>::iterator, bool> pr;
    
    for(auto b:before)
    {
        pr = mb.insert(pair<int,int>(b,1));
        if(!pr.second) mb[b]++;
    }
    
    for(auto a:after)
    {
        pr = ma.insert(pair<int,int>(a, 1));
        if(!pr.second) ma[a]++;
    }
    
    
    
    for(map<int,int>::iterator it = mb.begin(); it != mb.end(); it++)
    {
        if(ma.find(it->first) == ma.end()) return 0;
        for(map<int,int>::iterator ita = ma.begin(); ita != ma.end(); ita++)
        {
            if(it->first == ita->first)
            {
                if(it->second != ita->second)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}