/*
	https://school.programmers.co.kr/learn/courses/30/lessons/12981
*/



#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    // 끝말잇기에서 단어를 말해야 하는 플레이어 번호
    int playerNum = 0;
    
    // 현재 턴
    int turn = 1;   
    
    // 사용한 단어를 담는 임시 백터
    vector<string> tempVector;
    
    // 하나 담아줌
    tempVector.push_back(words[0]);
    
    // 다음 플레이어 차례
    playerNum++;
    
    for(int i = 1; i < words.size(); i++) {
        playerNum++;
        if(find(tempVector.begin(), tempVector.end(), words[i]) != tempVector.end()) {
            // 이미 사용한 단어 있음, <algorithm>의 find는 없는 단어일 경우 tempVector.end()를 반환함
            cout << "이미 사용한 단어" << endl;
            answer.push_back(playerNum);
            answer.push_back(turn);
            return answer;
        }
        else {
            // 이미 사용한 단어는 아님
            if(tempVector.back().back() == words[i].front()) {
                // 마지막 단어의 마지막과 새로운 단어의 앞글자가 같음 
                cout << "옳은 단어" << endl;
                tempVector.push_back(words[i]);
            }
            else {
                // 마지막 단어의 마지막과 새로운 단어의 앞글자가 다름
                cout << "옳은 단어가 아님" << endl;
                answer.push_back(playerNum);
                answer.push_back(turn);
                return answer;
            }
        }
        if(playerNum % n == 0) {
            turn++;
            playerNum = 0;
        }
    }
    
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}