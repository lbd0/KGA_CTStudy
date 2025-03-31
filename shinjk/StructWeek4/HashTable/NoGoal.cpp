//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(vector<string> participant, vector<string> completion) {
//    string answer = "";
//    int count = 0;
//
//    while (participant.size() != 1)
//    {
//        for (int i = 0; i < participant.size(); ++i)
//        {
//            if (participant[i] == completion[completion.size() - 1])
//            {
//                participant.erase(participant.begin() + i);
//                completion.pop_back();
//                break;
//            }
//
//        }
//    }
//
//    answer = participant[0];
//    return answer;
//}//시간 부족


//#include <string>
//#include <vector>
//#include<unordered_set>
//
//using namespace std;
//
//string solution(vector<string> participant, vector<string> completion) {
//    string answer = "";
//    unordered_set<string>us;
//
//    for (int i = 0; i < completion.size(); ++i)
//    {
//        us.insert(completion[i]);
//    }
//    while (participant.size() != 1)
//    {
//        if (us.find(participant[0]) == us.end())
//        {
//            answer = participant[0];
//            break;
//        }
//        else
//        {
//            us.erase(participant[0]);
//            participant.erase(participant.begin());
//
//
//        }
//    }
//
//
//    return answer;//오류
//}

#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int>um;//unordered_map 사용

    for (int i = 0; i < participant.size(); ++i)
    {
        if (um.find(participant[i]) != um.end())//동명이인이 있다면
        {
            um[participant[i]]++;//동명이인 int 증가
        }
        else
        {
            um[participant[i]] = 1;//없다면, int 1
        }
    }
    for (int i = 0; i < completion.size(); ++i)
    {
        if (um.find(completion[i]) != um.end())//이름 중에 완주자가 있다면
        {
            um[completion[i]]--;//int 1감소
        }
    }

    for (auto& iter : um)
    {
        if ((iter.second) == 1)//값이 1인 사람
        {
            answer = iter.first;//이름
        }
    }



    return answer;
}