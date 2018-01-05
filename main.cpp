#include <iostream>
#include<map>
#include<algorithm>
#define pp pair<int,int>
#include<vector>
using namespace std;
int partitionForQuickSort(int* &arr,int start,int last)
{

    int pivot=arr[last],temp;
    int i=start-1;
    for(int k=start;k<last;k++)
    {
        if(arr[k]<=pivot)
        {
            i++;
           temp=arr[k];
           arr[k]=arr[i];
           arr[i]=temp;

        }
    }
    i++;
    temp=arr[i];
    arr[i]=arr[last];
    arr[last]=temp;
    return i;
}
void quickSort(int* &arr,int start,int last)
{
    if(start>=last)
        return;
    else
    {

        int pivot=partitionForQuickSort(arr,start,last);
        quickSort(arr,start,pivot-1);
        quickSort(arr,pivot+1,last);
    }
}

/********************************************code for binary search*////////////
bool isBinary(int *arr,int start,int last,int data)
{
    if(start>last)
        return false;
    else
    {
        int mid=(last+start)/2;
        if(arr[mid]==data)
            return true;
        else
            if(data>arr[mid])
            return isBinary(arr,mid+1,last,data);
        else
             return isBinary(arr,start,mid-1,data);
    }


}

void printArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<< " ";
        cout<<endl;
}

int main()
{
/********problem 9*///////////////////
    int *A,*B,n,temp,flag=0,k;
    cin>>n>>k;
    A=new int[n];
    B=new int[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];
          quickSort(B,0,n-1);
    for(int i=0;i<n;i++)
    {
     temp=k-A[i];
      if(isBinary(B,0,n-1,temp))
      {
          flag=1;
           break;
      }

    }
    if(flag)
        cout<<"yes";
    return 0;
}
