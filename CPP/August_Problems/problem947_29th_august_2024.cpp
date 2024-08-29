#include <iostream>
#include <vector>
#include <set>

using namespace std;

int removeStones(vector<vector<int>> &stones)
{
    set<int> rows;
    set<int> columns;
    int removed_stone_num;
    for (const auto &cordinates : stones)
    {
        rows.insert(cordinates[0]);
        columns.insert(cordinates[1]);
    }
    while (stones.size() != 1)
    {
        int i = 0;
        if (rows.find(stones[i][0]) != rows.end())
        {
            removed_stone_num += 1;
            stones.pop_back();
        }
        else if (columns.find(stones[i][0]) != columns.end())
        {
            removed_stone_num += 1;
            stones.pop_back();
        }
        else
        {
            i -= 1;
        }
    }
}

int main()
{
    return 0;
}