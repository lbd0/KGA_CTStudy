/*
    https://school.programmers.co.kr/learn/courses/30/lessons/17681
    비트연산으로 간단하게 풀이한 사람들을 보고 할 말을 잃었다
    다른 사람의 답안을 보니 좋은 풀이는 아닌거 같다
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/// <summary>
/// 이진수를 구하는 함수
/// </summary>
/// <param name="n">이진수의 길이</param>
/// <param name="intValue">이진수로 구할 값</param>
/// <returns>intValue를 n자리 이진수로 변환한 값</returns>
string Binary(int n, int intValue) {
    string tempString = "";

    while (intValue != 0) {
        tempString.insert(0, to_string(intValue % 2));
        intValue /= 2;
    }

    int tempStringLength = tempString.length();

    if (tempString.length() < n) {
        for (int i = 0; i < n - tempStringLength; i++) {
            tempString.insert(0, "0");
        }
    }

    return tempString;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> map1;
    vector<string> map2;

    for (int temp : arr1) {
        map1.push_back(Binary(n, temp));
    }

    for (int temp : arr2) {
        map2.push_back(Binary(n, temp));
    }

    string temp = "";

    for (int i = 0; i < n; i++) {
        temp = "";
        for (int j = 0; j < n; j++) {
            if (map1[i][j] == map2[i][j] && map1[i][j] == '0') {
                temp += " ";
            }
            else {
                temp += "#";
            }
        }
        answer.push_back(temp);
    }

    return answer;
}