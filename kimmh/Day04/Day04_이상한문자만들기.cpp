#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";

    istringstream iss(s);
    string buffer;
    vector<string> result;

    while (getline(iss, buffer, ' ')) {
        result.push_back(buffer);
    }

    for (auto word : result) {
        for (int i = 0; i < word.size(); i++) {
            if (i % 2 == 0) {
                answer += toupper(word[i]);
            }
            else {
                answer += tolower(word[i]);
            }
        }
        answer += " ";
    }

    answer.pop_back();

    if (s.size() > answer.size()) {
        for (int i = 0; i < s.size() - answer.size(); i++) {
            answer += " ";
        }
    }

    return answer;
}