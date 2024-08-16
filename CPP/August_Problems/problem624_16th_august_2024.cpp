#include <iostream>
#include <vector>

using namespace std;

int maxDistance(vector<vector<int>> &arrays)
{
    int max_dist = 0;
    int smallest_val = arrays[0][0];
    int largest_val = arrays[0].back();
    for (int i = 1; i < arrays.size(); i += 1)
    {
        max_dist = max(max_dist, abs(smallest_val - arrays[i].back()));
        max_dist = max(max_dist, abs(largest_val - arrays[i].front()));
        smallest_val = min(smallest_val, arrays[i].front());
        largest_val = max(largest_val, arrays[i].back());
    }
    return max_dist;
}

int main()
{
    return 0;
}