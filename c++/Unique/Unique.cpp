#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<int> readTestCase()
{
    int x;
    vector<int> testCase;
    string path="F:\\Programming\\TestCases\\";
    string fileName="dup.txt";
    string const fullPath = path + fileName;
    ifstream fileHandle;
    fileHandle.open(fullPath.c_str(),ios::in);
    if(!fileHandle){
        cerr<<"Unable to open "<<fullPath<<endl;
        exit(1);
    }
    while(fileHandle >> x){
//        cout<<x<<endl;
        testCase.push_back(x);
    }
    fileHandle.close();
    return testCase;
}

void Unique(vector<int> data)
{
    cout<<data[0]<<endl;
    for(int i=1;i<data.size();i++)
    {
        if(data[i]!=data[i-1])
        {
            cout<<data[i]<<endl;
        }
    }
}

int main()
{
    vector<int> testCase;
    testCase = readTestCase();
    Unique(testCase);
    return 0;
}
