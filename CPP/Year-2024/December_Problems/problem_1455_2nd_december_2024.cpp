#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split_sentence(string sentence)
{
    vector<string> words;
    string word;
    stringstream ss(sentence);
    while (ss >> word)
    {
        words.push_back(word);
    }
    return words;
}

int isPrefixOfWord(string sentence, string searchWord)
{
    vector<string> words = split_sentence(sentence);
    int index = 0;
    for (const auto &word : words)
    {
        i++;
        if (word.size() >= searchWord.size() && word.substr(0, searchWord.length()) == searchWord)
        {
            return index;
        }
    }
    return -1;
}

int main()
{
    return 0;
}