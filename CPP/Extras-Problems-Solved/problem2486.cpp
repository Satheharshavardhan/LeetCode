#include <iostream>

using namespace std;

int appendCharacters(string s, string t)
{
    int n = s.size(), m = t.size();
    int i = 0, j = 0, result = 0;
    while (i < n and j < m)
    {
        if (s[i] == t[j])
        {
            i += 1;
            j += 1;
        }
        else
        {
            i += 1;
        }
    }
    if (i >= n)
    {
        result = m - j;
    }
    return result;
}

int main()
{
    cout << "This is the solution of the Leetcode Problem 2486 i.e. Append Characters to String to Subsequence\n";
    cout << "Enter First string : ";
    string s;
    cin >> s;
    cout << "Enter second String : ";
    string t;
    cin >> t;
    int result = appendCharacters(s, t);
    cout << "The added number of characters are : " << result << endl;
    return 0;
}