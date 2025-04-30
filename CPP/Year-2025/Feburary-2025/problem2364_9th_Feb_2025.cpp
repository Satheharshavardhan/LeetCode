#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long countBadPairs(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[i] = (nums[i] - 1);
    }
    long long bad_pairs = 0;
    
}

int main()
{
    return 0;
}