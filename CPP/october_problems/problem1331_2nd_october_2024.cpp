#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> arrayRankTransform(vector<int> &arr)
{
    vector<int> new_array = arr;
    sort(new_array.begin(), new_array.end());
    unordered_map<int, int> rank;
    int i = 1;
    for (const auto &num : new_array)
    {
        if (rank.find(num) == rank.end())
        {
            rank[num] = i;
            i++;
        }
        else
        {
            continue;
        }
    }
    new_array.clear();
    for (const auto &num : arr)
    {
        new_array.push_back(rank[num]);
    }
    return new_array;
}

int main()
{
    return 0;
}