#include <iostream>
#include <cmath>
using namespace std;
#define pi 3.14

double bdy(double x,double t)
{
	if(x==pi || x==-pi) return 0;
	else return (1- abs(x/pi));
	
}

double explicit_method()
{
int n=1000;

double T=0.1;

int m=ceil(2*T*n*n/(4*pi*pi));

double dt=T/m;
double dx= 2*pi/n;
double x0=-pi;
double xn=pi;

double rho = dt/(dx*dx);

double a= rho*(1+.5*dx);
double b= 1-2*rho;
double c= rho*(1-.5*dx);

double u[2][1000];

//initialize the boundary 
for (int i = 0;i<n;i++) u[1][i] = bdy(x0+i*dx,T); 

int j1 = 0;
int j2=1;
int temp;
for (int j=m-2;j>=0;j--)
{
		
		for(int i=0;i<n;i++)
		{
		
			if(i==0 || i==n-1) u[j1][i]=0;
			else u[j1][i]=a*u[j2][i-1] + b*u[j2][i] + c*u[j2][i+1];			
		}
		temp=j1;
		j1=j2;
		j2=temp;
}

return u[j2][500];
}

int main()
{

cout<<"Explicit Method"<<endl;
cout<<explicit_method()<<endl;

return 0;
}