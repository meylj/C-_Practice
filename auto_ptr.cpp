#include <iostream>
/*
**智能指针：auto_ptr, shared_ptr, unique_ptr, weak_ptr
*/
#include <memory>    //包含智能指针的头文件


bool weird_thing()
{
    return false;
}

void remodel(std::string &str)
{
	//普通指针，需要手动释放内存
	std::string *ps = new std::string("hi!");
	if (weird_thing())
	{
		delete ps;
		throw std::exception();
	}
	str = *ps;
	std::cout << str << std::endl;
	delete ps;
	return;
}

void remodel2(std::string &str)
{
	//auto_ptr智能指针，是将普通指针封装成对象，可以调用析构函数在对象结束使用后
	std::auto_ptr <std::string> ps (new std::string("Linda!"));
	if (weird_thing())
	{
		throw std::exception();
	}
	str = *ps;
	std::cout << str << std::endl;
	return;
}

int main(int argc, char const *argv[])
{
	std::string str = "hello world!";
	remodel(str);
	remodel2(str);

    std::shared_ptr <double> pd;
    double *p_reg = new double(23.2);
    std::cout << *p_reg << std::endl;
   // pd = p_reg;    //not allowed, implicit conversion
    pd = std::shared_ptr <double> (p_reg); //allowed, explicit conversion
    //std::shared_ptr <double> pshared = p_reg; // not allowed, implicit conversion
    std::shared_ptr <double> qshared(p_reg);    //allowed, explicit conversion
    std::cout << *p_reg << std::endl;

    //对所有三种智能指针都应避免这点：
    // std::string vacation("I wandered lonely as a cloud.");
    // std::shared_ptr<string> pvac(&vacation);    
    // //No,pvac过期时，程序将把delete运算符用于堆内存，错误？？？


	return 0;
}