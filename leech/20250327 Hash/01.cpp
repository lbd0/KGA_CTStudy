#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> map;
    
    for (const auto& player : participant)
    {
        if (map.end() == map.find(player))
            map[player] = 1;
        else
            ++map[player];
    }

    for (const auto& player : completion)
        --map[player];

    for(const auto& player : participant)
        if (map[player] > 0)
            return player;
}