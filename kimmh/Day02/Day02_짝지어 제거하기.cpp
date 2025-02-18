/*
    https://school.programmers.co.kr/learn/courses/30/lessons/12973
    스택을 사용해야 하는 문제였다
*/

#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    string temp = "";

    for (int i = 0; i < s.length(); i++) {
        if (temp.back() == s[i]) {
            temp.pop_back();
            //cout << "같음" << endl;
        }
        else {
            temp.push_back(s[i]);
            //cout << "다름" << endl;
        }
        //cout << "temp : " << temp << ". s : " << s << endl;
    }

    //cout << temp << endl;

    if (temp.empty()) {
        return 1;
    }
    else {
        return 0;
    }

}

/*
* 시행착오 1 시간복잡도 실패
int solution(string s)
{
    string temp = "";

    while (!s.empty()) {
        if (temp.back() == s.front()) {
            temp.pop_back();
        }
        else {
            temp.push_back(s.front());
        }
        s.erase(0, 1);
        if (s.length() == 0)
            break;
    }

    cout << temp << endl;

    return temp.length() == 0 ? 1 : 0;

}
*/
/* 
* 시행착오 2 시간복잡도 실패
int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.length() - 1; i++) {
        cout << s << " , " << i << endl;
        if (s[i] == s[i + 1]) {
            cout << "지우기 실행" << endl;
            s.erase(i, 2);
            i = -1;
            if (s.length() == 0) {
                break;
            }
        }
    }

    cout << s << endl;

    return s.empty() ? 1 : 0;

}

int main() {
    cout << solution("baabaa") << endl;

}
*/
