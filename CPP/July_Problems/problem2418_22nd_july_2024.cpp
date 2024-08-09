#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> sortPeople(vector<string> &names, vector<int> &heights)
{
    unordered_map<int, int> map;
    for (int i = 0; i < heights.size(); i += 1)
    {
        map[heights[i]] = i;
    }
    sort(heights.begin(), heights.end(), greater<int>());
    vector<string> sorted_names(heights.size());
    for (int i = 0; i < heights.size(); i++)
    {
        int original_index = map[heights[i]];
        sorted_names[i] = names[original_index];
    }
    return sorted_names;
}

int main()
{
    return 0;
}