#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include <cmath>
using namespace std;
#define  NaN = log(0);

class TimeSeries {
public:
  TimeSeries(vector<int> &time,vector<double> &vals){
     this->time=time;
     this->vals=vals;
   }
  vector<int> Time(){return time;}
  vector<double> Vals(){return vals;}
private:
    vector<int> time;
    vector<double> vals;    
};


int WeakPreDecessor(vector<int> ts, int x)
{
  //assumes that the time series ts is sorted which is reasonable
  //Find the first element that is greater than x  
  vector<int>::iterator it= upper_bound(ts.begin(),ts.end(),x); // does a binary search - O(log n) - **** This is important
  if(it!=ts.begin())  return (--it - ts.begin()); // this will return the index of the element <= x
  else if( *it > x)return -1; // x is smaller than the lowest element in ts
   
}

TimeSeries TimeSeriesDiff(TimeSeries ts1,TimeSeries ts2)
{
    vector<int> tDiffs;
    vector<double> valDiffs;
    
    vector<int> time1= ts1.Time();
    vector<int> time2= ts2.Time();
    vector<double> prices1 = ts1.Vals();
    vector<double> prices2 = ts2.Vals();
    int maxTime = max(time1[time1.size()-1],time2[time2.size()-1]);
    int time = 0;
    while(time <= maxTime)
    {
        int i1 = WeakPreDecessor(time1,time);
        int i2 = WeakPreDecessor(time2,time);
        double diff;
        
        if(i1== -1 || i2 == -1) diff = log(0); // Want to assign NaN if one of the elements has no weak predecessor
        else { diff = fabs( prices1[i1] -  prices2[i2]);}
        tDiffs.push_back(time);
        valDiffs.push_back(diff);
        time+=10;
    }    
    
    TimeSeries tsDiff(tDiffs,valDiffs);
    return tsDiff;
}

//int main()
//{
//    int t1[] = {4,15,23,30,45};
//    int v1[] = {2,2.4,3.4,4,4.5};    
//    std::vector<int> time1(t1,t1+5); 
//    std::vector<double> value1(v1,v1+5);
//    TimeSeries ts1(time1,value1);
//    int t2[] = {3,10,13,30,50};
//    int v2[] = {2,2,3.4,4,5};    
//    std::vector<int> time2(t2,t2+5); 
//    std::vector<double> value2(v2,v2+5);
//    TimeSeries ts2(time2,value2);
//    TimeSeries tsDiff = TimeSeriesDiff(ts1,ts2);
//    return 0;
//}