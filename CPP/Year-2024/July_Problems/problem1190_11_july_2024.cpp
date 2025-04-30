#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string reverseParentheses(string s)
{
    stack<string> S;
    string ans = "";
    for (char ch : s)
    {
        if (ch == '(')
        {
            S.push(ans);
            ans = "";
        }
        else if (ch == ')')
        {
            reverse(ans.begin(), ans.end());
            ans = S.top() + ans;
            S.pop();
        }
        else
        {
            ans += ch;
        }
    }
    return ans;
}

int main()
{
    return 0;
}