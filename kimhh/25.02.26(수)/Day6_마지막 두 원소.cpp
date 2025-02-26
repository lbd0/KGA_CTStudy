#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    answer = num_list;

    int s = num_list.size() - 1;
    int fin = num_list[s] - num_list[s - 1];

    answer.push_back(fin > 0 ? fin : num_list[s] * 2);
    return answer;
}
