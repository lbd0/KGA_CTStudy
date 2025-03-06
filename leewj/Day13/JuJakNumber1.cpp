// https://school.programmers.co.kr/learn/courses/30/lessons/181926

#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    for (const char& val : control) {
        switch (val) {
        case 'w':
            ++n;
            break;
        case 's':
            --n;
            break;
        case 'a':
            n -= 10;
            break;
        case 'd':
            n += 10;
            break;
        default:
            break;
        }
    }

    return n;
}