#include <vector>
#include <iostream>
using namespace std;


void SoldierSpyN(int N)
{
    int sum = N*(N+1)/2;
    int runningSum=0;
    for(int i=0;i<N-1;i++){
        int p=0;
        cout<<"Enter Patch Number "<<i+1<<endl;
        cin>>p;
        runningSum+=p;
    }
    cout<<"Spy: "<<sum - runningSum<<endl;
}

int main()
{
    //This program illustrates for size 10. Size 100 would be similar.
    //TestSoldierSpy10();
    int N=0;
    cout<<"Enter Total Number of Soldiers"<<endl;
    cin>>N;
    SoldierSpyN(N);
}