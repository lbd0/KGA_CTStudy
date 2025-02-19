#include <string>
#include <vector>
using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    string stra = to_string(a);
    string strb = to_string(b);
    
    string strAnswerAB = stra + strb;
    string strAnswerBA = strb + stra;
    
    int intAnswerAB = stoi(strAnswerAB);
    int intAnswerBA = stoi(strAnswerBA);
    answer = max(intAnswerAB, intAnswerBA);
    
    return answer;
}
