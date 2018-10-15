#include <iostream>
using namespace std;

int main()
{
    unsigned int n;
    int a1=1,a2=1,temp;
    cin>>n;

    if(n==1 || n==2)
        cout<<a1;
    else
    {
        for(int i=3;i<=n;i++)
        {
            temp=a1+a2;
            a2=a1;
            a1=temp;
        }
        cout<<"fib("<<n<<")="<<a1;
    }


   /* int first = 0, second = 1;

    for (int i = 1; i < n; i++)
    {
        second += first;
        first = second - first;
    }

    cout << first << "\n";

    */

    return 0;
}
