#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <istream>
#include <algorithm>
#include <iterator>
#include <vector>
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


void JumpleSort(vector<string> input)
{
    vector<int> numbers;
    vector<string> words;
    
    for(int i=0;i<input.size();i++)
    {
        if(isInt(input[i])) numbers.push_back(atoi(input[i].c_str()));
        else words.push_back(input[i]);
    }
    
    sort(numbers.begin(),numbers.end());
    sort(words.begin(),words.end());
    
    vector<int>::iterator numItr = numbers.begin();
    vector<string>::iterator strItr = words.begin();
    for(int i=0;i<input.size();i++)
    {
        if(isInt(input[i])) cout<<*numItr++;
        else cout<<*strItr++;
        cout<<" ";
    }
    
}



int main()
{    
    string input;
    cout<<"Enter a line"<<endl;
    getline (cin,input);
    //printVector(split(input,' '));
    JumpleSort(split(input,' '));
    return 0;
}