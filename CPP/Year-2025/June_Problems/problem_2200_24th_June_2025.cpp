#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
{
    int n = nums.size();
    vector<int> result;
    vector<bool> isValid(n, false);
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == key)
        {
            int start = max(0, i - k);
            int end = min(n - 1, i + k);
            for (int j = start; j <= end; ++j)
            {
                isValid[j] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (isValid[i])
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    return 0;
}