#include<stdio.h>
void radixsort(int a[]);
int largest(int a[]);
void main()
{
	int a[10]={23,67,45,56,87,32,12,59,19,54};
	int i;
	radixsort(a);
	printf("\n the sorted array is");
	for(i=0;i<10;i++)
	{
		printf("%d \t",a[i]);
	}
	
}
void radixsort(int a[])
{
	int i,j,k,remainder,nop=0,divisor=1,larger,pass,bucket[10][10],bucket_count[10];
	larger =largest(a);
	while(larger>0)
	{
		nop++;
		larger=larger/10;
	}
	for(pass=0;pass<nop;pass++)
	{
		for(i=0;i<10;i++)
		bucket_count[i]=0;
		for(i=0;i<10;i++)
		{
			remainder=(a[i]/divisor)%10;
			bucket[remainder][bucket_count[remainder]]=a[i];
			bucket_count[remainder]+=1;
		}
		i=0;
		for(k=0;k<10;k++)
		{
			for(j=0;j<bucket_count[k];j++)
			{
				a[i]=bucket[k][j];
				i++;
			}
			
		}
		divisor=divisor*10;
	}
}
int largest(int a[])
{
	int large,i;
	large=a[0];
	for(i=0;i<10;i++)
	{
	 if(a[i]>large)
	 {
	 	large=a[i];
	 }	
	}
	return large;
}
