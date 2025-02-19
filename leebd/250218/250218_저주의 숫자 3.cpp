/**************저주의 숫자 3******************
문제 설명
3x 마을 사람들은 3을 저주의 숫자라고 생각하기 때문에 3의 배수와 숫자 3을 사용하지 않습니다. 3x 마을 사람들의 숫자는 다음과 같습니다.

10진법	3x 마을에서 쓰는 숫자	10진법	3x 마을에서 쓰는 숫자
1	1	6	8
2	2	7	10
3	4	8	11
4	5	9	14
5	7	10	16
정수 n이 매개변수로 주어질 때, n을 3x 마을에서 사용하는 숫자로 바꿔 return하도록 solution 함수를 완성해주세요.

제한사항
1 ≤ n ≤ 100

*********************************************************/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> nums;
    int number = 1;
    
    for(int i=0; i<n; i++)
    {
        do
        {
            if(number == 30) number = 39;
            if(number >= 130 && number < 140) number = 140;
            
            if(number%10 != 3 && number%3 != 0) break;
            
            number++;
        } while(true);
        nums.push_back(number);
        number++;
        cout << nums[i] << " ";
        
    }
    
    answer = nums[n-1];
    
    return answer;
}