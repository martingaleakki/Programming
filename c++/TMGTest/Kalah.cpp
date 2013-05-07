#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

//Player 1: Houses - 1,2,3,4,5,6 Store - 7
//Computer: Houses - 8,9,10,11,12 Store - 0

//Houses and Stores are both Boxes
//Stores are always initialized with 0. Houses may or may not be.
class Box {
private:
    int myNum;
    int countSeeds;
    public:
        
        Box(int _myNum,int _countSeeds)
        {
            myNum=_myNum;
            countSeeds=_countSeeds;
        }
        int GetMyNum() {return myNum;}
        int GetCountSeeds(){return countSeeds;}
        void AddSeed() { countSeeds+=1;}
        void AddSeed(int s){countSeeds+=s;}
        void RemoveSeeds() { countSeeds=0;}
        bool IsEmpty() { return countSeeds==0;}        
};


class Kalah{
private:
    vector<Box> houses;
    const static int SeedsPerPlayer=30;
    const static int ComputerStore=0;
    const static int PlayerStore=7;
    void Init()
    {
        int n=7;
        srand(time(0));
        vector<int> seeds = GetSeeds(n-1);
        for(int i=0;i<n;i++)
        {            
            Box b(i,(i==0? 0:seeds[i-1]));
            houses.push_back(b);
        }
        
        seeds = GetSeeds(n-1);
        for(int i=0;i<n;i++)
        {            
            Box b(n+i,(i==0?0:seeds[i-1]));
            houses.push_back(b);
        }
    }
    
    vector<int> GetSeeds(int n)
    {
        vector<int> seeds;
        vector<int> U = Uniform(1,10,n-1);
        int sum=0;
        for(int i=0;i<U.size();i++) sum+=U[i];
        int sumSeed=0;
        for(int i=0;i<U.size();i++)
        {
            double u= 1.0*U[i];
            int seed= floor(SeedsPerPlayer * u/sum);
            sumSeed+=seed;
            seeds.push_back(seed);
        }
        seeds.push_back(SeedsPerPlayer>sumSeed ? SeedsPerPlayer - sumSeed: 0);
        return seeds;
    }
    
    vector<int> Uniform(int a,int b,int n)
    {
        vector<int> U;
        
        for(int i=0;i<n;i++){
           int r = a+ (b-a)*(rand() / double(RAND_MAX));
           U.push_back(r);
        }
        return U;
    }
    
    bool IsGameOver()
    {
        //return true;
        bool gameOver = false;
        //When one player no longer has any seeds in any of his/her houses, the game ends. 
        int computerSeedsInHouses=0;
        int playerSeedsInHouse=0;
                 
        for(int i=1;i<=6;i++) { playerSeedsInHouse+=houses[i].GetCountSeeds();}
        for(int i=8;i<=13;i++) { computerSeedsInHouses+=houses[i].GetCountSeeds();} 
        
        if(playerSeedsInHouse==0 || computerSeedsInHouses==0) gameOver=true;
        
        //The other player moves all remaining seeds to his/her store, and 
        //the player with the most seeds in his/her store wins.
        if(gameOver)
        {
            
            if((playerSeedsInHouse+houses[PlayerStore].GetCountSeeds()) > 
                    (computerSeedsInHouses+houses[ComputerStore].GetCountSeeds()))
            {
                cout<<"You Won!"<<endl;
            }
            else if  ((playerSeedsInHouse+houses[PlayerStore].GetCountSeeds()) < 
                    (computerSeedsInHouses+houses[ComputerStore].GetCountSeeds()))cout<<"Computer Won"<<endl;
            else cout<<"Draw"<<endl;
            
            cout<<"Computer Seeds: "<<computerSeedsInHouses+houses[ComputerStore].GetCountSeeds()<<endl;
            cout<<"Player Seeds: "<<playerSeedsInHouse+houses[PlayerStore].GetCountSeeds()<<endl;
            exit(EXIT_SUCCESS);
        }
        
        return gameOver;
    }
     bool IsEmptyHouse(int h)
    {
        return houses[h].IsEmpty();
    }
    int GetOppositeHouse(int h)
    {
        return 14-h;
    }
    bool IsComputer(int h)
    {
     return h>=8 && h <= 13;    
    }    
    int Move(int startHouse, bool sim)
    {
        // Players take turns sowing their seeds. On a turn, the player removes all seeds from one 
        //of the houses under his/her control. Moving counter-clockwise, the player drops one seed
        //in each house in turn, including the player's own store but not his/her opponent's. 
        
        
        vector<Box>::iterator itr = houses.begin() + startHouse;
        int seedsToDistribute = itr->GetCountSeeds();
        if(!sim)itr->RemoveSeeds();        
             
        
        while(seedsToDistribute>0)
          {
              itr++;
              if(itr==houses.end()) itr =houses.begin();
              if(itr->GetMyNum()==(IsComputer(startHouse)?7:0))itr++;
              if(!sim)itr->AddSeed();              
              seedsToDistribute--;              
         }
         
        return itr->GetMyNum();        
    }
     
    bool IsExtraTurn(int startHouse,int endHouse)
    {
        //If the last sown seed lands in the player's store, the player gets an additional move. 
        //There is no limit on the number of moves a player can make in his/her turn.
        if(IsComputer(startHouse) && endHouse == ComputerStore)
        {
            return true;
        }
        else if (!IsComputer(startHouse) && endHouse == PlayerStore)
        {
            return true;
        }
        return false;
    } 
    
