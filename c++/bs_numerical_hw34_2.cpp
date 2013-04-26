#include <iostream>
#include <cmath>
using namespace std;

#define r .05


//int n=10000;
int n=4000;
double xn=400;
double dx= xn/(double)n;
double x0=0;

double T=0.75;
long  m=ceil(T*n*n*(1.3*.25)*(1.3*.25)/(30));

double dt=T/(double)m;

double bdy(double x,double t)
{ 
return max(x-100,0.0);	
}


inline double a_j_1(double s,double t)
{
	return (r*s/(4*dx) - ((.25+(1-t)*s/1000)*(.25+(1-t)*s/1000)*s*s)/(4*dx*dx));
}


inline double b_j_1(double s,double t)
{
	return (r/2 + 1/dt +(.25+(1-t)*s/1000)*(.25+(1-t)*s/1000)*s*s/(2*dx*dx));
}


inline double c_j_1(double s,double t)
{
	return (- r*s/(4*dx) - ((.25+(1-t)*s/1000)*(.25+(1-t)*s/1000)*s*s)/(4*dx*dx));
}

inline double a_j(double s,double t)
{
	return (-r*s/(4*dx) + ((.25+(1-t)*s/1000)*(.25+(1-t)*s/1000)*s*s)/(4*dx*dx));
}


inline double b_j(double s,double t)
{
	return (-r/2 + 1/dt-((.25+(1-t)*s/1000)*(.25+(1-t)*s/1000)*s*s)/(2*dx*dx));
}


inline double c_j(double s,double t)
{
	return (r*s/(4*dx) +((.25+(1-t)*s/1000)*(.25+(1-t)*s/1000)*s*s)/(4*dx*dx));
}


double crank_nicolson()
{
double u[n];

double bp[n];
double f[n];

double s;
double t;

double a,b,c;


//initialize the boundary 
for (int i = 0;i<n;i++) { u[i] = bdy(i*dx,T);}
/*
for(int i=0;i<n;i++)
{
	s=x0+i*dx;
	if(i==0) f[i] = b_j(i*dx,T,rho)*u[i] + c_j((i+1)*dx,T,rho)*u[i+1];
	else if(i==n-1) f[i] = a_j((i-1)*dx,T,rho)*u[i-1] + b_j(i*dx,T,rho)*u[i];
	else f[i] = a_j((i-1)*dx,T,rho)*u[i-1] + b_j(i*dx,T,rho)*u[i] + c_j((i+1)*dx,T,rho)*u[i+1];
	
	if(i==0) bp[i]=b_j_1(i*dx,T-dt,rho);
	else bp[i] = b_j_1(i*dx,T-dt,rho) -a_j_1(i*dx,T-dt,rho)*c_j_1((i-1)*dx,T-dt,rho)/bp[i-1];
}
*/


for (int j=m;j>=1;j--)
{
		
		//cout<<t<<endl;
		for(int i=0;i<n;i++)
		{	
			b = b_j(i*dx,j*dt);
			c= c_j(i*dx,j*dt);
			a = a_j(i*dx,j*dt)
			s=x0+i*dx;
			if(i==0) f[i] = b*u[i] + c*u[i+1];
			else if(i==n-1) f[i] = a*u[i-1] + b*u[i];
			else f[i] = a*u[i-1] + b*u[i] + c*u[i+1];	
			
			if(i==0) bp[i]=b_j_1(i*dx,(j-1)*dt);
			else bp[i] = b_j_1(i*dx,(j-1)*dt) -a_j_1(i*dx,(j-1)*dt)*c_j_1((i-1)*dx,(j-1)*dt)/bp[i-1];
		}
		
		for(int i=1;i<n;i++)
		{				
			f[i] =f[i] - a_j_1(i*dx,(j-1)*dt)*f[i-1]/bp[i-1]; 	
		}
		
		
		for(int i=n-1;i>=0;i--)
		{			
			if(i==n-1) u[i]=f[i]/bp[i];
			else u[i]=(f[i]-c_j_1(i*dx,(j-1)*dt)*u[i+1])/bp[i]	;			
			
		}
		u[0]=0;
		u[n-1]=bdy((n-1)*dx,t);
		
}
 int id =(int)ceil(100/dx);
 cout<<id<<endl;
return u[id];

}

int main()
{

cout<<"Crank Nicolson Method"<<endl;
cout<<crank_nicolson()<<endl;

return 0;

}