#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    int answer = 0;

    for (auto grade : control) {
        switch (grade) {
        case 'w': n += 1; break;
        case 's': n -= 1; break;
        case 'd': n += 10; break;
        case 'a': n -= 10; break;
        }
    }
    answer = n;
    return answer;
}
