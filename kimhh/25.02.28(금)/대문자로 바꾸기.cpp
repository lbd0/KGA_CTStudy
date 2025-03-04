#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(auto& str:myString){
        str = islower(str)? toupper(str): str;
    }
    answer = myString;
    return answer;
}
