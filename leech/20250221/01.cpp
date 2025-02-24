/*
Q. 이어 붙인 수

정수가 담긴 리스트 num_list가 주어집니다. 
num_list의 홀수만 순서대로 이어 붙인 수와 
짝수만 순서대로 이어 붙인 수의 합을 
return하도록 solution 함수를 완성해주세요.
*/

#include <string>
#include <vector>

int solution(std::vector<int> num_list) {
    std::string odd = "", even = "";
    
    for(int n : num_list)
    {
        n % 2 == 0 ? even += std::to_string(n) : odd += std::to_string(n);
    }
    
    return std::stoi(even) + std::stoi(odd);
}