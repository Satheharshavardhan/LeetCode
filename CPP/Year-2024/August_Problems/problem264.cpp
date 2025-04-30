#include <iostream>
#include <vector>

using namespace std;

int nthUglyNumber(int n)
{

    vector<int> ugly_nums(n);
    ugly_nums[0] = 1;
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    for (int i = 1; i < n; i++)
    {
        int two_mul = ugly_nums[p1] * 2;
        int three_mul = ugly_nums[p2] * 3;
        int five_mul = ugly_nums[p3] * 5;
        ugly_nums[i] = min(two_mul, min(three_mul, five_mul));
        if (ugly_nums[i] == two_mul)
            p1++;
        if (ugly_nums[i] == three_mul)
            p2++;
        if (ugly_nums[i] == five_mul)
            p3++;
    }
    return ugly_nums[n - 1];
}

int main()
{
    return 0;
}