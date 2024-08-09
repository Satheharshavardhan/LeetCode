#include <iostream>
#include <vector>

using namespace std;

int findTheWinner(int n, int k)
{
    vector<int> player;
    for (int i = 1; i <= n; i += 1)
    {
        player.push_back(i);
    }
    int current = 0;
    while (player.size() != 1)
    {
        current = (current + (k - 1)) % player.size();
        player.erase(player.begin() + current);
    }
    return player[0];
}

int main()
{
    cout << findTheWinner(5, 2);
    return 0;
}