#include<iostream>
using namespace std;
class FCFS
{
	int *bt,*tat,*wt,*at,*ct;
	void calwt(int *&tat,int *&wt,int n,int *&bt,int &avgwt)
{
	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]+=(tat[i]-bt[i]);
		avgwt+=(wt[i]);
	}
//	for(int i=0;i<n;i++)
//	cout<<wt[i]<<endl;
	avgwt/=n;
}
void calct(int *&bt,int *&at,int *ct,int n,int &avgct)
{
	ct[0]=bt[0];
	for(int i=1;i<n;i++)
	{
		ct[i]=ct[i-1]+bt[i];
	}
//	for(int i=0;i<n;i++)
//	cout<<ct[i]<<endl;
	avgct/=n;
}
void TAT(int *&ct,int *&t,int *&at,int &avgtat,int n)
{
	for(int i=0;i<n;i++)
	{
		t[i]+=(ct[i]-at[i]);
		avgtat+=t[i];
	}
	avgtat/=n;
}
public:
	FCFS()
	{
	bt=new int[100]{0};
	tat=new int[100]{0};
	wt=new int[100]{0};
	at=new int[100]{0};
	ct=new int[100]{0};
	}

void func()
{
	int n,avgwt=0,avgtat=0,avgct=0;
	cout<<"enter total number of process(max 100) - ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter burst time of process "<<i<<'-';
		cin>>bt[i];
		cout<<endl;
	}
	calct(bt,at,ct,n,avgct);
	TAT(ct,tat,at,avgtat,n);
	calwt(tat,wt,n,bt,avgwt);
	cout<<"avg wt - "<<avgwt<<endl<<"avg tat - "<<avgtat<<endl;
}	
~FCFS()
{
	delete[] *bt,*tat,*wt,*at,*ct;
}
};

class SJF
{
	int *bt,*tat,*wt,*at,*ct;
	public:
	SJF()
	{
	bt=new int[100]{0};
	tat=new int[100]{0};
	wt=new int[100]{0};
	at=new int[100]{0};
	ct=new int[100]{0};
	}
	
		
};
int main()
{

	FCFS obj;
	obj.func();
	
	return 0;
}


