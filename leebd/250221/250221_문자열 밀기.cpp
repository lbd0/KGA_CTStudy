/**************문자열 밀기******************
문제 설명
문자열 "hello"에서 각 문자를 오른쪽으로 한 칸씩 밀고 마지막 문자는 맨 앞으로 이동시키면 "ohell"이 됩니다. 이것을 문자열을 민다고 정의한다면 문자열 A와 B가 매개변수로 주어질 때, A를 밀어서 B가 될 수 있다면 밀어야 하는 최소 횟수를 return하고 밀어서 B가 될 수 없으면 -1을 return 하도록 solution 함수를 완성해보세요.

제한사항
0 < A의 길이 = B의 길이 < 100
A, B는 알파벳 소문자로 이루어져 있습니다.
*********************************************************/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string A, string B) {
    int answer = 0;

    int index = A.size();

    string original = A;

    if (A.compare(B) == 0)
    {
        return 0;
    }

    do
    {
        string temp = A.back() + A;
        temp.pop_back();
        cout << temp;
        ++answer;

        if (temp.compare(B) == 0) break;

        if (temp.compare(original) == 0) return -1;
        A = temp;

    } while (true);

    return answer;
}