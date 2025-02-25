/*
	https://school.programmers.co.kr/learn/courses/30/lessons/176963?language=cpp
*/

#include <string>
#include <vector>
#include <map>


using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> nameYearning;
    
    for(int i =0; i < name.size(); i++) {
        nameYearning.insert(pair<std::string, int>(name[i], yearning[i]));
    }
    
    for(auto photoPeople : photo) {
        int mScore = 0;
        for(auto photoPerson : photoPeople) {
            if(nameYearning.find(photoPerson) != nameYearning.end()) {
                mScore += nameYearning.at(photoPerson);
            }
        }
        answer.push_back(mScore);
    }

    
    
    
    
    return answer;
}