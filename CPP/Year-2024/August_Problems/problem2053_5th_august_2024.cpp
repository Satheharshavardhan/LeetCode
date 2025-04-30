#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string kthDistinct(vector<string> &arr, int k)
{
    unordered_map<string, int> count_map;
    for (const auto &str : arr)
    {
        count_map[str] += 1;
    }
    vector<string> distinct_strings;
    for (const auto &str : arr)
    {
        if (count_map[str] == 1)
        {
            distinct_strings.push_back(str);
        }
    }
    if (distinct_strings.size() < k)
    {
        return "";
    }
    else
    {
        return distinct_strings[k - 1];
    }
}

int main()
{
    return 0;
}