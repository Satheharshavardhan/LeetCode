#include <iostream>
#include "Header\\input_utils.h"

using namespace std;

int main()
{
    cout << "Enter the values seperated by commas : ";
    string input;
    getline(cin, input);
    vector<int> nums = parseInput(input);
    for (auto &num : nums)
    {
        cout << num << " ";
    }
    return 0;
}