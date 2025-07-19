while(1)
{
	bool iscompleted=1;
	for(int i=0;i<n;i++)
	{
		if(rem_bt[i])
		{
			flag=0;
			if(rem_bt[i]>q)
			{
				rem_bt[i]-=q;
				time+=q;				
					}	
					else
					{
						time+=rem_bt[i];
						rem_bt[i]=0;
						ct[i]=time;
					}
		}
	}
	if(flag==1)break;
}