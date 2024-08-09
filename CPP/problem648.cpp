#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

string replaceWords(vector<string> &dictionary, string sentence)
{
    vector<string> words;
    string result = "";
    stringstream ss(sentence);
    string token;
    while (getline(ss, token, ' '))
    {
        words.push_back(token);
    }
    sort(dictionary.begin(), dictionary.end());
    for (auto &word : words)
    {
        string temp_word = word;
        for (auto &lett : dictionary)
        {
            if (word.find(lett) == 0)
            {
                temp_word = lett;
                break;
            }
        }
        if (!result.empty())
        {
            result += " ";
        }
        result += temp_word;
    }
    return result;
}

int main()
{
    cout << "This is the Solution of the Leetcode problem 648 i.e. Replace Words\n";
    string sentence;
    cout << "Enter the Sentence : ";
    getline(cin, sentence);
    vector<string> dictionary;
    cout << "Enter the words of dictionary seperated by commas : ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    string token;
    while (getline(ss, token, ','))
    {
        dictionary.push_back(token);
    }
    string result = replaceWords(dictionary, sentence);
    cout << "The resultant sentence after removing the derivative is : " << result << endl;
    return 0;
}