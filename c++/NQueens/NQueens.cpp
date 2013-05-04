#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
bool CheckQueen(vector<int> pos, int p)
{
    bool valid = false;
    int n = pos.size();
    for(int i=0;i<n;i++)
    {
        if((pos[i]==p) || abs(n - i) == abs(p - pos[i])) valid =true;
    }
    return valid;
}

void NQueens(int N,int n,vector<int> pos)
{
    if(N==n) {
        cout<<"Found Solution:"<<endl;
        for(int i=0;i<pos.size();i++) cout<<pos[i];
        cout<<endl;
    }
    else{
     
        for(int i=0;i<N;i++)
        {
          if(!CheckQueen(pos,i)) {
              pos.push_back(i);
              NQueens(N,n+1,pos);
              pos.pop_back();
          }            
        }      
    }    
}



int main()
{
    vector<int> pos;
    NQueens(5,0,pos);
    return 0;   
}