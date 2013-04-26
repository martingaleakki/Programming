#include <iostream>
using namespace std;
class temp
{
	int i;
	public:
	static const temp min;

}

const temp::min = temp();

int main()
{

	cout<<sizeof(temp)<<endl;

}