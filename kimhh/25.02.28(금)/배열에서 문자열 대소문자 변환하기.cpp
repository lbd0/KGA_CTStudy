#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    for (size_t i = 0; i < strArr.size(); ++i) {
        if (i % 2 == 0) {
            transform(strArr[i].begin(), strArr[i].end(), strArr[i].begin(), ::tolower);
        } else {
            transform(strArr[i].begin(), strArr[i].end(), strArr[i].begin(), ::toupper);
        }
    }
    answer = strArr;
    return answer;
}
