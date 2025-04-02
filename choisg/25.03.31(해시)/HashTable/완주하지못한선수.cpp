#include <string>
#include <vector>
#include <unordered_map> //중복처리를 위해 map을 사용

using namespace std;

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
    using namespace std;

    string solution(vector<string> participant, vector<string> completion)
    {
      
        //완주자 이름이 몇번 등장했는지 기록.
        unordered_map<string, int> completionMap;
        for (int i = 0; i < completion.size(); i++)
        {
            string name = completion[i];

            if (completionMap.find(name) == completionMap.end())
            {   //name이 기존에 없었으면 새롭게 1을 추가
                completionMap[name] = 1;    
            }
            else
            {   //name이 이미 있었으면 카운트 증가
                completionMap[name]++;
            }
        }

        // 참가자를 돌면서 이름이 완주자 쪽에 없거나 카운트가 0이면 반환
        for (int i = 0; i < participant.size(); i++)
        {
             string currentName = participant[i];

            // 완주자 맵에서 찾기
            unordered_map<string, int>::iterator it = completionMap.find(currentName);
            if (it == completionMap.end())
            {
                // 완주자 목록에 아예 없는 이름 → 미완주자
                return currentName;
            }
            else
            {
                // 찾았지만 카운트가 0 이하라면 동명이인도 아닌 경우
                if (it->second <= 0)
                {
                    return currentName;
                }
                // 카운트가 남아있다면  1개 소모.
                it->second--;

     
            }
        }

}