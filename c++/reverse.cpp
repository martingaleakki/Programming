#include <iostream>

using namespace std;

string inplace(string s)
{
	char *p1,*p2;
	p1= &s[0];
	char c;
	int len=s.length();
	p2=&s[len-1];
	
	while(p1!=p2)
	{
		c=*p1;
		*p1++=*p2;
		*p2--=c;		    
	}
	
	return s;

}


int main()
{
string s="Hello World";
cout<<inplace(s)<<endl;
return 0;
}