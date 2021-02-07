#include <iostream>
#include "utils1.h"
#include "utils2.h"

int main()
{
    int a = 2;
    int b = 3;
    int c = addInt(a, b);
    int d = addInt1(a, b);
    int e = addInt2(a, b);
    
    std::cout << "a is " << a << ", b is " << b << ", the sum c is " << c << ", the sum d is " << d << std::endl;

}