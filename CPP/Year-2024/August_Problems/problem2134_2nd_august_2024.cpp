#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSwaps(vector<int> &nums)
{
    int window_length = count(nums.begin(), nums.end(), 1);
    if (window_length == nums.size())
    {
        return 0;
    }
    int n = nums.size();
    for (int i = 0; i < window_length - 1; i += 1)
    {
        nums.push_back(nums[i]);
    }
    int max_one = 0;
    for (int i = 0; i < n; i += 1)
    {
        vector<int> window(nums.begin() + i, nums.begin() + i + window_length);
        int sub_sum = count(window.begin(), window.end(), 1);
        if (sub_sum > max_one)
        {
            max_one = sub_sum;
        }
    }
    return window_length - max_one;
}

int main()
{
    return 0;
}
