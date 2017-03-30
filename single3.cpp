#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton(){}
    static Singleton *m_stance;
    class ReleaseObj
    {
    public:
        ~ReleaseObj()
        {
            if(Singleton::GetInstance())
            {
                delete Singleton::GetInstance();
                cout<<"destructor call!"<<endl;
            }
        }
    };
    static ReleaseObj obj; //定义一个静态成员函数，系统释放资源时调用析构函数
public:
    static Singleton* GetInstance()
    {
        static Singleton* instance;
        cout<<"Instructor call"<<endl;
        return instance;
    }    
};

int main()
{
    Singleton *p = Singleton::GetInstance();
    cout<<p<<endl;

    return 0;
}
