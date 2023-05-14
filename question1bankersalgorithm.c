#include<stdio.h>
int main()
{
    int n,m,i,j,max[4][3],allocation[4][3],need[4][3],complete=0,available[3],safe[4],iter=0;
    int status[4];
    printf("\n Enter the number of process");
    scanf("%d",&n);
    printf("\n Enter the number of resources");
    scanf("%d",&m);

    //set the status of the process
    for(i=0;i<n;i++)
    {
        status[i]=0;
        safe[i]=0;
    }


    //get the max matrix
    for(i=0;i<n;i++)
    {
        printf("\n Enter the resources for the %d process",i);
        for(j=0;j<m;j++)
        {
            printf("\n Enter the %d th resources for the %d process",j,i);
            scanf("%d",&max[i][j]);
        }
    }

    //get the allocation matrix
    for(i=0;i<n;i++)
    {
        printf("\n Enter the resources for the %d process",i);
        for(j=0;j<m;j++)
        {
            printf("\n Enter the %d th resources for the %d process",j,i);
            scanf("%d",&allocation[i][j]);
        }
    }
    //get the available matrix
    for(i=0;i<m;i++)
    {
        printf("\n Enter the available resources for the %d ",i);
        scanf("%d",&available[i]);
    }

    // compute the need matrix

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }

    //display the matrix
    printf("\n The max matrix");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
        {
            printf("\t %d",max[i][j]);
        }
    }

    printf("\n The resource allocation matrix");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
        {
            printf("\t %d",allocation[i][j]);
        }
    }

    printf("\n The need matrix");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
        {
            printf("\t %d",need[i][j]);
        }
    }

    i=0;
    complete=0;
    iter=0;
   while(complete<n&&iter<2)
   {
       if(status[i]==0 && need[i][0]<=available[0] && need[i][1]<=available[1]&& need[i][2]<=available[2])
       {
           available[0]+=allocation[i][0];
           available[1]+=allocation[i][1];
           available[2]+=allocation[i][2];
           status[i]=1;
           safe[complete]=i;
           complete++;
       }
       if(i<n)
        i++;
       else
       {
         i=0;
         iter++;
       }

   }

  if(complete < n-1)
   {
      printf("\n The system is in unsafe state");
   }
   else
   {
      printf("\n The safe sequence is ");
      for(i=0;i<n;i++)
      {
          printf("%d -> ",safe[i]);
      }

   printf("\n the total no of resource available is ");
   for(i=0;i<m;i++)
    {
        printf("\n the available resources for the %d ",available[i]);
    }
   }
}
