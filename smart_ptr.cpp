#include <iostream>
#include <memory>

using namespace std;

class report
{
private:
	string str;
public:
	report(const string s):str(s)
	{
		cout << "Object created!" << endl;
	}
	~report()
	{
		cout << "Object released!" << endl;
	}

	void comment()const
	{
		cout << str << "\n";
	}
};

int main(int argc, char const *argv[])
{
	auto_ptr <report> auto_ps (new report("using auto_ptr!"));
	auto_ps->comment();

    shared_ptr <report> shared_ps (new report("using shared_ptr!"));
    shared_ps->comment();

    unique_ptr <report> unique_ps (new report("using unique_ptr!"));
    unique_ps->comment();

    // auto_ptr <string> films[5] = {
    // 	auto_ptr<string>(new string("fowl balls")),
    // 	auto_ptr<string>(new string("duck walks")),
    // 	auto_ptr<string>(new string("chicken runs")),
    // 	auto_ptr<string>(new string("turkey eggs")),
    // 	auto_ptr<string>(new string("goose eggs"))
    // };

    // auto_ptr<string> pwin;    //若改成shared_ptr或unique_ptr程序不会奔溃，但unique_ptr编译时会出错
    //auto_ptr和unique_ptr都采用所有权模型，shared_ptr采用引用计数模型
    //films[2] loses ownership,将所有权转让给pwin，films[2]不再引用该字符串变成空指针
    //访问空指针，程序会奔溃
    //所以为什么要摒弃auto_ptr？就是为了避免潜在的内存奔溃问题
    //unique_ptr优于auto_ptr的原因：1.在编译时就会检查语法错误，更安全；2.unique_ptr没有机会使用无效的数据
    shared_ptr <string> films[5] = {
    	shared_ptr<string>(new string("fowl balls")),
    	shared_ptr<string>(new string("duck walks")),
    	shared_ptr<string>(new string("chicken runs")),
    	shared_ptr<string>(new string("turkey eggs")),
    	shared_ptr<string>(new string("goose eggs"))
    };

    shared_ptr<string> pwin; 

    pwin = films[2]; 
    cout << "the nominees for best avian baseball film are:\n";
    for (int i = 0; i < 5; ++i)
    {
    	cout << *films[i] << endl;
    }
    cout << "the winner is:" << *pwin << endl;
    cin.get();

    // unique_ptr<string> pu1(new string("hello world"));
    // unique_ptr<string> pu2;    //留下了悬挂的pu1指针，可能造成危害
    // pu2 = pu1;    //not allowed

    unique_ptr<string> pu3;
    pu3 = unique_ptr<string>(new string("you"));    //allowed

    

	return 0;
}



