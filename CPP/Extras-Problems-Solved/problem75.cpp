#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

void sortColors_2(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        switch (nums[mid])
        {
        case 0:
            swap(nums[low++], nums[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(nums[mid], nums[high--]);
            break;
        }
    }
}

void sortColors_1(vector<int> &nums)
{
    unordered_map<int, int> counter;
    for (const auto &color : nums)
    {
        counter[color] += 1;
    }
    nums.clear();
    for (int i = 0; i < 3; i += 1)
    {
        while (counter[i] > 0)
        {
            nums.push_back(i);
            counter[i] -= 1;
        }
    }
}

int main()
{
    cout << "This is the Solution of the Leetcode problem 75 i.e. Sort Colours\n";
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
    sortColors_1(nums);
    for (const auto &num : nums)
    {
        cout << num << " ";
    }   
    return 0;
}