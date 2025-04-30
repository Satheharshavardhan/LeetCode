#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> m1;
    for (const auto &num : nums1)
    {
        m1[num] += 1;
    }
    vector<int> result;
    for (const auto &num : nums2)
    {
        if (m1[num] > 0)
        {
            result.push_back(num);
            m1[num] -= 1;
        }
    }
    return result;
}

int main()
{
    return 0;
}