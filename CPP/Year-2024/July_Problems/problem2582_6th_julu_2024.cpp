#include <iostream>

using namespace std;

int passThePillow(int n, int time)
{
    int has_pillow = 1;
    bool direction = true; // For forward it is true and for reverse it is fslse.
    while (time > 0)
    {
        if (has_pillow == n)
        {
            direction = false;
        }
        else if (has_pillow == 1)
        {
            direction = true;
        }
        if (direction)
        {
            has_pillow += 1;
        }
        else
        {
            has_pillow -= 1;
        }
        time -= 1;
    }
    return has_pillow;
}

int main()
{
    return 0;
}