#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string getMissingLetters(const string& sentence)
{
   string missingLetters="";   
   bool alphabets[26] = {0};
   string::const_iterator ptr = sentence.begin();   
   while(ptr != sentence.end())
   {
       if(!isalpha(*ptr)) ptr++;
       alphabets[(tolower(*ptr) - 'a')]=true;
       ptr++;
   }   
   for(int i=0;(i<26);i++){
       if(!alphabets[i])missingLetters.push_back('a'+i);
   }   
   return missingLetters;
}

vector<string> animate(int speed, const string& init)
{
    vector<string> animation;
    string singleStepAnimation;    
    
    int initSpeed=speed;
    singleStepAnimation = string(init.length(),'.');
    speed=0;
    while(true)
    {   
    for(int i=0;i<init.length();i++){
      int steps=0;
      if(init[i]=='L') steps = -speed;
      else if(init[i]=='R') steps = speed;
      else continue;
      if((i+steps)>= init.length()|| (i+steps) < 0 ) continue;
      singleStepAnimation[i+steps]='X';
      }
    
    animation.push_back(singleStepAnimation);    
    speed+=initSpeed;
    if(singleStepAnimation==string(init.length(),'.'))break;
    singleStepAnimation = string(init.length(),'.');
    }  
    
return animation;
}

int main()
{
    //cout<<getMissingLetters("A slow yellow fox crawls under the proactive dog")<<endl;
    vector<string> steps= animate(1,"LRRL.LR.LRR.R.LRRL.");
    for(int i =0;i<steps.size();i++) cout<<steps[i]<<endl;
}