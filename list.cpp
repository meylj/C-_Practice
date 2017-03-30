#include <iostream>
using namespace std;

template <class T> class Chain;
template <class T>
class ChainNode
{
	friend Chain<T>;
private:
	T data;
	ChainNode<T> *link;
public:
	ChainNode()
	{
		data = 0;
		link = 0;
		cout << "ChainNode instructor!\n";
	}
	~ChainNode()
	{
		cout << "ChainNode destructor!\n";
	}
};

template <class T>
class Chain
{
public:
	Chain() 
	{
		first = 0;
        cout << "Chain instructor!\n";
	}
	~Chain() {cout<<"Chain destructor!\n";}
    int Length() const;
    int Search(const T& x) const;
    Chain<T>&  Delete(int k, T& x);    //delete node
    Chain<T>&  Insert(int k, const T& x);    //insert node
	/* data */
private:
	ChainNode<T> *first;
};

int main(int argc, char const *argv[])
{
	ChainNode<int> node;
	ChainNode<int> *p=NULL;
	Chain<int> subNode;
	return 0;
}
