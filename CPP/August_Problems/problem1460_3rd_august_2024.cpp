#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canBeEqual(vector<int> &target, vector<int> &arr)
{
    sort(target.begin(), target.end());
    sort(arr.begin(), arr.end());
    if (target == arr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    return 0;
}