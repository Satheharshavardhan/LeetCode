#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int heightChecker(vector<int> &heights)
{
    vector<int> expected = heights;
    int result = 0;
    sort(expected.begin(), expected.end());
    for (int i = 0; i < expected.size(); i += 1)
    {
        if (expected[i] != heights[i])
        {
            result += 1;
        }
    }
    return result;
}

int main()
{
    cout << "This is the Solution of the Leetcode Problem 1051 i.e. Height Checker\n";
    cout << "Enter the value of Height Seperated by commas : ";
    string input;
    getline(cin, input);
    vector<int> heights;
    stringstream ss(input);
    string token;
    while (getline(ss, token, ','))
    {
        heights.push_back(stoi(token));
    }
    int result = heightChecker(heights);
    cout << "The final result is : " << result << endl;
    return 0;
}