#include <iostream>
#include <vector>
#include <string>

using namespace std;

string addSpaces(string s, vector<int> &spaces)
{
    vector<string> word;
    int start = 0;
    for (const auto &index : spaces)
    {
        word.push_back(s.substr(start, index - start));
        start = index;
    }
    word.push_back(s.substr(start));
    s = "";
    for (const auto &str : word)
    {
        s += str;
        s += " ";
    }
    s.pop_back();
    return s;
}

int main()
{
    string s = "LeetcodeHelpsMeLearn";
    vector<int> spaces = {8, 13, 15};
    cout << addSpaces(s, spaces);
    return 0;
}