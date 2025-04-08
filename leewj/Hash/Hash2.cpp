#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    std::unordered_map<string, int> map;

    for (const string& str : participant) {
        ++map[str];
    }

    for (const string& str : completion) {
        if (--map[str] <= 0) {
            map.erase(str);
        }
    }

    for (auto& val : map) {
        answer = val.first;
    }

    return answer;
}