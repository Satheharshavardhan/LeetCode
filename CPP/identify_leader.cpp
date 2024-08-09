#include <iostream>
#include <vector>

using namespace std;

vector<int> identify_leader(vector<int> &members)
{
    vector<int> leaders;
    leaders.push_back(members.back());
    int max_element = leaders[0];
    for (int i = members.size() - 2; i >= 0; i -= 1)
    {
        if (members[i] > max_element)
        {
            leaders.push_back(members[i]);
            max_element = members[i];
        }
    }
    return leaders;
}

int main()
{
    vector<int> members = {7,6,9,5,3,78,9,12,4};
    vector<int> leaders = identify_leader(members);
    cout << "The leaders are : ";
    for (const auto &num : leaders)
    {
        cout << num << " ";
    }
    return 0;
}