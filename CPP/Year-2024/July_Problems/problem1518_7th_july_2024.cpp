#include <iostream>

using namespace std;

int numWaterBottles(int numBottles, int numExchange)
{
    int result = 0, empty_bottel = 0;
    while (numBottles > 0)
    {
        result += numBottles;
        empty_bottel += numBottles;
        numBottles = (int)(empty_bottel / numExchange);
        empty_bottel = empty_bottel - (numBottles * numExchange);
    }
    return result;
}

int main()
{
    cout << numWaterBottles(9, 3);
    return 0;
}