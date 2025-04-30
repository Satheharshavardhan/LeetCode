#include <iostream>
#include <vector>

using namespace std;

bool check_odd(int num)
{
    if (num % 2 == 1)
    {
        return true;
    }
    return false;
}

bool threeConsecutiveOdds(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 2; i += 1)
    {
        if (check_odd(arr[i]) and check_odd(arr[i + 1]) and check_odd(arr[i + 2]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}