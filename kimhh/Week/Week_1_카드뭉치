#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    int idx1 = 0;
    int idx2 = 0;
    
    for (const string& word : goal) {
        if (idx1 < cards1.size() && cards1[idx1] == word) {
            idx1++;
        }
        else if (idx2 < cards2.size() && cards2[idx2] == word) {
            idx2++;
        }
        else {
            answer = "No";
        }
    }
    return answer;
}
