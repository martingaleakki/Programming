
#include <iostream>
#include <vector>
#include<string>
using namespace std;

const char* aA[] = {"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
const char* bA[] = {"ELEVEN","TWELEVE","THIRTEEN","FOURTEEN","FIFTEEN","SIXTEEN",
               "SEVENTEEN","EIGHTEEN","NINTEEN"};
const char* cA[]={"TEN","TWENTY","THIRTY","FOURTY","FIFTY","SIXTY","SEVENTY","EIGHTY",
            "NINTY"};

vector<string> units(aA, aA+9);
vector<string> teens(bA, bA+9);
vector<string> tens(cA, cA+9); 

void Unit(int n){
    if(n==0) cout<<"ZERO";
    else cout<<units[n-1];
}
void Tens(int n){
    if(n>10&& n<20) cout << teens[n-11];
    else {
        cout << tens[(n/10) -1] << " ";
        if(n%10)Unit(n%10);
    }
}

void Hundreds(int n)
{
    if(n/100) {Unit(n/100);cout << " HUNDRED ";}
    if(n%100) {Tens(n%100);}     
}

void Thousands(int n)
{
    if(n/1000){ Unit(n/1000);cout << " THOUSAND ";}
    if(n%1000) { Hundreds(n%1000);}
}

void TenThousands(int n)
{
    if(n/1000){ Tens(n/1000);cout << " THOUSAND ";}
    if(n%1000) { Hundreds(n%1000);}
}

void HundredThousands(int n)
{
    if(n/1000){ Hundreds(n/1000);cout << " THOUSAND ";}
    if(n%1000) { Hundreds(n%1000);}
}

void Millions(int n)
{
    if(n/1000000){ Unit(n/1000000);cout << " MILLION ";}
    if(n%1000000) { HundredThousands(n%1000000);}
}
void TenMillions(int n)
{
    if(n/1000000){ Tens(n/1000000);cout << " MILLION ";}
    if(n%1000000) { HundredThousands(n%1000000);}
}

void HundredMillions(int n)
{
    if(n/1000000){ Hundreds(n/1000000);cout << " MILLION ";}
    if(n%1000000) { HundredThousands(n%1000000);}
}

void PrintNumber(int num)
{
    int numDig=0;
    int n = num;
    do { numDig++ ;} while ((n /= 10) > 0);
    switch(numDig)
    {
        case 1: Unit(num); break;
        case 2: Tens(num);break;
        case 3: Hundreds(num);break;
        case 4: Thousands(num);break;
        case 5: TenThousands(num);break;
        case 6: HundredThousands(num);break;
        case 7: Millions(num);break;
        case 8: TenMillions(num);break;
        case 9: HundredMillions(num);break;
        //So on and so forth
    }
}



int main()
{
    int n;
    cout<<"Enter Number To Print"<<endl;
    cin>>n;
    
    PrintNumber(n);
    return 0;
}
