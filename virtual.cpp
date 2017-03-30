#include <iostream>
using namespace std;

class Cshape
{
public:
	Cshape(int color)
	{
        m_nColor = color;
        cout<<"This is common structor function call!"<<endl;
        cout<<"The data is:"<<m_nColor<<endl;
	}
    Cshape()
    {
    	cout<<"This is common no prameter structor function call!"<<endl;
        cout<<"The data is:"<<m_nColor<<endl;
    }
    Cshape(Cshape& hrs)
    {
    	m_nColor = hrs.m_nColor;
    	cout<<"This is copy structor function call!"<<endl;
        cout<<"The data is:"<<m_nColor<<endl;
    }
    virtual ~Cshape()
    {
        cout<<"Cshape destructor function call"<<endl;
    }

	void SetColor(int color)
	{
		m_nColor = color;
	}

	void virtual Display(void)
	{
		cout<<"Cshape"<<endl;
	}
private:
	int m_nColor;
};

class  Crectangle: public Cshape
{
public:

	void virtual Display(void)
	{
		cout<<"Crectangle"<<endl;
	}
	virtual ~Crectangle()
    {
        cout<<"Crectangle destructor function call"<<endl;
    }
};

class Ctriangle: public Cshape
{
public:
    
	void virtual Display()
	{
		cout<<"Ctriangle"<<endl;
	}

	virtual ~Ctriangle()
    {
        cout<<"Ctriangle destructor function call"<<endl;
    }
};

class Cellipse: public Cshape
{
public:

    void virtual Display()
    {
    	cout<<"Cellipse"<<endl;
    }
    virtual ~Cellipse()
    {
        cout<<"Cellipse destructor function call"<<endl;
    }
};

class Csquare:public Cshape
{
public:
	
	void virtual Display()
    {
    	cout<<"Csquare"<<endl;
    }

    virtual ~Csquare()
    {
        cout<<"Csquare destructor function call"<<endl;
    }
};

int main(int argc, char const *argv[])
{
    Cshape obshape;
    Cellipse obEllipse;
    Ctriangle obTriangle;
    Csquare obSquare;
    Cshape &hrsCshape = obshape;
    Cshape *pShape[4] = {&obshape, &obEllipse, &obTriangle, &obSquare};
    for (int i = 0; i < 4; ++i)
    {
    	pShape[i]->Display();
    }
	return 0;
}