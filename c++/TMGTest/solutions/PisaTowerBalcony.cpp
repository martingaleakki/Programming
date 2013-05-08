#include <vector>
#include <iostream>
using namespace std;

class PointP
{
 private:
        double x,y,z;
 public:
     PointP(double x,double y,double z)
     {
        this->x=x;
        this->y=y;
        this->z=z;
     }  
     double X()const {return x;}
     double Y() const {return y;}
     double Z() const{return z;}

};

class VectorV
{
 private:
        double x,y,z;
 public:
     VectorV(double x,double y,double z)
     {
         this->x=x;
         this->y=y;
         this->z=z;
     }
     
     VectorV(PointP p1,PointP p2)
     {
        this->x=p1.X() -p2.X();
        this->y=p1.Y() - p2.Y();
        this->z=p1.Z() - p2.Z();
     }  
     double X()const {return x;}
     double Y() const {return y;}
     double Z() const{return z;}
     double DotProduct(VectorV P) { return x*P.X() + y*P.Y()+z*P.Z(); }
     VectorV CrossProduct(VectorV P){
         double x1 = y*P.Z() - z*P.Y();
         double y1 = z*P.X() - x*P.Z();
         double z1 = x*P.Y() - y*P.X();
         return VectorV(x1,y1,z1);
     }
     VectorV operator-(const  VectorV& p) const
     {
         return VectorV(x-p.X(),y-p.Y(),z-p.Z());         
     }
     
     bool operator==(const VectorV& p) const
     {
         return (x==p.X())&&(y==p.Y())&&(z==p.Z());
     }
     void Print()
     {
         cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
     }
};

VectorV NormalVector(VectorV A,VectorV B)
{    
    return A.CrossProduct(B);
}

bool IsPerpendicular(PointP wall1,PointP wall2,PointP wall3, PointP beam1,PointP beam2,PointP beam3)
{
    VectorV WAB(wall1,wall2);
    VectorV WAC(wall1,wall3);
    VectorV BAB(beam1,beam2);
    VectorV BAC(beam1,beam3);
    VectorV normVecWall = NormalVector(WAB,WAC);
    VectorV normVecBeam = NormalVector(BAB,BAC);
    
    double dp = normVecWall.DotProduct(normVecBeam);
    
    return dp == 0;
}

void TestPisaTowerBalcony()
{
    int x,y,z;
    cout<<"Enter Coordinates of Point 1 on Wall"<<endl;
    cin>>x>>y>>z;
    PointP w1(x,y,z);
    cout<<"Enter Coordinates of Point 2 on Wall"<<endl;
    cin>>x>>y>>z;
    PointP w2(x,y,z);
    cout<<"Enter Coordinates of Point 3 on Wall"<<endl;
    cin>>x>>y>>z;
    PointP w3(x,y,z);
    
    cout<<"Enter Coordinates of Point 1 on Beam"<<endl;
    cin>>x>>y>>z;
    PointP b1(x,y,z);
    cout<<"Enter Coordinates of Point 2 on Beam"<<endl;
    cin>>x>>y>>z;
    PointP b2(x,y,z);
    cout<<"Enter Coordinates of Point 3 on Beam"<<endl;
    cin>>x>>y>>z;
    PointP b3(x,y,z);
    cout <<"Perpendicular ?" << (IsPerpendicular(w1,w2,w3,b1,b2,b3)?"Yes":"No")<<endl;
    
}

void TestNormalVector()
{
    int x,y,z;
    cout<<"Enter Coordinates of Point 1 on Wall"<<endl;
    cin>>x>>y>>z;
    PointP w1(x,y,z);
    cout<<"Enter Coordinates of Point 2 on Wall"<<endl;
    cin>>x>>y>>z;
    PointP w2(x,y,z);
    cout<<"Enter Coordinates of Point 3 on Wall"<<endl;
    cin>>x>>y>>z;
    PointP w3(x,y,z);
    VectorV WAB(w1,w2);
    VectorV WAC(w1,w3);
    VectorV n = NormalVector(WAB,WAC);
    n.Print();
}
int main()
{
    //TestNormalVector();
    TestPisaTowerBalcony();
    return 0;
}