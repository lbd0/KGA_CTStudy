#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(auto query:queries)
    {
        int min=1000001;
        bool check=false;

        for(int i=query[0]; i<=query[1]; i++)
        {
            if(arr[i]>query[2] && arr[i]<min) 
            {
                min=arr[i];
                check=true;
            }
        }

        if(!check) answer.push_back(-1);
        else answer.push_back(min);
    }
    
    return answer;
}
