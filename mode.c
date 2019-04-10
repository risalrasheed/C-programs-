#include<stdio.h>

void main()
{
	int num,a[50],b[50],h_count=0,count,i,j,small,temp,flag,median;
	printf("Enter the number of numbers ");
	scanf("%d",&num);
	
	printf("Enter the elements ");
	for(i=0;i<num;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<num;i++)
	{
		small=i;
		for(j=i;j<num;j++)
		{
			if(a[j]<a[small])
				small=j;
		}
		temp=a[i];
		a[i]=a[small];
		a[small]=temp;
	}
	
	for(i=0;i<num;i++)
		b[i]=NULL;
	for(i=0;i<num;i++)
	{
		count=0;
		flag=1;
		for(j=0;j<num;j++)
			if(a[i]==b[j])
			{
				flag=0;
				break;
			}
		if(flag==1)
		{
			for(j=0;j<num;j++)
				if(a[i]==a[j])
					count++;
		}
		if(count>h_count)
		{
			for(j=0;j<num;j++)
				b[j]=NULL;
			h_count=count;
			b[0]=a[i];
		}
		else if(count==h_count)
			{
			for(j=0;j<num;j++)
				if(b[j]==NULL)
				{
					b[j]=a[i];
					break;
				}
			}
	}
	printf("Mode is ");
	for(j=0;j<num;j++)
		if(b[j]!=NULL)
			printf("%d ",b[j]);
			
	if(num%2==0)
	{
		median=(a[(num/2)]+a[(num/2)-1]);
		printf("\nMedian is %f",(float)median/2);
	}
	else
		{
		median=a[num/2];
		printf("\nMedian is %d",median);
		}
}
