#include <iostream>

using namespace std;

int scoreOfString(string s)
{
    int score = 0;
    for (int i = 1; i < s.size(); i += 1)
    {
        score += abs(static_cast<int>(s[i - 1]) - static_cast<int>(s[i]));
    }
    return score;
}

int main()
{
    cout << "This is the solution of the Leetcode Problem 3110 i.e. Score of the String\n";
    string s;
    cout << "Enter the String : ";
    cin >> s;
    int result = scoreOfString(s);
    cout << "The score of the String is : " << result << endl;
    return 0;
}