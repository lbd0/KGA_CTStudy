#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end());
    queue<int> q;

    for (int s : score) {
        q.push(s);
    }
    
    for (int i = 0; i < score.size() % m; ++i) {
        q.pop();
    }
    
    vector<int> boxs;
    
    int count = 0;
    while (!q.empty()) {
        if(count % m == 0) {
            boxs.push_back(q.front());
        }
        q.pop();
        count++;
    }
    
    for(int box : boxs) {
        answer += box * m;
    }
    
    return answer;
}