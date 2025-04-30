#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> commonChars(vector<string> &words)
{
    vector<unordered_map<char, int>> charCounts(words.size());
    for (size_t i = 0; i < words.size(); ++i)
    {
        for (char c : words[i])
        {
            charCounts[i][c]++;
        }
    }
    unordered_map<char, int> minFreq;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        minFreq[c] = INT_MAX;
    }
    for (const auto &counts : charCounts)
    {
        for (char c = 'a'; c <= 'z'; ++c)
        {
            if (counts.find(c) != counts.end())
            {
                minFreq[c] = min(minFreq[c], counts.at(c));
            }
            else
            {
                minFreq[c] = 0;
            }
        }
    }
    vector<string> result;
    for (const auto &pair : minFreq)
    {
        for (int i = 0; i < pair.second; ++i)
        {
            result.push_back(string(1, pair.first));
        }
    }
    return result;
}

int main()
{
    cout << "This is the Solution of the Leetcode problem 1002 i.e. Find Common Characters\n";
    vector<string> words;
    string word;
    char delimiter = ',';
    cout << "Enter words separated by commas (e.g., 'bella,label,roller'):" << endl;
    string inputLine;
    getline(cin, inputLine);
    istringstream stream(inputLine);
    while (stream >> word)
    {
        words.push_back(word);
    }
    vector<string> result = commonChars(words);
    for (const auto &str : result)
    {
        cout << str << endl;
    }
    return 0;
}