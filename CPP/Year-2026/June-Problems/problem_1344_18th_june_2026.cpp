#include <iostream>
#include <math.h>

using namespace std;

double angleClock(int hour, int minutes)
{
    double min_angle = 0;
    min_angle = minutes * 6;
    double hour_angle = 0;
    hour_angle = (hour % 12) * 30 + minutes * 0.5;
    double diff = abs(hour_angle - min_angle);
    return min(diff, 360 - diff);
}

int main()
{
    cout << angleClock(12, 30) << endl;
    return 0;
}
