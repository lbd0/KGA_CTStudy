#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    map<int, int> freq;
    vector<int> dice = {a, b, c, d};
    
    for(int num : dice) freq[num]++;
    
    switch(freq.size())
    {
        case 1:
            answer = 1111 * a;
            break;
        case 2:
           
            break;
        case 3:
            int n;
            int m;
            for(auto f : freq)
            {
                if(f.second == 1)
                {
                    if(q == 0) q = f.first;
                    else
                }
            }
            break;
        case 4:
            answer = *min_element(dice.begin(), dice.end());
            break;
    }
    
    return answer;
}
