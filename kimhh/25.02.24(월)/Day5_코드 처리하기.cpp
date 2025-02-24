#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string ret;
    int mode = 0;

    for (int i = 0; i < code.size(); ++i) {
        if (code[i] == '1') { mode = 1 - mode; continue; }

        if (mode == 0) {
            if (i % 2 == 0) { ret.push_back(code[i]); }
        }
        else if (mode == 1) {
            if (i % 2 == 1) { ret.push_back(code[i]); }
        }
    }
    string answer = ret;
    if (ret.empty()) { answer = "EMPTY"; }
    return answer;
}
