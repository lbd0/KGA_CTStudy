/**************안전지대****************
문제 설명
다음 그림과 같이 지뢰가 있는 지역과 지뢰에 인접한 위, 아래, 좌, 우 대각선 칸을 모두 위험지역으로 분류합니다.
image.png
지뢰는 2차원 배열 board에 1로 표시되어 있고 board에는 지뢰가 매설 된 지역 1과, 지뢰가 없는 지역 0만 존재합니다.
지뢰가 매설된 지역의 지도 board가 매개변수로 주어질 때, 안전한 지역의 칸 수를 return하도록 solution 함수를 완성해주세요.

제한사항
board는 n * n 배열입니다.
1 ≤ n ≤ 100
지뢰는 1로 표시되어 있습니다.
board에는 지뢰가 있는 지역 1과 지뢰가 없는 지역 0만 존재합니다.
**************************************/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ChangeValue(int value)
{
    if(value != 1) return -1;
    return value;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int size = board.size();
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(board[i][j] == 1)
            {
                for(int a=-1; a<=1; a++)
                {
                    for(int b=-1; b<=1; b++) 
                    {
                        if((i+a>=0&&i+a<size) && (j+b>=0&&j+b<size))
                        {
                            board[i+a][j+b] = ChangeValue(board[i+a][j+b]);
                        }
                    }
                }
            }
        }
    }
    for(auto n:board)
    {
        for(auto m:n)
        {
            if(m == 0)
                answer += 1;
        }
        
        cout << endl;
    }
    return answer;
}