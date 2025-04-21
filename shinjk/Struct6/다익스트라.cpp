#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    vector<vector<pair<int,int>>>graph(N+1);
    
    for(auto r:road) //도로정보 넣기
    {
        int a=r[0];
        int b=r[1];
        int time=r[2];
        graph[a].push_back({b,time}); 
        graph[b].push_back({a,time}); //양방향이니까 반대도 저장
    }
    
    vector<int> minTime(N+1, 500001); //시간 저장 배열. 처음엔 최댓값보다 1 크게 저장
    minTime[1]=0; //시작점은 시간0
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq; //작은시간부터 처리됨
    pq.push({0,1}); //시간 0, 마을 1
    
    while(!pq.empty())
    {
        int time=pq.top().first;
        int town=pq.top().second;
        pq.pop();
        

	//이미 더 빠른 길이 있으면 무시
        if(time>minTime[town])continue;
        
	// 연결된 마을들 확인
        for(auto next:graph[town])
        {
            int nextTown=next.first;
            int nextTime=next.second;
            
	   //더 짧은 시간으로 갈 수 있으면ㄴ 업데이트
            if(minTime[nextTown]>time+nextTime)
            {
                minTime[nextTown]=time+nextTime;
                pq.push({minTime[nextTown],nextTown});
            }
        }
    }
    
   //K시간 이하의 마을만 세기
    for(int i=1;i<=N;++i)
    {
        if(minTime[i]<=K)answer++;
    }

    return answer;
}