#include <ctype.h>
#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(const char* str)
{
    int i=0;
    int len=strlen(str);
    const char* head = &str[0];
    const char* tail= &str[len-1];   
    
    while(head != tail)
    {
      if(isalpha(*head) && isalpha(*tail))
      {
          if(tolower(*head) == tolower(*tail)){
              head++;
              tail--;
          }
          else return false;
      }
      else if (isalpha(*head))
      {
          tail--;
      }
      else if (isalpha(*tail))
      {
          head++;
      }
      else
      {
          head++;
          tail--;
      }
    }    
return true;    
}

int main()
{
   cout<< isPalindrome("MadamAdam")<<endl;
}