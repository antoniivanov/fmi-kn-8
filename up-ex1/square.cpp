#include <iostream>
using namespace std;

int main()
{
    double x,y;
    cin>>x;
    cin>>y;

    //return ((x<-1 ||x>1) && (y>1||y<-1)) && x*x+y*y<=4;

    if (x < 0) x *= -1;
    if (y < 0) y *= -1;

    if ((x*x + y*y <= 2*2) && (x >= 1 || y >= 1))
    {
        cout << "in\n";
    }
    else
    {
        cout << "out\n";
    }
    return 0;
}
