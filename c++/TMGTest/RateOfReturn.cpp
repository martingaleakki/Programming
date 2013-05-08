#include <cmath>
#include <iostream>
using namespace std;

double RateOfReturn(double pv, int d)
{
    double n = d/365.0;
    double yield = pow(100.0/pv,1.0/n) -1;
    return 100*yield;
}

//int main()
//{
//    double pv;
//    int d;
//    cout<<"Enter PV"<<endl;
//    cin>>pv;
//    cout<<"Enter Days to maturity"<<endl;
//    cin>>d;
//    cout<<"Rate of Return (%)"<< RateOfReturn(pv,d)<<endl;
//    return 0;
//}