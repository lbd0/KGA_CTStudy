#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.begin(), score.end(), greater<>());

    int iniValue = 0;
    while (iniValue + m <= score.size()) {  
        int appleBox = score[iniValue + m - 1]; 
        answer += appleBox * m; 
        iniValue += m; 
    }

    return answer;
}