/*
	https://school.programmers.co.kr/learn/courses/30/lessons/12951?language=cpp
*/

#include string
#include vector
#include sstream

using namespace std;

string solution(string s) {
    string answer = ;
    
    string temp = ;
    
    for(auto word  s) {
        temp += tolower(word);
    }
    
    istringstream iss(temp);             
    string buffer;
    
    while (getline(iss, buffer, ' ')) {
        buffer[0] = toupper(buffer[0]);
        answer += buffer +  ;
    }
    
    if(s.size()  answer.size()) {
        answer.pop_back();    
    }
    
    
    return answer;
}