#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int minIncrementForUnique(vector<int> &nums)
{
    set<int> s(nums.begin(), nums.end());
    if (s.size() == nums.size())
    {
        return 0;
    }
    int result = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i += 1)
    {
        if (nums[i] < i + 1)
        {
            result += abs(nums[i] - (i + 1));
        }
    }
    return result;
}

int main()
{
    cout << "This is the Solution of the Leetcode problem 945 i.e. Minimum increment to make array unique\n";
    string input;
    cout << "Enter the Values of nums seperated by commas : ";
    getline(cin, input);
    string token;
    stringstream ss(input);
    vector<int> nums;
    while (getline(ss, token, ','))
    {
        nums.push_back(stoi(token));
    }
    int result = minIncrementForUnique(nums);
    cout << "The result is : " << result << endl;
    return 0;
}