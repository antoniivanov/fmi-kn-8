#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n<=0)
    {
        cout<< "incorrect input \n";
        return 1;
    }
    int fact=1;

    for(int i=1;i<=n; i++)
        fact=fact*i;
    cout<< n <<"!=" <<fact <<endl;


     //or
     /* while (n > 1)
    {
        factoriel *= n;
        n--;
    }
    */

    return 0;
}
