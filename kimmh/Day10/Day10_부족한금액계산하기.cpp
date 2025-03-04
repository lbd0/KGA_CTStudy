/*
	https://school.programmers.co.kr/learn/courses/30/lessons/82612?language=cpp
*/
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    long long priceSum = 0;
    
    int temp = price;
    
    for(int i = 1; i < count + 1; i++) {
        priceSum += price;
        price += temp;
    }
    
    if(priceSum - money > 0) {
        return priceSum - money;
    }
    else {
        return 0;
    }
    
    return answer;
}