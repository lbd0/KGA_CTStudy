#include <stack>
#include <string>
using namespace std;

bool solution(string s) {
    
    stack <char> ch;
    
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
      
        if (c == '(') {
            ch.push(c);
        } else { 
           
            if (!ch.empty() && ch.top() == '(') {
                ch.pop();
                
            } else {
                
                return false;
            }
        }
    }
    
    return ch.empty();
}
