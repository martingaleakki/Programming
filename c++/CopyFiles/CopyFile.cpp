#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <istream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
using namespace std;

//TODO: Move this string functions to a common library

string numToStr(int i)
{
  string s = static_cast<ostringstream*>( &(ostringstream() << i) )->str();
  return s;
}
bool isInt(string s){
    int i = atoi(s.c_str());
    return s == numToStr(i);
}

vector<string> split(string s,char token)
{
  // construct a stream from the string
  std::stringstream strstr(s);  
  string word;
  vector<string> result;
  
  while (getline(strstr, s, token)) {
      result.push_back(s);
  }
 
  return result;
}

void printVector(vector<string>results)
{
  std::ostream_iterator<std::string> oit(std::cout);
  std::copy(results.begin(), results.end(), oit);
}

void CopyFile(vector<string> dataIDList)
{
    map<int, vector<string> > dcdataIDs;
    map<int, vector<int> > idToDC;
    map<int, vector<int> >::iterator itr;
    for(int i=0;i<dataIDList.size();i++)
    {
        vector<string> ids = split(dataIDList[i],' ');
        dcdataIDs[i]=ids;
       
        for(int j=0;j<ids.size();j++){
                          
            idToDC[atoi(ids[j].c_str())].push_back(i+1);
        }       
    }
    
    itr = idToDC.begin();
    while(itr!=idToDC.end())
    {
        vector<int>::iterator itr2;
        int id = itr->first;
        vector<int> dcs = itr->second;    
        for(int i=1;i<=dataIDList.size();i++)
        {
            itr2=find(dcs.begin(),dcs.end(),i);
            if(itr2==dcs.end()) cout<<id<<" "<<dcs.front()<<" "<<i<<endl;           
        }
        itr++;
    }  
    
}

int main()
{
    int numDC=0;
    string n;
    getline(cin,n);
    numDC=atoi(n.c_str());
    vector<string> dataIDList ;
    string input;
    
    for(int i=1;i<=numDC;i++){ 
        getline (cin,input);
     dataIDList.push_back(input);
    }
    cout<<"Solution"<<endl;
    CopyFile(dataIDList);
    cout<<"done"<<endl;
    return 0;
}
