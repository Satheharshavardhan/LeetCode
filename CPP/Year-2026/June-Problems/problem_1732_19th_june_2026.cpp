#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestAltitude(vector<int> &gain)
{
    int start_point = 0;
    vector<int> altitudes;
    for (int num : gain)
    {
        start_point += num;
        altitudes.push_back(start_point);
    }
    return max(*max_element(altitudes.begin(), altitudes.end()), 0);
}

int main()
{
    vector<int> gain = {-4, -3, -2, -1, 4, 3, 2};
    cout << largestAltitude(gain) << endl;
    return 0;
}