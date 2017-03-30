#include <string>
#include <set>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	set<string> strset;   //declare a set veriable
	set<string>::iterator si;  //declare a set<string> iterator
	strset.insert("1");  //insert data to set
	strset.insert("2");
	strset.insert("3");
	strset.insert("4");
	strset.insert("5");
	strset.insert("6");
	for (si=strset.begin(); si!=strset.end(); ++si)   //use iterator to go through set
	{
		cout << *si << " ";    //output all datas from the set
	}
	cout << endl;
   
	return 0;
}