#include <iostream>
int main()
{
    int a, b;
    int *const p = &a;
    *p = 5;
    p = &b;
    return 0;
}