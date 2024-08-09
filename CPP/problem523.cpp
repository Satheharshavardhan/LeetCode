#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    for (int i = 0; i < nums.size(); i += 1)
    {
        for (int j = i + 1; j < nums.size(); j += 1)
        {
            vector<int> sub(nums.begin() + i, nums.begin() + j + 1);
            if (sub.size() >= 2 and accumulate(sub.begin(), sub.end(), 0) % k == 0)
            {
                return true;
            }
            sub.clear();
            sub.shrink_to_fit();
        }
    }
    return false;
}

int main()
{
    cout << "This is the solution of the Leetcode problem 523 i.e. Contineous subarray sum\n";
    int k;
    cout << "Enter the value of K : ";
    cin >> k;
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
    bool result = checkSubarraySum(nums, k);
    cout << result << endl;
    return 0;
}