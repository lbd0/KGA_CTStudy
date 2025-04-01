#include <string>
#include <vector>
#include <unordered_map> //�ߺ�ó���� ���� map�� ���

using namespace std;

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
    using namespace std;

    string solution(vector<string> participant, vector<string> completion)
    {
      
        //������ �̸��� ��� �����ߴ��� ���.
        unordered_map<string, int> completionMap;
        for (int i = 0; i < completion.size(); i++)
        {
            string name = completion[i];

            if (completionMap.find(name) == completionMap.end())
            {   //name�� ������ �������� ���Ӱ� 1�� �߰�
                completionMap[name] = 1;    
            }
            else
            {   //name�� �̹� �־����� ī��Ʈ ����
                completionMap[name]++;
            }
        }

        // �����ڸ� ���鼭 �̸��� ������ �ʿ� ���ų� ī��Ʈ�� 0�̸� ��ȯ
        for (int i = 0; i < participant.size(); i++)
        {
             string currentName = participant[i];

            // ������ �ʿ��� ã��
            unordered_map<string, int>::iterator it = completionMap.find(currentName);
            if (it == completionMap.end())
            {
                // ������ ��Ͽ� �ƿ� ���� �̸� �� �̿�����
                return currentName;
            }
            else
            {
                // ã������ ī��Ʈ�� 0 ���϶�� �������ε� �ƴ� ���
                if (it->second <= 0)
                {
                    return currentName;
                }
                // ī��Ʈ�� �����ִٸ�  1�� �Ҹ�.
                it->second--;

     
            }
        }

}