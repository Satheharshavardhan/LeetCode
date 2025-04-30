#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rangeSum(vector<int> &nums, int n, int left, int right)
{
    vector<int> sub_array_sum;
    for (int i = 0; i < n; i += 1)
    {
        sub_array_sum.push_back(nums[i]);
        for (int j = i + 1; j < n; j += 1)
        {
            sub_array_sum.push_back(sub_array_sum.back() + nums[j]);
        }
    }
    sort(sub_array_sum.begin(), sub_array_sum.end());
    int result = 0;
    // int MOD = 1000000007;
    int MOD = 1e9 + 7; // This is same as the above Code.
    for (int i = left - 1; i < right; i += 1)
    {
        result = (result + sub_array_sum[i]) % MOD;
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int n = 4, left = 1, right = 5;
    cout << rangeSum(nums, n, left, right);
    return 0;
}