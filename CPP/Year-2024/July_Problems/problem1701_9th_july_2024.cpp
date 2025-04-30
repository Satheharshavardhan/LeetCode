#include <iostream>
#include <vector>

using namespace std;

double averageWaitingTime(vector<vector<int>> &customers)
{
    int current_time = customers[0][0];
    int total_waiting = 0;
    for (int i = 0; i < customers.size(); i += 1)
    {
        if (current_time >= customers[i][0])
        {
            current_time += customers[i][1];
            total_waiting += (current_time - customers[i][0]);
        }
        else
        {
            current_time = current_time + (customers[i][0] - current_time);
            i -= 1;
        }
    }
    double avg_wait_time = (double)total_waiting / customers.size();
    return avg_wait_time;
}

int main()
{
    // vector<vector<int>> customers = {{5, 2}, {5, 4}, {10, 3}, {20, 1}};
    vector<vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};
    cout << averageWaitingTime(customers);
    return 0;
}