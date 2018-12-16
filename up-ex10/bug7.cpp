#include <iostream>
int main()
{
    int a = 5, b;
    const int const *const p = &a;
    std::cout << *p << std::endl;
    *p = 10;
    p = &b;
    return 0;
}