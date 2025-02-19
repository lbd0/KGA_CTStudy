/*
	https://school.programmers.co.kr/learn/courses/30/lessons/81301#
*/

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    while (true) {
        if (s.find("zero") != string::npos) {
            s.replace(s.find("zero"), 4, "0");
        }
        else if (s.find("one") != string::npos) {
            s.replace(s.find("one"), 3, "1");
        }
        else if (s.find("two") != string::npos) {
            s.replace(s.find("two"), 3, "2");
        }
        else if (s.find("three") != string::npos) {
            s.replace(s.find("three"), 5, "3");
        }
        else if (s.find("four") != string::npos) {
            s.replace(s.find("four"), 4, "4");
        }
        else if (s.find("five") != string::npos) {
            s.replace(s.find("five"), 4, "5");
        }
        else if (s.find("six") != string::npos) {
            s.replace(s.find("six"), 3, "6");
        }
        else if (s.find("seven") != string::npos) {
            s.replace(s.find("seven"), 5, "7");
        }
        else if (s.find("eight") != string::npos) {
            s.replace(s.find("eight"), 5, "8");
        }
        else if (s.find("nine") != string::npos) {
            s.replace(s.find("nine"), 4, "9");
        }
        else {
            break;
        }
    }

    return stoi(s);
}