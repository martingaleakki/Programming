#include <cmath>
#include <iostream>
using namespace std;

double RateOfReturn(double pv, int d)
{
    double n = d/365.0;
    double yield = pow(100.0/pv,1.0/n) -1;
    return yield;
}

//int main()
//{
//    cout<<  RateOfReturn(95.5,153)<<endl;
//    return 0;
//}