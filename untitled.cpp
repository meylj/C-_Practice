#include <iostream>
#include <string>

#define ADD(A,B) (A)+(B)

int main()
{
	int i1(1), i2(2);
    std::string s1("Hello, "), s2("world!");
    int i = ADD(i1, i2);
    std::string s = ADD(s1, s2);
    std::cout << "i = "<< i << endl;
    std::cout << "s = "<< s << endl;

    return 0;
}