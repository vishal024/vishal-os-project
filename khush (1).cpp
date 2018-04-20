#include<stdio.h>
int sum(int a[],int n)
{
	int sum1=0;
	for(int i=0;i<n;i++)
	sum1+=a[i];

	return(sum1);
}
void waiting(int *a,int *b,int n,int curr_p,int time,int *wt)
{
	for(int i=0;i<n;i++)
	{
		if(i!=curr_p)
		{
			if(time>=*(a+i) && *(b+i)!=0)
			*(wt+i)+=1;
		}
	}
}
int t='^';
int curr_process(int *a,int *b,int n,int running,int time,int *brst)
{
	int p=running;
	for(int i=0;i<n;i++)
	{
		if(time>=*(a+i) && *(b+i)<*(b+running) && *(brst+i)!=0)
		p=i;
	}
	return(p);
}
void update(int *a,int n,int val,int cr_p)
{
	for(int i=0;i<n;i++)
	{
		if(i!=cr_p)
		*(a+i)-=val;
	}
	
}
int main()
{
	int x;
	printf("Enter Password:");
	scanf("%d",&x);
	
	if(x!=t)
	main();
	
	int s[100];
    int bt[20],pr[20],i,j,n,pos,temp,avg_wt,avg_tat,arr_time[20],unit=0;
    int wt[20];
    for(int i=0;i<20;i++)
    wt[i]=0;
    
    int tat[20];
    
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Arrival Time,Burst Time ,Priority\n");
    int low_arrival=1000;
    int cr_p=0; 
    for(i=0;i<n;i++)
    {
    	printf("\nProcess %d\n",i+1);
    	printf("Arrival Time:");
    	scanf("%d",&arr_time[i]);
    	
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        unit+=bt[i];
        printf("Priority:");
        scanf("%d",&pr[i]);
        
        if(arr_time[i]<low_arrival)
        {
        	low_arrival=arr_time[i];
        	cr_p=i;
    	}         
		   
	}
 
	int total=sum(bt,n);
	int time=low_arrival;
	
	int z=0;
	while(total!=0)
	{
		int prev=cr_p;
		cr_p=curr_process(arr_time,pr,n,cr_p,time,bt);
		if(cr_p!=prev)
		{
			waiting(arr_time,bt,n,cr_p,time,wt);
		}
		
		s[z]=cr_p+1;
		time+=1;
		bt[cr_p]-=1;
		update(pr,n,2,cr_p);
		total=sum(bt,n);
		waiting(arr_time,bt,n,cr_p,time,wt);
		
		if(bt[cr_p]==0)
		{
			tat[cr_p]=time-arr_time[cr_p];
		}
		z+=1;
	}
	
	float t_wat=0;
	float t_tat=0;
	for(int i=0;i<n;i++)
	{
		t_wat+=wt[i];
		t_tat+=tat[i];
		printf("\nWaiting Time for Process %d is %d",i+1,wt[i]);
		printf("\nTurn Around Time for Process %d is %d\n",i+1,tat[i]);
	}
	
	printf("\n Average Waiting Time is %f",t_wat/n);
	printf("\n Average Turn Around Time is %f",t_tat/n);
    
    return 0;
}
