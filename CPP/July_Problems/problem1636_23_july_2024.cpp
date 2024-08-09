#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> frequencySort(vector<int> &nums)
{
    unordered_map<int, int> freq_map;
    for (const auto &num : nums)
    {
        freq_map[num] += 1;
    }
    nums.clear();
    vector<pair<int, int>> freq_pair(freq_map.begin(), freq_map.end());
    sort(freq_pair.begin(), freq_pair.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { 
            if(a.second==b.second)
            {
                return a.first>b.first;
            }
            return a.second < b.second; });
    for (const auto &pair : freq_pair)
    {
        int i = pair.second;
        while (i > 0)
        {
            nums.push_back(pair.first);
            i -= 1;
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {-1, 1, -6, 4, 5, -6, 1, 4, 1};
    nums = frequencySort(nums);
    for (const auto &num : nums)
    {
        cout << num << " ";
    }
    return 0;
}