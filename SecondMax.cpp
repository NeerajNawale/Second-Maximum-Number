#include<iostream>
#include<stdio.h>
class Array
{
		int *arr,size;
	public:
		Array(int n):size(n)
		{
			arr=new int[size];
		}
		void getData()
		{
			printf("\nEnter %i Elements\n",size);
			for(int i=0;i<size;i++)
				scanf("%d",arr+i);
		}
		void sort()
		{
			for(int i=0;i<size-1;i++)
				for(int j=i+1;j<size;j++)
					if(arr[i]>arr[j])
					{
						arr[i]^=arr[j];
						arr[j]^=arr[i];
						arr[i]^=arr[j];
					}
		}
		int findFirstMax()
		{
			this->sort();
			printf("\nFirst Maximum Number in the Array --> %i",*(arr+size-1));
			return arr[size-1];
		}
		int CountOfFirstMax(int fmax)
		{
			int fcount=0;
			for(int i=0;i<size;i++)
				if(arr[i]==fmax)
					fcount++;
			return fcount;
		}
		void findSecondMax(int fmax)
		{
			int fcount=CountOfFirstMax(fmax);
			if(fcount==size)
			{
				printf("\nSecond Maximum Number doesn't Exist\n");
				return;
			}
			int i=0;
			for(;i<size-fcount;i++);
			printf("\nSecond Maximum Number in the Array --> %i",*(arr+i-1));
		}
		void showData(char* msg)
		{
			sort();
			printf("%s",msg);
			for(int i=0;i<size;i++)
				printf("%d\t",*(arr+i));
		}
};
main()
{
	int n;
	{
		printf("\nHow Many Elements? --> ");
		scanf("%d",&n);
	}
	Array a(n);
	a.getData();
	//a.showData("\nSorted Array --> ");
	int fmax=a.findFirstMax();
	a.findSecondMax(fmax);
}


