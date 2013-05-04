#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

void IntegerToBits(int num)
{
    std::bitset<32> a(num);
    cout<<a<<endl;
}

short swap_bytes(short input)
{
    bitset<16> bits(input);
    unsigned char bit;
    for(int i=0;i<8;i++)
    {
       bit = bits[i];
       bits[i]= bits[i+8];
       bits[i+8]=bit;
    }
    short myShort = static_cast<short>( bits.to_ulong() );
    
    return myShort;
}



int main()
{
    int n=7;
    IntegerToBits(n);
    IntegerToBits(swap_bytes(n));    
}