/*
문자열 my_string과 이차원 정수 배열 queries가 매개변수로 주어집니다. 
queries의 원소는 [s, e] 형태로, my_string의 인덱스 s부터 인덱스 e까지를 뒤집으라는
 의미입니다. my_string에 queries의 명령을 순서대로 처리한 후의 문자열을 return 하는
 solution 함수를 작성해 주세요.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = "";
    int count=0;
    
//     for(int i=0;i<queries.size();++i)
//     {
//         for(int k=queries[i][0];k<=(queries[i][1])/2;++k)
//         {
//             int len = queries[i][1]-queries[i][0]
//             string temp=my_string[k];
//             my_string[k]=my_string[queries[i][1]-count];
//             my_string[queries[i][1]-count]=temp;
//             count++;
            
//         }
//         count=0;
//     }
    string temp="";
    
    for(int i=0; i<queries.size();++i)
    {
        for(int k=queries[i][1]; k>=queries[i][0];--k)
        {
            temp+=my_string[k];
        }
       
        my_string.replace(queries[i][0],temp.length(),temp);
        temp="";
    }
    
    return my_string;
}