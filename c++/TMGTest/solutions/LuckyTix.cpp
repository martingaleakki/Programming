#include <vector>
#include <iostream>
#include <iterator>
#include <map>
using namespace std;

vector<int> Digits(int n)
{
    vector<int> dig;
    do {       /* generate digits in reverse order */
        int c = n % 10 ;        
        dig.push_back(c);   /* get next digit */
    } while ((n /= 10) > 0);
    return dig;
}

map<int,int> SumMap(int n)
{
    //Generate the map of number and sum of its digits
    map<int,int> sumMap;
    for(int i=0;i<n;i++){
        vector<int> digs=Digits(i);
        vector<int>::iterator itr = digs.begin();
        int digSum=0;
        while(itr!=digs.end())digSum+=*itr++;
        sumMap[i]= digSum;
        
    }
    
    return sumMap;
}


int LuckyTix(int n,bool print)
{
    int count =0;
    map<int,int> digMaps = SumMap(n);
    map<int,int>::iterator itr = digMaps.begin();
    //Count pairs of numbers which have the same sum of digits
    while(itr!=digMaps.end())
    {
        map<int,int>::iterator itr2 = digMaps.begin();
        
        while(itr2!= digMaps.end())
        {
            
            if(itr->second == itr2->second ) {
                count++;
                if(print)cout<<"Match"<<itr->first<<" "<<itr2->first<<endl;
            }
            itr2++;
        }
        itr++;
    }
    
  return count;
}

//This finds the number of lucky tickets from 000000 to 999999 
int main()
{
   
  cout<<LuckyTix(1000,false)<<endl;  
  return 0;  
    
}