    bool IsCapture(int startHouse, int endHouse, bool sim)
     {
            //If the last sown seed lands in an empty house owned by the player, 
             //and the opposite house contains seeds, 
             //both the last seed and the opposite seeds are captured and placed into the player's store.

            if(IsComputer(startHouse) && IsComputer(endHouse) && houses[endHouse].GetCountSeeds()==1)
            {
               
                if(!sim){
                        houses[ComputerStore].AddSeed(houses[endHouse].GetCountSeeds()+ houses[GetOppositeHouse(endHouse)].GetCountSeeds() );
                        houses[endHouse].RemoveSeeds();
                        houses[GetOppositeHouse(endHouse)].RemoveSeeds();
                }
                return true;
            }
            else if(!IsComputer(startHouse) && !IsComputer(endHouse) && houses[endHouse].GetCountSeeds()==1)
            {
                //sim here is redundant now but may be in the future 
                //if the computer wants to look ahead at opponent moves sim can be used
                if(!sim){
                        houses[PlayerStore].AddSeed(houses[endHouse].GetCountSeeds()+ houses[GetOppositeHouse(endHouse)].GetCountSeeds() );       
                        houses[endHouse].RemoveSeeds();
                        houses[GetOppositeHouse(endHouse)].RemoveSeeds();
                }
                return true;
            }  
            return false;
    }
     
    void DoPlayerTurn ()
    {
        DisplayBoard();
        cout<<"Your turn:"<<endl;
        int h1;
        cout<<" Pick a house from [1,2,3,4,5,6]"<<endl;
        cin>>h1;
        if(!(h1>=1 && h1<=6)){
            cout<<"Invalid House Number"<<endl;
            DoPlayerTurn();
        }
        else if(houses[h1].IsEmpty())
        {
            cout<<"Invalid Move !!! The house is already empty"<<endl;
            if(!IsGameOver()) DoPlayerTurn();
        }
        else
        {
           int h2 = Move(h1, false);
           if(!IsGameOver() && IsExtraTurn(h1,h2)) {cout<<"****You get an extra turn****"<<endl; DoPlayerTurn();}
           else if(IsCapture(h1, h2, false)){cout<<"Oh no! You captured seeds from me"<<endl;}
        }        
    }
    
    void DoComputerTurn()
    {
        cout<<"My turn:"<<endl;
        DisplayBoard();
        int h1 = GetBestMoveForComputer();
        cout<<"I pick "<<h1-7<<endl;
        int h2 = Move(h1, false);
        if(!IsGameOver() && IsExtraTurn(h1,h2)) {cout<<"*****I get an extra turn****"<<endl; DoComputerTurn();}
        else if(IsCapture(h1, h2, false)){cout<<"Oh yes! I captured seeds from you:"<<endl;}
    }
    
    void DisplayBoard()
    {
        //Display Computer
        cout<<"House#(Seeds) :"<<endl;
         
        cout<<"Computer:"<<endl;
        cout<<"S"<<"("<<houses[ComputerStore].GetCountSeeds()<<") ";
        for(int i=6;i>=1;i--){cout<<i<<"("<<houses[7+i].GetCountSeeds()<<") ";}
        
        cout<<endl<<"You:"<<endl;
        cout<<"     ";
        for(int i=1;i<=6;i++){cout<<i<<"("<<houses[i].GetCountSeeds()<<") ";}
         cout<<"S"<<"("<<houses[PlayerStore].GetCountSeeds()<<")"<<endl<<endl;
    }     
    
    int GetUtility(int startHouse)
    {
        //Compute the utility to the computer for this house
        //This is a very simple utility function and can be improved a lot if desired :)
        if(houses[startHouse].IsEmpty()) return -1;
        int sim=true;
        int endHouse = Move(startHouse,sim);
        int seedsRetained = (houses[startHouse].GetCountSeeds() > (14 - startHouse))? 14-startHouse : houses[startHouse].GetCountSeeds();
        int seedsCaptured = 0;
        if(IsCapture(startHouse, endHouse, sim)){
            seedsCaptured = houses[endHouse].GetCountSeeds(); 
        }        
        int utility = seedsRetained+ 100*seedsCaptured + 100*IsExtraTurn(startHouse,endHouse);
        return utility;
    }
    
    int GetBestMoveForComputer()
    {
        //This will return the house number that
        //corresponds to the best move based on some conditions
        int bestHouse = -1;
        int bestHouseUtility = -1;
        for(int i=8;i<=13;i++)
        {
            if(bestHouseUtility < GetUtility(i) ) bestHouse=i;
        }        
        return bestHouse;
    }
    
    
public:    
    void Play()
    {
        cout<<"Welcome to the game Kalah"<<endl;
        cout<<"Read the instructions from Wikipedia"<<endl;
        //DisplayBoard();
        while(!IsGameOver())
        {
            //Players Turn            
            DoPlayerTurn();
            
            //Computers Turn
            if(!IsGameOver()){DoComputerTurn();}
        }        
    }   
    
    Kalah()
    {        
        Init();        
    }
};

//int main()
//{    
//    Kalah game;
//    game.Play();
//}