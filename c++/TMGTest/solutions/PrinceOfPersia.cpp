#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define MAX 99999
using namespace std;

int levels;
int row;
int col;

class Pos
{
 private:
        int x,y,z;
        int dist;
        Pos* parent;
        Pos* child;
 public:
     Pos(int x,int y,int z,int dist)
     {
        this->x=x;
        this->y=y;
        this->z=z;
        this->dist=dist;
        parent==NULL;
        child==NULL;
     }  
     int X()const {return x;}
     int Y()const {return y;}
     int Z()const {return z;}
     int D(){return dist;}
     void Print() { cout <<"L:"<< x << " R:" <<y<<" C:"<<z<<endl;}
     Pos* Parent() {return parent;}
     Pos* Child() {return child;}
     void SetD(int d){dist =d;}
     void SetParent(Pos &p){ parent = &p;} 
     void SetChild(Pos &p){ child = &p;}
     bool operator==(const Pos& p) const
     {
         return ((x==p.X())&&(y==p.Y())&&(z==p.Z()));
     }
     
     bool operator!=(const Pos& p) const
     {
         return ((x==p.X())&&(y==p.Y())&&(z==p.Z()))? false:true ;        
     }
};

bool isEdge(Pos p1,Pos p2)
{
    if(abs(p1.X() - p2.X()) == 0 && abs(p1.Y()-p2.Y()) == 0 && abs(p1.Z()-p2.Z()) ==1) return true;
    else if(abs(p1.X() - p2.X()) == 0 && abs(p1.Y()-p2.Y()) == 1 && abs(p1.Z()-p2.Z()) ==0) return true;
    else if(abs(p1.X() - p2.X()) == 0 && abs(p1.Y()-p2.Y()) == 0 && abs(p1.Z()-p2.Z()) ==1) return true;
    else if(abs(p1.X() - p2.X()) == 1 && abs(p1.Y()-p2.Y()) == 0 && abs(p1.Z()-p2.Z()) ==0) return true;
    else return false;    
}

vector<Pos> ValidPos(int Levels,int Rows, int Cols,vector<Pos> Pillars,Pos start)
{
    vector<Pos> validPositions;
    for(int i=1;i<=Levels;i++)
          for(int j=1;j<=Rows;j++)
              for(int k=1;k<=Cols;k++)
              {
               Pos p(i,j,k,MAX);
               if(p==start) p.SetD(0);
               if(Pillars.end() == find(Pillars.begin(),Pillars.end(),p))
               {
                   validPositions.push_back(p);
               }
              }
return validPositions;    
}

int FindMinD(vector<Pos> p,vector<int> visited)
{
    int minD = MAX;
    int minDI = -1;
    for(int i=0;i<p.size();i++)
    {
      if(find(visited.begin(),visited.end(),i)==visited.end())
      {
          if(minD > p[i].D()) 
          {
              minD = p[i].D();
              minDI = i;
          }
      }
    }
    return minDI;
}

//Implements Dijkstra Algorithm
void ShortestPath(int Levels,int Rows, int Cols,vector<Pos> Pilars,Pos Start,Pos End)
{
    //Intially the shortest time to every other node is  infinity except itself
    vector<Pos> allPos = ValidPos(Levels,Rows,Cols,Pilars,Start);    
    //Keep a list of nodes visited and the minimum time to reach them so far and their parent that gives the minimum time
    vector<int> visited;    
    while(visited.size()!= allPos.size())
    {     
    //Start with the node which as the shortest time so far and is not the end node
    int minDI = FindMinD(allPos,visited);    
    //Mark it as visited
    visited.push_back(minDI);
    //Update the shortest time for all nodes reachable from the node found above
    for(int i=0;i<allPos.size();i++)
    {
        if(i != minDI && isEdge(allPos[minDI],allPos[i])) {
            if(allPos[i].D() > allPos[minDI].D()+5)
            {
                allPos[i].SetD(allPos[minDI].D()+5);
                allPos[i].SetParent(allPos[minDI]);
                allPos[minDI].SetChild(allPos[i]);
            }           
        }
    }
    }
    //Find the node that has the shortest time from all nodes except those visited
    //Iterate till end node is found
    vector<Pos>::iterator itr = find(allPos.begin(),allPos.end(),End);    
    int step=0;
    Pos * ptr = & *itr;
    while((*ptr) != Start) {
        ptr->Parent()->SetChild(*ptr);
        ptr=ptr->Parent();
    }
    cout<<"Solution :"<<endl;
    cout<<"Start:";
    ptr->Print();
   
    while((*ptr) != End)
    {
        ptr = ptr->Child();
        cout <<"Step "<< ++step<<": ";
        ptr->Print();      
    }
    
    cout<<"Total Cost"<< step*5<<endl;
}

void TestPrinceOfPersia()
{
   cout<<"Enter Number of Levels"<<endl;
   cin>>levels;
   cout<<"Enter Number of Rows Per Level"<<endl;
   cin>>row;
   cout<<"Enter Number of Cols Per Level"<<endl;
   cin>>col;
   int numPillars=0;
   cout<<"Enter Number of Pillars"<<endl;
   cin>>numPillars;
   cout<<"Enter Positions of Pillars as: Level Row Col"<<endl;
   vector<Pos> Pillars;
   int pL=0;
   int pR=0;
   int pC=0;
   while(numPillars>0)
   {
       cin>>pL>>pR>>pC;
      // cout<<"You Entered "<<pL<<" "<<pR<<" "<<pC<<endl;
       Pos pp(pL,pR,pC,MAX);
       Pillars.push_back(pp);
       numPillars--;
   }
   
   int prL,prR,prC;
   int prsL,prsR,prsC;
   cout<<"Enter position of Prince"<<endl;
   cin>>prL>>prR>>prC; // prL = levels;
   Pos Prince(prL,prR,prC,0);
   cout<<"Enter position of Princess"<<endl;
   cin>>prsL>>prsR>>prsC; //prsL = 1;
   Pos Princess(prsL,prsR,prsC,MAX);
   
   ShortestPath(levels,row,col,Pillars,Prince,Princess);
   
}

int main()
{
    TestPrinceOfPersia();
}

/*
3
3
3

3 2 1
3 2 2
2 1 1
2 1 2
2 1 3
2 2 3
2 3 2
2 3 3
1 1 1
1 1 2
1 1 3
1 2 1
1 3 1
0 0 0

3 1 1
1 3 3
 */