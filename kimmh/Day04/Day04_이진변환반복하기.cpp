/*
    https://school.programmers.co.kr/learn/courses/30/lessons/70129
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string Binary(int intValue) {
    string tempString = "";

    while (intValue != 0) {
        tempString.insert(0, to_string(intValue % 2));
        intValue /= 2;
    }

    int tempStringLength = tempString.length();

    return tempString;
}

vector<int> solution(string s) {
    vector<int> answer;

    int count = 0;
    int deleteZeroCount = 0;

    int tempString = 0;

    while (true) {
        count++;
        tempString = 0;
        for (auto ins : s) {
            if (ins == '0') {
                deleteZeroCount++;
            }
            else {
                tempString += 1;
            }
        }

        if (tempString == 1) {
            answer.push_back(count);
            answer.push_back(deleteZeroCount);
            return answer;
        }

        s = Binary(tempString);
    }



    //while(s != "1") {
    //    
    //}


    return answer;
}