// https://school.programmers.co.kr/learn/courses/30/lessons/181944

#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    cout << n << (n % 2 == 0 ? " is even" : " is odd");

    return 0;
}