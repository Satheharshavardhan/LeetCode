#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkIfExist(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int i = 0;
    if (arr[0] == 0 and arr[1] == 0)
    {
        return true;
    }
    else
    {
        if (arr[0] == 0)
        {
            i = 1;
        }
    }
    for (int i = i; i < arr.size(); i++)
    {
        if (find(arr.begin(), arr.end(), arr[i] * 2) != arr.end())
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {-2, 0, 10, -19, 4, 6, -8};
    cout << checkIfExist(arr);
    return 0;
}