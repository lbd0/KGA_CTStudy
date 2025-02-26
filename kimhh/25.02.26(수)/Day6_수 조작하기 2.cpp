#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    map<int, char> mNum = { {1, 'w'}, {-1, 's'}, {10, 'd'}, {-10, 'a'} };
    for (size_t i = 1; i < numLog.size(); ++i) {
        int log = numLog[i] - numLog[i - 1];
        answer += mNum[log];
    }
    return answer;
}
