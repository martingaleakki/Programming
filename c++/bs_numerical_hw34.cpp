#include <iostream>
#include <cmath>
using namespace std;

#define r .05


//int n=10000;
int n=20000;
double xn=600;
double dx= xn/(double)n;
double x0=0;

double T=0.75;
//long  m=ceil(T*n*n*(1.04*.25)*(1.04*.25)/(30));
int m = 4000;
double dt=T/(double)m;


double rho = dt/(dx*dx);

double bdy(double x,double t)
{ 
return max(x-100,0.0);	
}


double a_j_1(double s,double t,double rho)
{
	return r*s*dt/4 - (.25+(1-t)*s/1000)*(.25+(1-t)*s/1000)*s*s*rho/4;
}


double b_j_1(double s,double t,double rho)
{
	return r*dt/2 + 1+(.25+(1-t)*s/1000)*(.25+(1-t)*s/1000)*s*s*rho/2;
}


double c_j_1(double s,double t,double rho)
{
	return - r*s*dt/4 - (.25+(1-t)*s/1000)*(.25+(1-t)*s/1000)*s*s*rho/4;
}

double a_j(double s,double t,double rho)
{
	return -r*s*dt/4 + (.25+(1-t)*s/1000)*(.25+(1-t)*s/1000)*s*s*rho/4;
}


double b_j(double s,double t,double rho)
{
	return -r*dt/2 + 1-(.25+(1-t)*s/1000)*(.25+(1-t)*s/1000)*s*s*rho/2;
}


double c_j(double s,double t,double rho)
{
	return r*s*dt/4 +(.25+(1-t)*s/1000)*(.25+(1-t)*s/1000)*s*s*rho/4;
}


double crank_nicolson()
{





double u[n];

double bp[n];
double f[n];

double s;
double t;


t=0;

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
		t= (j)*dt;
		
		for(int i=0;i<n;i++)
		{	
			s=x0+i*dx;
			if(i==0) f[i] = b_j(i*dx,t,rho)*u[i] + c_j((i+1)*dx,t,rho)*u[i+1];
			else if(i==n-1) f[i] = a_j((i-1)*dx,t,rho)*u[i-1] + b_j(i*dx,t,rho)*u[i];
			else f[i] = a_j((i-1)*dx,t,rho)*u[i-1] + b_j(i*dx,t,rho)*u[i] + c_j((i+1)*dx,t,rho)*u[i+1];	
			
			if(i==0) bp[i]=b_j_1(i*dx,t-dt,rho);
			else bp[i] = b_j_1(i*dx,t-dt,rho) -a_j_1(i*dx,t-dt,rho)*c_j_1((i-1)*dx,t-dt,rho)/bp[i-1];
		}
		
		for(int i=1;i<n;i++)
		{
				
			f[i] =f[i] - a_j_1((i)*dx,t-dt,rho)*f[i-1]/bp[i-1]; 	
		}
		
		
		for(int i=n-1;i>=0;i--)
		{
			
			if(i==n-1) u[i]=f[i]/bp[i];
			else u[i]=(f[i]-c_j_1(i*dx,t-dt,rho)*u[i+1])/bp[i]	;			
		}
		
		
}

return u[(int)ceil(100/dx)];

}

int main()
{

cout<<"Crank Nicolson Method"<<endl;
cout<<m<<endl;
cout<<crank_nicolson()<<endl;

return 0;

}