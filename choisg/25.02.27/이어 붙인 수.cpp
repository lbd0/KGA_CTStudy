정수가 담긴 리스트 num_list가 주어집니다. num_list의 홀수만 순서대로 이어 붙인 수와 짝수만 순서대로 이어 붙인 수의 합을 return하도록 solution 함수를 완성해주세요.

제한사항
2 ≤ num_list의 길이 ≤ 10
1 ≤ num_list의 원소 ≤ 9
num_list에는 적어도 한 개씩의 짝수와 홀수가 있습니다.
입출력 예
num_list	result
[3, 4, 5, 2, 1]	393
[5, 7, 8, 3]	581
입출력 예 설명
입출력 예 #1

홀수만 이어 붙인 수는 351이고 짝수만 이어 붙인 수는 42입니다. 두 수의 합은 393입니다.
입출력 예 #2

홀수만 이어 붙인 수는 573이고 짝수만 이어 붙인 수는 8입니다. 두 수의 합은 581입니다.

답
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    string evenNum = "";
    string oddNum = "";

    for (int i = 0; i< num_list.size(); i++ )
    {
        if (num_list[i] % 2 == 0) {
            oddNum += to_string(num_list[i]);
        }
        else{
            evenNum += to_string(num_list[i]);
        }
    }

    answer = stoi(evenNum) + stoi(oddNum);
    return answer;
}