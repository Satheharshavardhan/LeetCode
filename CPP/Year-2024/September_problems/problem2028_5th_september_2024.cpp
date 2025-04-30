#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> missingRolls(vector<int> &rolls, int mean, int n)
{
    int m = rolls.size();
    int given_sum = 0;
    for (const auto &roll : rolls)
    {
        given_sum += roll;
    }
    int sum_missing = (m + n) * mean - given_sum;
    if (sum_missing > 6 * n or sum_missing < 0 or sum_missing < n)
    {
        return {};
    }
    int rem = sum_missing % n;
    int added = sum_missing / n;
    vector<int> missing_rolls(n, added);
    for (int i = 0; i < rem; i += 1)
    {
        missing_rolls[i] += 1;
    }
    return missing_rolls;
}

int main()
{
    return 0;
}