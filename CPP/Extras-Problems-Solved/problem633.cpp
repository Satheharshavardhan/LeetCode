#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool binarySearch(const vector<int> &square, int target)
{
    int left = 0;
    int right = square.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (square[mid] == target)
        {
            return true;
        }
        else if (square[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

bool judgeSquareSum(int c)
{
    vector<int> square;
    for (int i = 0; i <= (int)sqrt(c); i += 1)
    {
        square.push_back(i * i);
    }
    for (int i = 0; i < c; i += 1)
    {
        if (binarySearch(square, c - (i * i)))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "This is the Solution of the Leetcode problem 633 i.e. Sum of Square Numbers\n";
    cout << "Enter the value of C : ";
    string c;
    getline(cin, c);
    bool result = judgeSquareSum(stoi(c));
    cout << result << endl;
    return 0;
}