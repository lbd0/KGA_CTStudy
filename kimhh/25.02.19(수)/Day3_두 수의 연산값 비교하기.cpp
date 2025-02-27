#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int strab = stoi(to_string(a)+to_string(b));
    int intab = 2 * a * b;
    
    if(strab < intab){
        answer = intab;
    }
    else{
        answer = strab;
    }
    return answer;
}
