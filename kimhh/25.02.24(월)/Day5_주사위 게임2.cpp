#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b, int c) {
    int answer = 0;
    int sum = (a + b + c);
    int sum2 = (pow(a, 2) + pow(b, 2) + pow(c,2));
    int sum3 = (pow(a, 3) + pow(b, 3) + pow(c,3));
    
    if(a != b && b != c && c != a){
        answer = sum;
    }
    else if(a == b && b == c && c == a){
        answer = sum * sum2 * sum3;
    }
    else{
        answer = sum * sum2;
    }
    return answer;
}
