#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> partMap;
    
     for(string person : participant)
     {
         // 현재 참가자 중에 값이 존재한다면
         if(partMap.find(person) != partMap.end())
         {
             //해당되는 값에 1을 더해서 넣어준다.
             int count = partMap[person];
             partMap[person] = count + 1;
         }
         else
         {
           // 그게 아니라면 1만 넣어준다.
            partMap[person] = 1;
         }
     }

   
    for(string complete : completion)
    {
        if(partMap.find(complete) != partMap.end())
        {
            //완주자가  있다면 해당 값에 1을 빼준다.          
            int count = partMap[complete];
            partMap[complete] = count -1;
        }
        
    }
    
    for(auto it = partMap.begin(); it != partMap.end();++it)
    {
        //만약 value 값이 0이 아니라면 ,즉 참가한 만큼 완주하지 못한 사람이 있다면
        if(it->second != 0)
        {
          // 그 한명을 값으로 넣는다.
            answer = it->first;
        }
    }
    
    
    return answer;
}
