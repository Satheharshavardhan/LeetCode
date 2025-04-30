#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool compare(const int &a, const int &b)
{
    string s1 = to_string(a);
    string s2 = to_string(b);
    return s1 + s2 > s2 + s1;
}

string largestNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), compare);
    if (nums[0] == 0)
    {
        return "0";
    }
    string result = "";
    for (const auto &num : nums)
    {
        result += to_string(num);
    }
    return result;
}

int main()
{
    return 0;
}