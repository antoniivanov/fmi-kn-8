#include <iostream>

using namespace std;

void factor(int n, int m)
{
    for (int i = 1; i < n; i++)
    {
        if (i % m == 0)
        {
            cout << i << "\n";
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    factor(n, m);
    return 0;
}