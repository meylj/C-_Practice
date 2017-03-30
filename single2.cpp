#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton(){}
    static Singleton *p_instance;
public:
    static Singleton * GetInstance()
    {
        if(p_instance == NULL)
            p_instance = new Singleton();
        return p_instance;
    }
};

Singleton* Singleton::p_instance;

int main(int argc, const char* argv[])
{
    Singleton *p = Singleton::GetInstance();
    Singleton *q = Singleton::GetInstance();
    Singleton *rf = q;
    cout<<"p="<<p<<endl<<"q="<<q<<endl<<"rf="<<rf<<endl;

    return 0;
}
