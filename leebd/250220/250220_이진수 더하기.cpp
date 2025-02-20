/**************이진수 더하기******************
문제 설명
이진수를 의미하는 두 개의 문자열 bin1과 bin2가 매개변수로 주어질 때, 두 이진수의 합을 return하도록 solution 함수를 완성해주세요.

제한사항
return 값은 이진수를 의미하는 문자열입니다.
1 ≤ bin1, bin2의 길이 ≤ 10
bin1과 bin2는 0과 1로만 이루어져 있습니다.
bin1과 bin2는 "0"을 제외하고 0으로 시작하지 않습니다.
*********************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    
    int num1 = stoi(bin1);
    int num2 = stoi(bin2);
    int sum = 0, carry = 0;
    
    if(num1 == 0 && num2 == 0) answer = "0";
    
    do
    {
        if(num1 == 0 && num2 == 0) break;
        
        sum = (num1%10) + (num2%10) + carry;
        
        if(sum == 2)
        {
            sum = 0;
            carry = 1;
        }
        else if(sum == 3)
        {
            sum = 1;
            carry = 1;
        }
        else carry = 0;
        
        answer += to_string(sum);
        
        num1 /= 10;
        num2 /= 10;
        
    } while(true);
    
    if(carry != 0) answer += to_string(carry);
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}