#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,i,qt,count=0,tmp,sq=0;
    cin>>n;
    int bt[10],wt[10],tat[10],rem_bt[10],at[10];
    
    for(int i=0;i<n;i++)
    cin>>bt[i];
    
    for(int i=0;i<n;i++)
    rem_bt[i]=bt[i];
    
    cin>>qt;
    while(1)
    {
    	for(int i=0;i<n;i++)
    	{
    		int tmp=qt;
    		if(rem_bt[i]==0){
			count++;continue;}
    		if(rem_bt[i]>qt)
    		{rem_bt[i]-=qt;
			}
			else
			{
				if(rem_bt[i]>=0)
				{
					tmp=rem_bt[i];
					rem_bt[i]=0;
				}
			
			}
		sq=sq+tmp;
			tat[i]=sq;
			
		}
			
	if(count==n)break;
	}
	int sum=0;
		for(int i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
		cout<<tat[i]<<" "<<wt[i]<<endl;
		}
		for(int i=0;i<n;i++)
		sum=sum+wt[i];
    cout<<endl<<((float)sum/n);
    return 0;
}
