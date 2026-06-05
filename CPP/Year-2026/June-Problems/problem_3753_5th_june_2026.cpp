#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution
{
private:
    struct Node
    {
        long long cnt;
        long long waviness;

        Node(long long c = 0, long long w = 0)
            : cnt(c), waviness(w) {}
    };

    string digits;

    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    Node dfs(int pos,
             int prev2,
             int prev1,
             bool tight,
             bool started)
    {
        if (pos == digits.size())
        {
            return Node(1, 0);
        }

        if (!tight && vis[pos][prev2][prev1][started][0])
        {
            return dp[pos][prev2][prev1][started][0];
        }

        int limit = tight ? digits[pos] - '0' : 9;

        Node ans;

        for (int digit = 0; digit <= limit; digit++)
        {

            bool newTight = tight && (digit == limit);

            if (!started && digit == 0)
            {

                Node child = dfs(
                    pos + 1,
                    10,
                    10,
                    newTight,
                    false);

                ans.cnt += child.cnt;
                ans.waviness += child.waviness;
            }
            else
            {

                if (!started)
                {

                    Node child = dfs(
                        pos + 1,
                        10,
                        digit,
                        newTight,
                        true);

                    ans.cnt += child.cnt;
                    ans.waviness += child.waviness;
                }
                else
                {

                    int extra = 0;

                    if (prev2 != 10)
                    {

                        if ((prev1 > prev2 && prev1 > digit) ||
                            (prev1 < prev2 && prev1 < digit))
                        {
                            extra = 1;
                        }
                    }

                    Node child = dfs(
                        pos + 1,
                        prev1,
                        digit,
                        newTight,
                        true);

                    ans.cnt += child.cnt;

                    ans.waviness +=
                        child.waviness +
                        extra * child.cnt;
                }
            }
        }

        if (!tight)
        {
            vis[pos][prev2][prev1][started][0] = true;
            dp[pos][prev2][prev1][started][0] = ans;
        }

        return ans;
    }

    long long solve(long long x)
    {
        if (x <= 0)
        {
            return 0;
        }

        digits = to_string(x);

        memset(vis, false, sizeof(vis));

        return dfs(
                   0,
                   10,
                   10,
                   true,
                   false)
            .waviness;
    }

public:
    long long totalWaviness(long long num1, long long num2)
    {
        return solve(num2) - solve(num1 - 1);
    }
};

int main()
{
    Solution s;

    cout << s.totalWaviness(120, 130) << endl;

    return 0;
}