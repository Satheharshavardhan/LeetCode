#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_pailndrome(string s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

string shortestPalindrome(string s)
{
    if (s.empty())
    {
        return "";
    }
    int i = s.size() - 1;
    while (i >= 0)
    {
        string temp(s.begin(), s.begin() + i + 1);
        if (is_pailndrome(temp))
        {
            string remaining(s.begin() + i + 1, s.end());
            reverse(remaining.begin(), remaining.end());
            return remaining + s;
        }
        i--;
    }
    return "";
}

// string shortestPalindrome(string s)
// {
//     int n = s.size(), mid;
//     if (n % 2 == 0)
//     {
//         mid = n / 2 - 1;
//     }
//     else
//     {
//         mid = n / 2;
//     }
//     int left = mid - 1, right = mid + 1;
//     while (s[left] == s[right])
//     {
//         left--;
//         right++;
//     }
//     if (left == -1 && right == n)
//     {
//         return s;
//     }
//     else
//     {
//         string temp(s.begin() + right, s.end());
//         reverse(temp.begin(), temp.end());
//         return (temp + s);
//     }
// }

int main()
{
    // string s = "aacecaaa";
    // string s = "abcd";
    string s = "abacacaad";
    cout << shortestPalindrome(s);
    return 0;
}