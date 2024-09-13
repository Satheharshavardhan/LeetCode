#include <iostream>
#include <vector>

using namespace std;

vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    vector<int> result;
    int n = arr.size();
    vector<int> prefixXor(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefixXor[i + 1] = prefixXor[i] ^ arr[i];
    }
    for (const auto &q : queries)
    {
        int left = q[0], right = q[1];
        result.push_back(prefixXor[left] ^ prefixXor[right + 1]);
    }
    return result;
}

int main()
{
    return 0;
}
