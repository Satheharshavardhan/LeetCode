#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int get_diff(const string &s1, const string &s2)
{
    int hour_1 = stoi(s1.substr(0, 2));
    int minutes_1 = stoi(s1.substr(3, 2));
    int hour_2 = stoi(s2.substr(0, 2));
    int minutes_2 = stoi(s2.substr(3, 2));
    int total_minutes_1 = hour_1 * 60 + minutes_1;
    int total_minutes_2 = hour_2 * 60 + minutes_2;
    return abs(total_minutes_1 - total_minutes_2);
}

int findMinDifference(vector<string> &timePoints)
{
    sort(timePoints.begin(), timePoints.end());
    int min_diff = get_diff(timePoints[0], timePoints[timePoints.size() - 1]);
    int circular_diff = 1440 - get_diff(timePoints[0], timePoints[timePoints.size() - 1]);
    min_diff = min(min_diff, circular_diff);
    for (int i = 0; i < timePoints.size() - 1; i++)
    {
        min_diff = min(min_diff, get_diff(timePoints[i], timePoints[i + 1]));
    }
    return min_diff;
}

int main()
{
    vector<string> timePoints = {"23:59", "00:00"};
    cout << findMinDifference(timePoints);
    return 0;
}