/*
1부터 6까지 숫자가 적힌 주사위가 네 개 있습니다. 네 주사위를 굴렸을 때 
나온 숫자에 따라 다음과 같은 점수를 얻습니다.

네 주사위에서 나온 숫자가 모두 p로 같다면 1111 × p점을 얻습니다.
세 주사위에서 나온 숫자가 p로 같고 나머지 다른 주사위에서 나온 숫자가 q(p ≠ q)라면
 (10 × p + q)2 점을 얻습니다.
주사위가 두 개씩 같은 값이 나오고, 나온 숫자를 각각 p, q(p ≠ q)라고 한다면
 (p + q) × |p - q|점을 얻습니다.
어느 두 주사위에서 나온 숫자가 p로 같고 나머지 두 주사위에서 
나온 숫자가 각각 p와 다른 q, r(q ≠ r)이라면 q × r점을 얻습니다.
네 주사위에 적힌 숫자가 모두 다르다면 나온 숫자 중 
가장 작은 숫자 만큼의 점수를 얻습니다.
네 주사위를 굴렸을 때 나온 숫자가 정수 매개변수 a, b, c, d로 주어질 때,
 얻는 점수를 return 하는 solution 함수를 작성해 주세요.
*/


#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    
    map<int,int> dice;
    dice[a]++;
    dice[b]++;
    dice[c]++;
    dice[d]++;
    
    if(dice[a]==4)//4개 다 똑같음
    {
        answer=a*1111;
    }
    else if(dice[a]==1 && dice[b]==1 && dice[c]==1)//4개 다 다름
    {
        int min=7;
     
        for(auto itr= dice.begin(); itr!=dice.end(); ++itr)
        {
            if(itr->first < min)
            {
                min = itr->first;
            }
            
        }
        answer=min;
    }
    else if(dice[a]==3 || dice[b]==3 || dice[c]==3 || dice[d]==3)//3+1
    {
        int p=0;
        int q=0;
        for(auto itr= dice.begin(); itr!=dice.end(); ++itr)
        {
            switch(itr->second)
            {
                case 1: 
                    q=itr->first;
                    break;
                case 2:
                    break;
                case 3:
                    p=itr->first;
            }
        }
        
        answer=pow((10*p+q),2);
    }
    else if(dice[a]==2 && dice[b]==2 && dice[c]==2)//2+2
    {
        if(a==b)
        {
            answer=(a+c)*abs(a-c);
        }
        else
        {
            answer=(a+b)*abs(a-b);
        }
    }
    else if(dice[a]==2 || dice[b]==2 || dice[c]==2 || dice[d]==2)
    {
        int temp=1;
        for(auto itr=dice.begin(); itr!=dice.end(); ++itr)
        {
            switch(itr->second)
            {
                case 1: 
                    temp*=itr->first;
                    break;
            }
        }
        answer=temp;

    }
    
    
    return answer;
}