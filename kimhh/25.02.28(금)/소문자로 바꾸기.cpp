#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(auto& str:myString){
        str = isupper(str)? tolower(str):str;
    }
    answer = myString;
    return answer;
}
