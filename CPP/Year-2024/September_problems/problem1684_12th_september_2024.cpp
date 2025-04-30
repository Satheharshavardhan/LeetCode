#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

int countConsistentStrings(string allowed, vector<string> &words)
{
    unordered_set<char> allowed_set(allowed.begin(), allowed.end());
    int count = 0;
    for (const auto &word : words)
    {
        bool consistent = true;
        for (const auto &character : word)
        {
            if (allowed_set.find(acter) == allowed_set.end())
            {
                consistent = false;
                break;
            }
        }
        if (consistent)
        {
            count += 1;
        }
    }
    return count;
}

int main()
{
    return 0;
}