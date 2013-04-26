#include <iostream>
#include <cmath>
using namespace std;
#define pi 3.14

double bdy(double x,double t)
{
	return 1-abs(x/pi);
	
}


double crank_nicolson()
{

int n=1000;

double T=0.1;

int m=ceil(2*T*n*n/(4*pi*pi));

double dt=T/m;
double dx= 2*pi/n;
double x0=-pi;
double xn=pi;

double rho = dt/(dx*dx);

double a_j_1= -rho*(1+.5*dx);
double b_j_1= 2*(1+rho);
double c_j_1= -rho*(1-.5*dx);


double a_j= rho*(1+.5*dx);
double b_j= 2*(1-rho);
double c_j= rho*(1-.5*dx);


double u[1000];

double bp[1000];
double f[1000];


//initialize the boundary 
for (int i = 0;i<n;i++) u[i] = bdy(x0+i*dx,T); 
for(int i=0;i<n;i++)
{
	if(i==0) f[i] = b_j*u[i] + c_j*u[i+1];
	else if(i==n-1) f[i] = a_j*u[i-1] + b_j*u[i];
	else f[i] = a_j*u[i-1] + b_j*u[i] + c_j*u[i+1];
	
	if(i==0) bp[i]=b_j_1;
	else bp[i] = b_j_1 -a_j_1*c_j_1/bp[i-1];
}



for (int j=m-2;j>=0;j--)
{
		for(int i=1;i<n;i++)
		{
			f[i] =f[i] - a_j_1*f[i-1]/bp[i-1]; 			 
		}
		
		
		for(int i=n-1;i>=0;i--)
		{
		
			if(i==n-1) u[i]=f[i]/bp[i];
			else u[i]=(f[i]-c_j_1*u[i+1])/bp[i]	;			
		}
		
		for(int i=0;i<n;i++)
		{
			if(i==0) f[i] = b_j*u[i] + c_j*u[i+1];
			else if(i==n-1) f[i] = a_j*u[i-1] + b_j*u[i];
			else f[i] = a_j*u[i-1] + b_j*u[i] + c_j*u[i+1];			
		}
		
}

return u[500];


}

int main()
{

cout<<"Crank Nicolson Method"<<endl;
cout<<crank_nicolson()<<endl;

return 0;


}