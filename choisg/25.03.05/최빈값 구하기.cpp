문제 설명
최빈값은 주어진 값 중에서 가장 자주 나오는 값을 의미합니다. 정수 배열 array가 매개변수로 주어질 때, 최빈값을 return 하도록 solution 함수를 완성해보세요. 최빈값이 여러 개면 -1을 return 합니다.

제한사항
0 < array의 길이 < 100
0 ≤ array의 원소 < 1000
입출력 예
array	result
[1, 2, 3, 3, 3, 4]	3
[1, 1, 2, 2]	-1
[1]	1
입출력 예 설명
입출력 예 #1

[1, 2, 3, 3, 3, 4]에서 1은 1개 2는 1개 3은 3개 4는 1개로 최빈값은 3입니다.
입출력 예 #2

[1, 1, 2, 2]에서 1은 2개 2는 2개로 최빈값이 1, 2입니다. 최빈값이 여러 개이므로 -1을 return 합니다.
입출력 예 #3

[1]에는 1만 있으므로 최빈값은 1입니다.

답
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int solution(vector<int> array) {
    int answer = 0;
    
    sort(array.begin(), array.end());
 
    // 최빈값이 들어갈 vector
    vector<int> numbers;
    
    // 최대로 나온 갯수 count
    // 최빈값 max
    // 이전 값 temp
    int count = 0, max = 0, temp;
    for(int i = 0; i < array.size(); i++)
    {
        // i == 0 일때는 저장만 한다.
        if (i == 0)
        {   
            temp = array[i];
            count = 1, max = 1;
            numbers.push_back(array[i]);
        }
        // 그 이외에는
        else
        {
            // 이전 값과 현재 값이 같다면 count++
            if(temp == array[i]) count++;
            // 다르다면 temp를 바꾸고 count = 1
            else 
            {
                temp = array[i];
                count = 1;
            }
            
            // 만약 최빈값이 갱신된다면 numbers를 비우고
            // max를 갱신한 뒤, numbers에 해당 값을 넣어준다.
            if (max < count)
            {
                numbers.clear();
                numbers.push_back(array[i]);
                max = count;
            }
            // 동일한 최빈값이 있다면 numbers에 최빈값을 넣어준다.
            else if (max == count)
            {
                numbers.push_back(array[i]);
            }
        }
    }
    
    if (numbers.size() == 1)
    {
        return numbers[0];
    }
    else return -1;
}
