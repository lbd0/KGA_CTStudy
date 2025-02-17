https://school.programmers.co.kr/learn/courses/30/lessons/181949?language=cpp

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for(char &c : str)
    {
        if(isupper(c)) c = tolower(c);
        else if(islower(c)) c = toupper(c);
    }
    cout << str;
    
    return 0;
}
