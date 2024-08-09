#include <iostream>

using namespace std;

int main()
{
    double a[2] = {20.0, 25.0};
    double *p, *q;
    p = a;
    q = p + 1;
    cout << (int)(q - p) << " : " << (int)(*q - *p);
}