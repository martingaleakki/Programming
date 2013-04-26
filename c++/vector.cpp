#include <vector>
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class tempo
{
int i;
};


string print()
{
	return "Hello World";
}


int main()
{
string (*func)();
vector<int> temp(2,1);
cout << temp.size()<<temp[0]<<temp[1]<<endl;

func=print;	

cout<<(*func)()<<endl;
temp[1]=3;
//temp.front()=13;
temp.insert(temp.begin(),12);
cout<<temp[0]<<" "<<temp[1]<<endl;


cout<<sizeof(tempo)<<endl;
return 0;
}

