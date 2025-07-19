
#include <stdio.h>
#include <stdlib.h>
int main()
{
//    int Max[10][10], need[10][10], allocation[10][10], available[10], completed[10], safeSequence[10];
//    int noofprocess, resources, i, j, process, count;
//    count = 0;
//
//    printf("Enter the no of processes : ");
//    scanf("%d", &noofprocess);
//
//    for(i = 0; i< noofprocess; i++)
//        completed[i] = 0;               //  flag whether the process completed or not
//
//    printf("\n\nEnter the no of resources : ");
//    scanf("%d", &resources);
//
//    printf("\n\nEnter the Max Matrix for each process : ");
//    for(i = 0; i < noofprocess; i++)
//    {
//        printf("\nFor process %d : ", i + 1);
//        for(j = 0; j < resources; j++)
//            scanf("%d", &Max[i][j]);
//    }
//
//    printf("\n\nEnter the allocation for each process : ");
//    for(i = 0; i < noofprocess; i++)
//    {
//        printf("\nFor process %d : ",i + 1);
//        for(j = 0; j < resources; j++)
//            scanf("%d", &allocation[i][j]);
//    }
//
//    printf("\n\nEnter the Current Available Resources with OS : ");
//    for(i = 0; i < resources; i++)
//        scanf("%d", &available[i]);
//
//    for(i = 0; i < noofprocess; i++)
//        for(j = 0; j < resources; j++)
//            need[i][j] = Max[i][j] - allocation[i][j];
//
//        do
//        {
//            printf("\nMax matrix:\tAllocation matrix:\n");
//
//            for(i = 0; i < noofprocess; i++)
//            {
//                for( j = 0; j < resources; j++)
//                    printf("%d ", Max[i][j]);
//
//                printf("\t\t");
//
//                for( j = 0; j < resources; j++)
//                    printf("%d ", allocation[i][j]);
//
//                printf("\n");
//            }
//
//            process = -1;           // For Each loop eligible process variable set = -1
//
//            for(i = 0; i < noofprocess; i++)
//            {
//                if(completed[i] == 0)   //if not completed
//                {
//                    process = i ;       // Process Value updated
//                    for(j = 0; j < resources; j++)
//                    {
//                        if(available[j] <= need[i][j])       // for each Resource of need matrix availability checked
//                        {
//                            process = -1; //  if one of resource is having higher value then RESET default value
//                            break;
//                        }
//                    }
//                }
//                if(process != -1)
//                    break;
//            }
//
//            if(process != -1)
//            {
//                printf("\nProcess %d runs to completion!", process + 1);
//                safeSequence[count] = process + 1;
//                count++;                            // increment count of completed process
//                for(j = 0; j < resources; j++)
//                {
//                    available[j] += allocation[process][j];
//                    allocation[process][j] = 0;         // allocation turned to zero
//                    Max[process][j] = 0;
//                    completed[process] = 1;             // mark completed process
//                }
//            }
//        }
//        while(count != noofprocess && process != -1);
//
//        if(count == noofprocess)
//        {
//            printf("\nThe system is in a safe state!!\n");
//            printf("Safe Sequence : < ");
//            for( i = 0; i < noofprocess; i++)
//                printf("%d ", safeSequence[i]);
//            printf(">\n");
//        }
//        else
//            printf("\nThe system is in an unsafe state!!");
	int n=4;
	int r=3;
	
	int max[4][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
	int alloc[4][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
	int need[4][3];
	int avail[3]={0,0,0};
	int index=0,ans[n],tmp[4]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
//			printf("exe\n");
			if(tmp[i]==0)
			{
//				printf("exe\n");
			int flag=1;
			for(int j=0;j<r;j++)
			{
//				printf("exe\n");
				if(need[i][j]>avail[j])
				{
					flag=0;
					break;
//					printf("exe\n");
				}
			}
			
			if(flag)
				{
					
					for(int y=0;y<r;y++)
					avail[y]+=alloc[i][y];
//					printf("exe\n");
					ans[index++]=i;
					tmp[i]=1;
				}
			}
			
		}

}
for(int i=0;i<n;i++)
printf("%d ",ans[i]);
return 0;
}
