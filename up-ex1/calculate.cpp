#include <iostream>
using namespace std;

int main()
{
    int a,b;
    char op;
    cin >> a >> op >> b;
    switch(op)
    {
        case'+': cout<<a+b;
        break;
        case'*': cout<<a*b;
        break;
        case'-': cout<<a-b;
        break;
        case'/': if(b!=0) return a/b;
        break;
        case'%': cout<<a%b;
        break;
        default: cout<<"no result";
    }


    /* if (op == '+')
    {
        cout << x + y << "\n";
    }
    else if (op == '-')
    {
        cout << x - y << "\n";
    }
    else if (op == '*')
    {
        cout << x * y << "\n";
    }
    else if (op == '/')
    {
        if (y != 0)
        {
            cout << x / y << "\n";
        }
        else
        {
            cout << "cannot divide by 0\n";
        }
    }
    else
    {
        cout << "invalid operation\n";
    }
    */
    return 0;
}
