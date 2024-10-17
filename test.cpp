#include <iostream>
#include "mystring.h"

int main()
{
    MyString alma = MyString("alma", 4);
    char *text = alma.getChar();
    
    std::cout<< text <<std::endl;

    return 0;
}