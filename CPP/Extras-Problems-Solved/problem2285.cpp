#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long maximumImportance(int n, vector<vector<int>> &roads)
{
    unordered_map<int, vector<int>> map;
    for (const auto &path : roads)
    {
        for (const auto &node : path)
        {
            if (map[path[node]].empty())
            {
                map[path[node]].push_back(0);
            }
            map[path[node]][0] += 1;
        }
    }
}

int main()
{
    return 0;
}