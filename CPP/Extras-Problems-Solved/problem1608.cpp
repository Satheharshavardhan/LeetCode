#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool special(vector<int> &nums, int x)
{
    int count = 0;
    for (int i : nums)
    {
        if (i >= x)
        {
            count += 1;
        }
    }
    return x == count;
}

int specialArray(vector<int> &nums)
{
    for (int x = 0; x <= nums.size(); x++)
    {
        if (special(nums, x))
        {
            return x;
        }
    }
    return -1;
}

int main()
{
    cout << "This is the Solution of the Leetcode problem 1608 i.e. Special Array with X elements Greater than or Equal X\n";
    cout << "Enter the Elements of array seperated by commas : ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> nums;
    string token;
    while (getline(ss, token, ','))
    {
        nums.push_back(stoi(token));
    }
    int result = specialArray(nums);
    cout << "The array is special and the value of X is " << result << endl;
    return 0;
}