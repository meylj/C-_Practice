#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> v;
    v.reserve(10);
    for(int i=0; i<7; i++)
    {
    	v.push_back(i);
        std::cout<<v[i]<<" ";
    }
    std::cout << "finish1"<< std::endl;

    try
    {
    	int iVal1 = v[6];
    	int iVal2 = v.at(2);
    }
    catch(const std::exception& e)
    {
    	std::cout<<e.what()<<std::endl;
        std::cout << "finish2" << std::endl;
    }
    

    for (int i = 0; i < 7; ++i)
    {
        std::vector<int>::iterator first = v.begin();
        v.pop_back();
        //v.clear();
        v.erase(first,first++);
        std::cout<<v[i]<<" ";
    }
    std::cout << "finish3" << std::endl;

    std::vector<int>::iterator first = v.begin();
    while(first != v.end())
    {
        int i = *first;
        v.push_back(i);
        first++;
    }

    std::cout<<std::endl;
    for (int i = 0; i < 7; ++i)
    {
        std::cout<<v[i]<<" ";
    }
    std::cout << "finish4" << std::endl;

	return 0;
}
