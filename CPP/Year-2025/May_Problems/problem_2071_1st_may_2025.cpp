#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
{
    int max_task = 0;
    sort(tasks.begin(), tasks.end());     // Sort tasks in ascending order (easier to assign easier tasks first).
    sort(workers.begin(), workers.end()); // Sort workers in ascending order (start with weaker workers).

    int task_index = tasks.size() - 1;     // Index of the hardest remaining task.
    int worker_index = workers.size() - 1; // Index of the strongest remaining worker.

    while (task_index >= 0 && worker_index >= 0)
    {
        if (workers[worker_index] >= tasks[task_index])
        {
            // Strongest worker can do the hardest task.
            max_task++;     // Assign the task.
            task_index--;   // Move to the next hardest task.
            worker_index--; // Move to the next strongest worker.
        }
        else if (pills > 0 && workers[worker_index] + strength >= tasks[task_index])
        {
            // Use a pill to help the worker do the task.
            max_task++;
            pills--; // Use a pill.
            task_index--;
            worker_index--;
        }
        else
        {
            // Current worker cannot do the task, even with a pill.
            worker_index--; // Try assigning this task to a weaker worker.
        }
    }
    return max_task;
}

int main()
{
    return 0;
}
