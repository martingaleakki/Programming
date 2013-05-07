#include <vector>
#include <iostream>
using namespace std;

class Point
{
 private:
        double x,y,z;
 public:
     Point(double x,double y,double z)
     {
        this->x=x;
        this->y=y;
        this->z=z;
     }  
     double X()const {return x;}
     double Y() const {return y;}
     double Z() const{return z;}
     double DotProduct(Point P) { return x*P.X() + y*P.Y()+z*P.Z(); }
     Point CrossProduct(Point P){
         double x1 = y*P.Z() - z*P.Y();
         double y1 = z*P.X() - x*P.Z();
         double z1 = x*P.Y() - y*P.X();
         return Point(x1,y1,z1);
     }
     Point operator-(const  Point& p) const
     {
         return Point(x-p.X(),y-p.Y(),z-p.Z());         
     }
     
     bool operator==(const Point& p) const
     {
         return (x==p.X())&&(y==p.Y())&&(z==p.Z());
     }
};

Point NormalVector(Point A,Point B, Point C)
{
    Point AB = A - B;
    Point AC = A - C;
    return AB.CrossProduct(AC);
}

bool IsPerpendicular(Point Wall1,Point Wall2,Point Wall3, Point Beam1,Point Beam2,Point Beam3)
{
    
    Point normVecWall = NormalVector(Wall1,Wall2,Wall3);
    Point normVecBeam = NormalVector(Beam1,Beam2,Beam3);
    
    double dp = normVecWall.DotProduct(normVecBeam);
    
    return dp == 0;
}

//int main()
//{
//    return 0;
//}