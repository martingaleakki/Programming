#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define r .04


//int n=10000;
int n=10000;
double xn=200;
double dx= xn/(double)n;
double x0=0;
double Strike = 50;

double T=0.5;
double sig=0.3;
long  m=10000;//ceil(T*n*n*(sig)*(sig)/(30));

double dt=T/(double)m;

double bdy(double x,double t)
{ 
return max(Strike-x,0.0);	
}


inline double a_j_1(double s,double t)
{
	return (r*s/(4*dx) - (sig*sig*s*s)/(4*dx*dx));
}


inline double b_j_1(double s,double t)
{
	return (r/2 + 1/dt +sig*sig*s*s/(2*dx*dx));
}


inline double c_j_1(double s,double t)
{
	return (- r*s/(4*dx) - (sig*sig*s*s)/(4*dx*dx));
}

inline double a_j(double s,double t)
{
	return (-r*s/(4*dx) + (sig*sig*s*s)/(4*dx*dx));
}


inline double b_j(double s,double t)
{
	return (-r/2 + 1/dt-(sig*sig*s*s)/(2*dx*dx));
}


inline double c_j(double s,double t)
{
	return (r*s/(4*dx) +(sig*sig*s*s)/(4*dx*dx));
}


double crank_nicolson()
{
double u[n];

double bp[n];
double f[n];

double s;
double t;

double a,b,c;
double last=0;
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
double bdy_v;
vector<double> u_s;
vector<double> st;
bool fbdy = false;
for (int j=m;j>=1;j--)
{
		
		//cout<<t<<endl;
		for(int i=0;i<n;i++)
		{	
			s=x0+i*dx;
			b = b_j(i*dx,j*dt);
			c= c_j(i*dx,j*dt);
			a = a_j(i*dx,j*dt);
			
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
			bdy_v = bdy(i*dx,j*dt);
			if(!fbdy && u[i] < bdy_v)
			{
			double stock = i*dx;
				fbdy = true;
				if(last != stock){
				u_s.push_back( u[i]) ;
				st.push_back( stock);
				last = stock;
				}
			}
			u[i] = max(u[i],bdy_v);
			
		}
		fbdy = false;
		u[0]=0;
		u[n-1]=bdy((n-1)*dx,t);
		
		
		
}

double us_p,us_m;
for (int j=1;j<=st.size()-2;j++)
{

	us_p = (u_s[j+1] - u_s[j])/(st[j+1]-st[j]);
	us_m = (u_s[j] - u_s[j-1])/(st[j]-st[j-1]);	
	cout<<j<<"us "<<u_s[j]<<" s*= "<<st[j]<<" us_p = "<<us_p<<" us_m = "<<us_m<<" diff="<<(us_p-us_m)<<endl;
	
}


int id =(int)ceil(50/dx); 
return u[id];

}

int main()
{

cout<<"Crank Nicolson Method"<<endl;
cout<<crank_nicolson()<<endl;

return 0;

}