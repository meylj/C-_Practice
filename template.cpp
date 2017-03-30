#include <iostream>
#include <string>
using namespace std;

template<class T, class T2, int num>
class CSampleTemplate
{
public:
	CSampleTemplate(T arg1, T2 arg2)
	{
		t1 = arg1 + num;
		t2 = arg2 + num;
	}
	~CSampleTemplate(){}

	void Write()
	{
		cout<<"t1:"<<t1<<"  t2:"<<t2<<endl;
	}
private:
	T t1;
	T2 t2;
};


template<class T>
T Add(T a, T b)
{
    T result;
    result = a + b;
    return result;
}

int main(int argc, char const *argv[])
{
    CSampleTemplate<int, int, 3> temp(1, 2);
    CSampleTemplate<double, int, 3> temp2(3.0, 3);
    temp.Write();
    temp2.Write();

    cout << "2+3=" << Add(2, 3) << endl;
    const char *a = "a", *b = "b";
    cout << "a+b=" << Add(string(a), string(b)) << endl;
	return 0;
}



int fucTest()
{
	try
	{
		char* pst = new char[20];
	}
	catch(const bad_alloc& e)
	{
		return -1;
	}
}

void *operator new(size_t cb, const std::nothrow_t&) throw()
{
	char *p;
	try
	{
		p = new char[cb];
	}
	catch(std::bad_alloc& e)
	{
		p = 0;
	}
	return p;
}

