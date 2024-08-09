#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
{
    vector<pair<int, int>> pair_num;
    for (int num : nums)
    {
        string s = to_string(num);
        string mapped_str = "";
        for (char c : s)
        {
            mapped_str += to_string(mapping[c - '0']);
        }
        int mapped_value = stoi(mapped_str);
        pair_num.push_back({num, mapped_value});
    }
    sort(pair_num.begin(), pair_num.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if (a.second == b.second)
        {
            return false;
        }
        return a.second < b.second; });
    vector<int> result;
    for (const auto &pair : pair_num)
    {
        result.push_back(pair.first);
    }
    return result;
}

int main()
{
    vector<int> mapping = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
    vector<int> nums = {991, 338, 38};
    vector<int> result = sortJumbled(mapping, nums);
    for (const auto &num : result)
    {
        cout << num;
    }
    return 0;
}