#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int &n,int i)
{
	int p=i;
	 int h=2*i+2;
	 int l=2*i+1;

	 if(l<n && arr[p]>arr[l] )
	 	p=l;
	 if(h<n && arr[p]>arr[h])
	 	p=h;
	 if(i!=p)
	 {
	 	swap(arr[i],arr[p]);
	 heapify(arr,n,p);

	 }
	 




}

void heapsort(int arr[],int n)
{
	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}

}
void insert(int arr[],int x,int &n)
{
	
	arr[n]=x;
	n=n+1;
	for(int i=n/2-1;i>=0;i--)
	heapify(arr,n,i);
}

void buildheap(int arr[],int &n)
{
        for(int i=n/2-1;i>=0;i--)
        	heapify(arr,n,i);
}


void print(int arr[],int &n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
int minimum(int arr[])
{
	return arr[0];
}
void extractmin(int arr[],int &n)
{
	arr[0]=arr[n-1];
	n=n-1;
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,n,i);
	cout<<"Heap after performing the extract max is"<<endl;
	print(arr,n);
}
void deletion(int arr[],int &n,int x)

{
	int j;
        for(int i=0;i<n;i++)
        {
        	if(arr[i]==x)
{
j=i;
                 break;
        	}
else
continue;
        	
        		
                 
        }
        arr[j]=arr[n-1];
        n=n-1;
        for(int i=n/2-1;i>=0;i--)
        	heapify(arr,n,i);

}

int main()
{
	int arr[100000];
	int n,option=1,val;
	cout<<"Enter the no of elements in the heap\n";
	cin>>n;
	cout<<"Enter the elements in the heap\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	    buildheap(arr,n);
	while(option)
	{
		cout<<"What operation u want to perform \n Press \n 1. Build heap\n 2.Print\n 3.Insertion\n 4.minimum\n 5.Extract min\n 6.Deletion\n 7.heapsort\n 8.exit\n";
	cin>>option;
	switch(option)
	{
		case 1:
		cout<<"Enter the no of elements in the heap\n";
	     cin>>n;
	    cout<<"Enter the elements in the heap\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
		buildheap(arr,n);
		break;
		case 2:
		print(arr,n);
		break;
		case 3:
		cout<<"Enter the element u want to add\n";
		cin>>val;
		insert(arr,val,n);
		cout<<"Heap after insertion is \n";
		print(arr,n);
		break;
		case 4:
		cout<<"Minimum value in the heap is "<<minimum(arr)<<endl;
		break;
		case 5:
		extractmin(arr,n);
		break;
		case 6:
		cout<<"Enter the element u want to delete\n";
		cin>>val;
		deletion(arr,n,val);
		cout<<"Heap after deletion is\n";
		print(arr,n);
		break;
		case 7:
		heapsort(arr,n);
		break;
		case 8:
		option=0;












	}

	}

	return 0;
	


}
