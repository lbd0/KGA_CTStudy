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
//}//�ð� ����


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
//    return answer;//����
//}

#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int>um;//unordered_map ���

    for (int i = 0; i < participant.size(); ++i)
    {
        if (um.find(participant[i]) != um.end())//���������� �ִٸ�
        {
            um[participant[i]]++;//�������� int ����
        }
        else
        {
            um[participant[i]] = 1;//���ٸ�, int 1
        }
    }
    for (int i = 0; i < completion.size(); ++i)
    {
        if (um.find(completion[i]) != um.end())//�̸� �߿� �����ڰ� �ִٸ�
        {
            um[completion[i]]--;//int 1����
        }
    }

    for (auto& iter : um)
    {
        if ((iter.second) == 1)//���� 1�� ���
        {
            answer = iter.first;//�̸�
        }
    }



    return answer;
}