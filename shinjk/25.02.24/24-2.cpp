/*
정수 배열 numbers와 정수 num1, num2가 매개변수로 주어질 때,
 numbers의 num1번 째 인덱스부터 num2번째 인덱스까지 자른 정수 배열을
 return 하도록 solution 함수를 완성해보세요.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2) {
    vector<int> answer;
    for(int i=num1; i<num2+1;i++)
    {
        answer.push_back(numbers[i]);
    }
    return answer;
}