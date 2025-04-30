#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void reverseString(vector<char> &s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i += 1;
        j -= 1;
    }
}

int main()
{
    cout << "This is the solution of the Leetcode problem 344 i.e. Reverse String\n";
    cout << "Enter the characters seperated by commas : ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    string token;
    vector<char> s;
    while (getline(ss, token, ','))
    {
        if (!token.empty())
        {
            s.push_back(token[0]);
        }
    }
    reverseString(s);
    cout << "The reverse string is : ";
    for (char c : s)
    {
        cout << c;
    }
    return 0;
}