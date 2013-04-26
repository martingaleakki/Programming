#include <iostream>
using namespace std;

int main()
{
	int i=0;
	int val=1;
	int num=16;
	
	while ((val=1<<i) <= num) 
	{	
		if(val&num)
		cout <<1;
		else cout<<0;
		i++;
	}


}