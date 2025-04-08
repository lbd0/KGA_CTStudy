#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> temp(n,1); //n개의 원소가 1인 vector
    
    for(int i=0;i<lost.size();++i)
    {
        temp[lost[i]-1]--; //lost[i]값의 -1 인덱스를 -1
        
    }
    for(int i=0; i<reserve.size();++i)
    {
        temp[reserve[i]-1]++; //reserve[i]값의 -1 인덱스를 -1
    }

    
    for(int i=0;i<temp.size();++i)
    {
        if(i==0) //첫번째 학생 예외
        {
            if(temp[i]==2&&temp[i+1]==0) //자신이 2개 갖고 있고, 뒷친구가 없는 경우
            {
                temp[i]=1;
                temp[i+1]=1;
            }
        }
        else if(i==temp.size()-1) //마지막 학생 예외
        {
            if(temp[i]==2&&temp[i-1]==0) //자신이 2개 갖고 있고, 앞친구가 없는 경우
            {
                temp[i]=1;
                ++answer;
            }
        }
        else if(temp[i]==2) //그 외에 자신이 2개 갖고 있는 경우,
        {
            if(temp[i-1]==0) //앞친구가 없는 경우
            {
                ++answer;
                temp[i]=1;
            }
            else if(temp[i+1]==0) //뒷친구가 없는 경우
            {
                temp[i+1]=1;
                temp[i]=1;
            }
        }
        if(temp[i]>=1) //친구한테 주고 난 후 판별
        {
            ++answer;
        }
    }

    
    return answer;
}