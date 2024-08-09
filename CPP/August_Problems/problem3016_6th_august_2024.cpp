#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int minimumPushes(string word)
{
    map<char, int> count_letter;
    for (const auto &str : word)
    {
        count_letter[str] += 1;
    }
    vector<pair<char, int>> count_word(count_letter.begin(), count_letter.end());
    sort(count_word.begin(), count_word.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         { return a.second > b.second; });
    int min_pushes = 0;
    int push_value = 1;
    int i = 0;
    for (const auto &entry : count_word)
    {
        min_pushes += (entry.second * push_value);
        i += 1;
        if (i == 8)
        {
            i = 0;
            push_value += 1;
        }
    }
    return min_pushes;
}

int main()
{
    return 0;
}