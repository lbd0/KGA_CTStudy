// https://school.programmers.co.kr/learn/courses/30/lessons/181949

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >= 97) {
            str[i] -= 32;
        }
        else {
            str[i] += 32;
        }
    }

    cout << str;

    return 0;
}