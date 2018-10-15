#include<iostream>

using namespace std;


int main()
{
    /*int n1;

    int number;
    int counter=0;

    cin>>n1;

    do
    {
        counter++;
        cin>>number;

        if(number>n1)
        {
            cout<<"too big" <<endl;
        }
        else if(number<n1)
        {
            cout<<"too small" <<endl;
        }
        else
            cout<<"that's the number"<<endl;

    }
    while(number!=n1);
    */


    int secretNum, guessNum;
    int cnt = 0;
    cin >> secretNum;
    while(true)
    {
        cnt++;
        cin >> guessNum;
        if (guessNum < secretNum)
        {
            cout << "Too small\n";
        }
        else if (guessNum > secretNum)
        {
            cout << "Too big\n";
        }
        else
        {
            cout << "You guessed it ;) in " << cnt << "tries\n";
            return 0;
        }
    }
    return 0;
}
