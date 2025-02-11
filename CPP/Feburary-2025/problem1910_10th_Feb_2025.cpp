#include <iostream>
#include <string>

using namespace std;

string removeOccurrences(string s, string part)
{
    int len_part = part.size();
    while (s.find(part) != s.npos)
    {
        int index = s.find(part);
        s.erase(index, len_part);
    }
    return s;
}

int main()
{
    return 0;
}