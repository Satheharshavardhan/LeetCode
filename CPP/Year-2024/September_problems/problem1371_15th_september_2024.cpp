#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool check_even_vovel(string s)
{
    string vovel = "aeiou";
    unordered_map<char, int> map;
    for (const char &character : s)
    {
        if (vovel.find(character) != string::npos)
        {
            map[character] += 1;
        }
    }
    for (const auto &pair : map)
    {
        if (pair.second % 2 != 0)
        {
            return false;
        }
    }
    return true;
}

int findTheLongestSubstring(string s)
{
    if (check_even_vovel(s))
    {
        return s.size();
    }
    int max_len = 0;
    for (int start = 0; start < s.size(); ++start)
    {
        for (int end = start; end < s.size(); ++end)
        {
            string s1 = s.substr(start, end - start + 1);
            if (check_even_vovel(s1))
            {
                max_len = max(max_len, static_cast<int>(s1.length()));
            }
        }
    }
    return max_len;
}

int main()
{
    string s = "eleetminicoworoep";
    cout << findTheLongestSubstring(s);
    return 0;
}