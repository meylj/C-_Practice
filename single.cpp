#include<iostream>
using namespace std;

class Singleton
{
private:
    static Singleton * singleton;
private:
    Singleton()
   { }

public:
    static Singleton *getinstance()
    {
        if(singleton==NULL)
        {
            singleton=new Singleton();
        }

    return singleton;
    }
};

Singleton* Singleton::singleton;

int main()
{ 

Singleton *p=Singleton::getinstance();
Singleton *q=Singleton::getinstance();
cout<<"p : "<<p<<" q :"<<q<<endl;
return 0;
}
