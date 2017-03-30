#include <iostream>
using namespace std;

int gcd(int, int);
int lcm(int, int);

int main(int argc, char const *argv[])
{
	int x = 3, y=8;

	cout<< "the greated common divisor is " << gcd(x, y) <<endl;
	cout << "the lowest common multiple is " << lcm(x, y) <<endl;


	return 0;
}

int gcd(int x, int y)
{
	int r = 0;

    if(x > y)
    {
    	x += y;
    	y -= x;
    	x += y;
    	y *= -1;
    }

    while((r = x%y) != 0)
    {
    	x = y;
    	y = r;
    }

    return y;
}

int lcm(int x, int y)
{
	return (x*y/gcd(x,y));
}