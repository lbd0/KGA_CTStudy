#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int mul = 1;
    int sum = 0;
    for(int i = 0; i < num_list.size(); ++i){
        mul *= num_list[i];
        sum += num_list[i];
    }
    
    int sqr = (pow(sum, 2)); 
    if(mul > sqr){ answer = 0; }
    else if(mul < sqr){ answer = 1; }
    
    return answer;
}
