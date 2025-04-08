#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool check_distinct(unordered_map<int, int> map)
{
    for (const auto &pairs : map)
    {
        if (pairs.second != 1)
        {
            return false;
        }
    }
    return true;
}

int minimumOperations(vector<int> &nums)
{
    unordered_map<int, int> count;
    int steps = 0;
    for (const auto &num : nums)
    {
        count[num] += 1;
    }
    if (check_distinct(count))
    {
        return 0;
    }
    else
    {
        while (!check_distinct(count))
        {
            if (nums.size() < 3)
            {
                return steps + 1;
            }
            else
            {
                nums.erase(nums.begin(), nums.begin() + 3);
                count.clear();
                for (const auto &num : nums)
                {
                    count[num] += 1;
                }
                steps++;
            }
        }
        return steps;
    }
}

int main()
{
    return 0;
}