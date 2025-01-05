#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string shiftingLetters(string s, vector<vector<int>> &shifts)
{
    unordered_map<int, char> mappings;
    for (int i = 19; i < 45; i++)
    {
        mappings[i] = 'a' + ((i - 19) % 26);
    }
    for (const auto &shift : shifts)
    {
        for (int i = shift[0]; i <= shift[1]; i++)
        {
            char current = s[i];
            int new_val = current - 'a';
            if (shift[2] == 0)
            {
                new_val = (new_val - 1 + 26) % 26;
            }
            else
            {
                new_val = (new_val + 1) % 26;
            }
            s[i] = mappings[new_val + 19];
        }
    }
    return s;
}

int main()
{
    string s = "abc";
    vector<vector<int>> shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
    cout << shiftingLetters(s, shifts);
    return 0;
}