#include <iostream>


class test{

public:
	test();
	const int a;

private:
	
};

test::test() :
	a(42)
{
	// a = 42;
}

int main(void)
{
	test test;
	std::cout << test.a << std::endl;

	return 0;
}
