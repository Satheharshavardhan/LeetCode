#include <iostream>
#include <algorithm>

using namespace std;

int maximumGain(string s, int x, int y)
{
    int larger = max(x, y);
    int gain = 0;
    size_t pos;

    if (larger == x)
    {
        while ((pos = s.find("ab")) != string::npos)
        {
            s.erase(pos, 2);
            gain += x;
        }
        while ((pos = s.find("ba")) != string::npos)
        {
            s.erase(pos, 2);
            gain += y;
        }
    }
    else
    {
        while ((pos = s.find("ba")) != string::npos)
        {
            s.erase(pos, 2);
            gain += y;
        }
        while ((pos = s.find("ab")) != string::npos)
        {
            s.erase(pos, 2);
            gain += x;
        }
    }
    return gain;
}

int main()
{
    cout << maximumGain("cdbcbbaaabab", 4, 5);
    return 0;
}