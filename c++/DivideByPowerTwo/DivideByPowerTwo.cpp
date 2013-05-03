#include<iostream>
using namespace std;

std::string getWritenAmount(int amount)
{
    string magic="";
    
    return magic;
}

int divideByTwoPower(int n, int p)
{
    int x=n;
    return x >> p;
}

int divideBySixteen(int n)
{
    return divideByTwoPower(n,4);
}

int main()
{
    //cout<<getWritenAmount(123)<<endl;
    //cout<<divideByTwoPower(16,3)<<endl;
    cout<<divideBySixteen(64)<<endl;
}