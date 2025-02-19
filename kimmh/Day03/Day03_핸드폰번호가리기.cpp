/*
    https://school.programmers.co.kr/learn/courses/30/lessons/12948
*/

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string temp;

    for (int i = 0; i < phone_number.size() - 4; i++) {
        temp += "*";
    }

    phone_number.replace(0, phone_number.size() - 4, "");

    return temp.append(phone_number);
}