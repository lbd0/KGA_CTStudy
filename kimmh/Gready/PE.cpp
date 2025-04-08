#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> students;

    for (int i = 1; i < n + 1; i++) {
        students.push_back(i);
    }

    for (auto lostStudent : lost) {
        if (find(students.begin(), students.end(), lostStudent) != students.end()) {
            //remove(students.begin(), students.end(), lostStudent);
            students.erase(find(students.begin(), students.end(), lostStudent));
        }
    }

    for (auto student : students) {
        cout << student;
    }
    cout << endl;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (auto lostStudent : lost) {
        int count = 0;
        for (int rev : reserve) {
            if (rev == lostStudent + 1 || rev == lostStudent - 1) {
                students.push_back(rev);
                reserve.erase(reserve.begin() + count);
                break;
            }
            count++;
        }
    }

    for (auto student : students) {
        cout << student;
    }

    return students.size();
}