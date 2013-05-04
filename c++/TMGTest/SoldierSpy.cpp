#include <vector>
#include <iostream>
using namespace std;
int SoldierSpy(vector<int> patches)
{
    int n= patches.size()+1;
    int totalSum = n *(n+1)/2;
    vector<int>::iterator itr = patches.begin();
    int sum=0;
    while(itr!=patches.end())
    {
        sum += *itr;
        itr++;
    }
    return totalSum - sum;
}

//int main()
//{
//    static const int arr[] = {1,2,3,4,5,6,7,8,9};
//    vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );    
//    cout << SoldierSpy(vec)<<endl;
//}