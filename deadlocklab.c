#include<stdio.h>
int main()
{
	int noofprocess,noofresources;
	cin>>noofprocess>>noofresources;
	int n=noofprocess,r=noofresources;
	int max[n][r],allocated[n][r],need[n][r];
	int available[r];
	int flag[n];
	int ans[n];
	int index=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-allocated[i][j];
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			if(flag[i]==0)
			{
				bool tmp=1;
				for(int j=0;j<r;j++)
				{
					if(need[i][j]>available[j])
					{
						tmp=0;
						break;
					}
				}
				if(tmp==1)
				{
					ans[index++]=i;
					for(int y=0;y<r;y++)
					{
						available[y]+=(allocated[i][y]);
					}
					flag[i]=1;
				}
			}	
		}
	}
}
