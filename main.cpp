#include <iostream>


int main(void)
{
    std::string *test = "hello";
    std::string test2 = "world";
    std::string& ref = test1;
    std::string& ref2 = test2;

    std::cout << test << std::endl;
    std::cout << test2 << std::endl;
    std::cout << ref << std::endl;
    std::cout << ref2 << std::endl;

    return 0;
}