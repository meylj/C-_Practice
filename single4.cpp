#include <iostream>
using namespace std;

#ifndef _SINGLETON_H_
#define _SINGLETON_H_

class Singleton
{
private:
    static Singleton* m_instance;
    Singleton(){}
    Singleton(const Singleton &){}
    Singleton& operator = (const Singleton&){}
public:
    static Singleton* GetInstance();
};
#endif

Singleton* Singleton::m_instance = new Singleton();
Singleton* Singleton::GetInstance()
{
    return m_instance;
}

int main()
{
    Singleton *p = Singleton::GetInstance();
    Singleton *q = Singleton::GetInstance();
    cout<<"p="<<p<<endl<<"q="<<q<<endl;
    return 0;
}
