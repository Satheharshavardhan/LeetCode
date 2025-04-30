#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> uncommonFromSentences(string s1, string s2)
{
    unordered_map<string, int> count1;
    unordered_map<string, int> count2;
    vector<string> words1;
    stringstream ss1(s1);
    string word;
    while (ss1 >> word)
    {
        words1.push_back(word);
    }
    stringstream ss2(s2);
    vector<string> words2;
    word = "";
    while (ss2 >> word)
    {
        words2.push_back(word);
    }
    for (const auto &word : words1)
    {
        count1[word] += 1;
    }
    for (const auto &word : words2)
    {
        count2[word] += 1;
    }
    vector<string> result;
    for (const auto &pair : count1)
    {
        if (pair.second == 1 and count2.find(pair.first) == count2.end())
        {
            result.push_back(pair.first);
        }
    }
    for (const auto &pair : count2)
    {
        if (pair.second == 1 and count1.find(pair.first) == count1.end())
        {
            result.push_back(pair.first);
        }
    }
    return result;
}

int main()
{
    return 0;
}