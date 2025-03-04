// https://school.programmers.co.kr/learn/courses/30/lessons/181941

#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(vector<string> arr) {
    stringstream stream;

    for (const string& str : arr) {
        stream << str;
    }

    return stream.str();
}