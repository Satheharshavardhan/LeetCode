#include <iostream>
#include <vector>

using namespace std;

bool isvowel(char character)
{
    if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u')
    {
        return true;
    }
    return false;
}

vector<int> vowelStrings(vector<string> &words,
                         vector<vector<int>> &queries)
{
    vector<int> result;
    for (const auto &pos : queries)
    {
        int total = 0;
        for (int index = pos[0]; index <= pos[1]; index++)
        {
            if (words[index].front() == words[index].back() && isvowel(words[index].front()))
            {
                total++;
            }
        }
        result.push_back(total);
    }
    return result;
}

int main()
{
    vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};
    vector<int> result = vowelStrings(words, queries);
    return 0;
}