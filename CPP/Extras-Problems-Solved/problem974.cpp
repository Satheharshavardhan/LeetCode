#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int subArrayDivByK(vector<int> &nums, int k)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i += 1)
    {
        for (int j = i; j < nums.size(); j += 1)
        {
            vector<int> sub(nums.begin() + i, nums.begin() + j + 1);
            if (accumulate(sub.begin(), sub.end(), 0) % k == 0)
            {
                result += 1;
            }
            sub.clear();
            sub.shrink_to_fit();
        }
    }
    return result;
}

int main()
{
    cout << "This is the solution of the Leetcode problem 974 i.e. Subarray Sum divisible by k\n";
    int k;
    string input;
    cout << "Enter the values of Nums seperated by commas : ";
    getline(cin, input);
    stringstream ss(input);
    vector<int> nums;
    string token;
    while (getline(ss, token, ','))
    {
        nums.push_back(stoi(token));
    }
    cout << "Enter the value of K : ";
    cin >> k;
    int result = subArrayDivByK(nums, k);
    cout << result << endl;
    return 0;
}