#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    
    my_string.erase(s, overwrite_string.length());
    my_string.insert(s, overwrite_string);
    answer = my_string;
    return answer;
}

/****************************************************************************************
다른 사람을 보니.. replace를 사용하고, length대신 size를 사용한다.

#include <string>
using namespace std;
string solution(string my_string, string overwrite_string, int s) {
    my_string.replace(s, overwrite_string.length(), overwrite_string); // 특정 위치에서 덮어쓰기
    return my_string;
}

replace
문자열.replace(시작 인덱스, 덮어쓸 길이, 새 문자열);
****************************************************************************************/
