/*
Q. 주사위 게임 3

1부터 6까지 숫자가 적힌 주사위가 네 개 있습니다. 
네 주사위를 굴렸을 때 나온 숫자에 따라 다음과 같은 점수를 얻습니다.

네 주사위에서 나온 숫자가 모두 p로 같다면 1111 × p점을 얻습니다.
세 주사위에서 나온 숫자가 p로 같고 나머지 다른 주사위에서 나온 숫자가 q(p ≠ q)라면 (10 × p + q)2 점을 얻습니다.
주사위가 두 개씩 같은 값이 나오고, 나온 숫자를 각각 p, q(p ≠ q)라고 한다면 (p + q) × |p - q|점을 얻습니다.
어느 두 주사위에서 나온 숫자가 p로 같고 나머지 두 주사위에서 나온 숫자가 각각 p와 다른 q, r(q ≠ r)이라면 q × r점을 얻습니다.
네 주사위에 적힌 숫자가 모두 다르다면 나온 숫자 중 가장 작은 숫자 만큼의 점수를 얻습니다.
네 주사위를 굴렸을 때 나온 숫자가 정수 매개변수 a, b, c, d로 주어질 때, 얻는 점수를 return 하는 solution 함수를 작성해 주세요.
*/

#include <map>
#include <algorithm>
#include <cmath>

int solution(int a, int b, int c, int d) {
    std::map<int, int> dice;
    
    int p = 0, q = 0, r = 0;
    int answer = 0, type = 0;
    
    dice[a]++;
    dice[b]++;
    dice[c]++;
    dice[d]++;
    
    for (auto num : dice) {
        type = (type > num.second) ? type : num.second;
        
        switch (num.second) {
            case 4:
                return 1111 * num.first;
            case 3:
                p = num.first;
                break;
            case 2:
                if (p == 0) p = num.first;
                else        q = num.first;
                break;
            case 1:
                answer = std::min({a, b, c, d});
                if (q == 0) q = num.first;
                else        r = num.first;
                break;
        }
    }
    return (type == 3) ? pow((10 * p) + q, 2) : (type == 2) ? (((p + q) * (abs(p - q))) * !(bool)r) + (q *  r) : std::min({a, b, c, d});
}