// https://school.programmers.co.kr/learn/courses/30/lessons/181940

#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string my_string, int k) {
    stringstream stream;

    for (int i = 0; i < k; ++i) {
        stream << my_string;
    }

    return stream.str();
}