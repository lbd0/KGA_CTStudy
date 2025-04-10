/////////////////////////////////////////////////////////////////////
vscode랑 코드 실행에서는 맞는데 답안제출하면 틀리게 나와요.
왠지는 알겠는데 일단 이렇게만 올려봐유..
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //find()라는 것을 써보고 싶어서 추가했는데 그냥 안씀요.

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    // 체육복 도둑맞은 칠칠맞은 녀석들 집단 lost에서 한 명씩 데려옴
    for (int l : lost)
    {
        // 체육복 두개씩 있는 부자 친구들 reserve에서 한 명씩 데려옴(사실 얘네가 훔쳐간거아님?!)
        for (int r : reserve)
        {
            // 근접한 애들끼리만 빌려줄 수 있다고 했으니까 'reserver의 번호가 lost의 번호보다 1 많으면' 체육복을 빌려갈 수 있다.
            // 근데 주어진 입출력예시는 이걸로만 됐는데 제대로 코드짤려면 'reserver의 번호가 lost의 번호보다 1 적을때'도 체크해야하는데 아직 못했어요.
            if (l == (r + 1))
            {
                answer += 1;
            }
        }
    }
    // answer는 체육복을 입는 최대 학생수니까 (위에 for문은 빌려입은 친구들을 체크한거고) 잃어버리지 않은 친구들도 더해줌
    answer += (n - lost.size());
    return answer;
}

int main()
{
    vector<int> lfirst = { 2,4 };   vector<int> rfirst = { 1,3,5 };
    vector<int> lsecond = { 2,4 };  vector<int> rsecond = { 3 };
    vector<int> lthird = { 3 };     vector<int> rthird = { 1 };
    
    std::cout << solution(5, lfirst, rfirst) << std::endl;
    std::cout << solution(5, lsecond, rsecond) << std::endl;
    std::cout << solution(3, lthird, rthird) << std::endl;
}
