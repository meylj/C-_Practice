#include <iostream>
using namespace std;

template<T> class Double;
template <class T>
class DoubleNode
{
	friend Double<T>;
private:
	T data;
	DoubleNode<T> *left, *right;
};

template<class T>
class Double
{
public:
	Double()
	{
		leftEnd = rightEnd = 0;
	}
	~Double();

	int length()const;
	int search(const T& x) const;
	Double<T>& Delete(int k, T& x);
	Double<T>& Insert(int k, const T& x);
private:
	DoubleNode<T> *leftEnd, *rightEnd;
};

int Double::length()const
{
	int len = 0;
	while(leftEnd != rightEnd)
	{
        len++;
        rightEnd = rightEnd->right;
	}
    return len;
}

int Double::search(const T&	 x) const
{
	int flag = 1;
	while(flag)
	{
		if (rightEnd.data == x)
	    {
	    	flag = 0;
		    return 1;
	    }
	    else
	    {
            while((leftEnd != rightEnd) && (rightEnd.data != x))
            {
                 rightEnd = rightEnd->right;
            }
	    }
	}
	if (flag == 0)
	{
		return 1;
	}
	else
        return 0;
	
}