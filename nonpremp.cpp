#include<iostream>
using namespace std;
class FCFS
{
	public:
	void calct(int ct[],int at[],int bt[],int n)
	{
		ct[0]=bt[0];
		int sum=ct[0];
		for(int i=1;i<n;i++)
		{
			ct[i]=ct[i-1]+bt[i];
			sum+=ct[i];
		}
		cout<<sum/3<<endl;
	}
	void caltat(int tat[],int ct[],int at[],int n)
	{
		for(int i=0;i<n;i++)
		tat[i]+=(ct[i]-at[i]);
	}
	void calwt(int tat[],int wt[],int bt[],int n)
	{
		for(int i=0;i<n;i++)
		wt[i]=tat[i]-bt[i];
	}
	int cal(int at[3],int bt[3],int wt[3],int ct[3],int tat[3],int n)
	{
		calct(ct,at,bt,n);
		caltat(tat,ct,at,n);
		calwt(tat,wt,bt,n);
		int sum=0;
		for(int i=0;i<n;i++)
		sum+=wt[i];
		for(int i=0;i<n;i++)
		cout<<wt[i]<<endl;
		cout<<"Avg wt - "<<(sum/n)<<endl;
		return 0;
	}
};
class SJF
{
	private:
		void sort(int at[],int bt[],int n)
		{
			int j=0;
			for(int i=0;i<n;i++)
			{
				int min=i;
				for(j=i+1;j<n;j++)
				{
					if(bt[min]>bt[j])
					min=j;
				}
				swap(bt[min],bt[i]);
				swap(at[min],at[i]);
    }
			
			for(int i=0;i<n;i++)
			{
				cout<<bt[i]<<" "<<at[i]<<endl;
			}
		}
	public:
	void calct(int ct[],int at[],int bt[],int n)
	{
		for(int i=0;i<n;i++)
			{
				cout<<bt[i]<<" "<<at[i]<<" ";
			}
			cout<<endl;
		ct[0]=bt[0];
		int sum=ct[0];
		for(int i=1;i<n;i++)
		{
			ct[i]=ct[i-1]+bt[i];
			sum+=ct[i];
		}
		cout<<ct[3]<<"fk"<<endl;
	}
	void caltat(int tat[],int ct[],int at[],int n)
	{
		for(int i=0;i<n;i++)
		tat[i]=(ct[i]-at[i]);
	}
	void calwt(int tat[],int wt[],int bt[],int n)
	{
		for(int i=0;i<n;i++)
		wt[i]=tat[i]-bt[i];
	}
	int cal(int at[],int bt[],int wt[],int ct[],int tat[],int n)
	{
		sort(at,bt,n);
		calct(ct,at,bt,n);
		caltat(tat,ct,at,n);
		calwt(tat,wt,bt,n);
		int sum=0;
		for(int i=0;i<n;i++)
		sum+=wt[i];
		cout<<"wt - \n";
		for(int i=0;i<n;i++)
		cout<<wt[i]<<" ";
		cout<<"Avg wt - "<<(sum/n)<<endl;
		return 0;
	}
};
int main()
{
	FCFS obj;
	SJF obj2;
	int at[]={0,0,0,0};
//	int bt[]={24,3,4};
	int ct[]={0};
	int tat[]={0};
	int wt[]={0};
	int bt[]={21,3,6,2};
//	obj.cal(at,bt,wt,ct,tat,3);
	obj2.cal(at,bt,wt,ct,tat,4);
	return 0;
}
