#include <string>
#include <iostream>
using namespace std;

// ���ڿ� ���� p�� y�� ���� https://school.programmers.co.kr/learn/courses/30/lessons/12916?language=cpp

/*
���� ����
    �빮�ڿ� �ҹ��ڰ� �����ִ� ���ڿ� s�� �־����ϴ�. 
    s�� 'p'�� ������ 'y'�� ������ ���� ������ True, �ٸ��� False�� return �ϴ� solution�� �ϼ��ϼ���. 
    'p', 'y' ��� �ϳ��� ���� ���� �׻� True�� �����մϴ�. 
    ��, ������ ���� �� �빮�ڿ� �ҹ��ڴ� �������� �ʽ��ϴ�.

    ���� ��� s�� "pPoooyY"�� true�� return�ϰ� "Pyy"��� false�� return�մϴ�.

���ѻ���
    ���ڿ� s�� ���� : 50 ������ �ڿ���
    ���ڿ� s�� ���ĺ����θ� �̷���� �ֽ��ϴ�.
*/

bool solution(string s)
{
    int pCount = 0;
    int yCount = 0;

    for (auto str : s) {
        if (str == 'P' or str == 'p')
            pCount++;
        if (str == 'Y' or str == 'y')
            yCount++;
        cout << str << endl;
    }

    if (pCount == yCount)
        return true;
    return false;

}