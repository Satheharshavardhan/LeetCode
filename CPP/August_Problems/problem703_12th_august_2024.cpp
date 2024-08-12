#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int> &nums) : k(k)
    {
        for (int num : nums)
        {
            add(num);
        }
    }

    int add(int val)
    {
        if (minHeap.size() < k)
        {
            minHeap.push(val);
        }
        else if (val > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};

int main()
{
    return 0;
}