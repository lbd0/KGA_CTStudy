#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for (const auto& query : queries) {
        int i = query[0], j = query[1];
        swap(arr[i], arr[j]);
    }
    answer = arr;
    return answer;
}
