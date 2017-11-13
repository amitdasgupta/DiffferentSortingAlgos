#include <iostream>
#include<map>
#define pp pair<int,int>
using namespace std;
/**************bubble sort algorithm
void bubbleSort(int* &arr,int n)
{
    int j=n-2,temp,isSwapp=1;
    for(;j>=0&&isSwapp;j--)
    {
        isSwapp=0;
        for(int i=0;i<=j;i++)
        {
            if(arr[i]>arr[i+1])
            {
                isSwapp=1;
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }

    }
}
*////////////////
/**********************selection sort algorithm*
void selectionSort(int* &arr,int n)
{
    int min_,temp,j;
    for(int i=0;i<n-1;i++)
    {
        min_=i;
        for(j=i;j<n;j++)
        {
            if(arr[j]<arr[min_])
                min_=j;
        }
        if(i!=min_)
        {
            temp=arr[i];
            arr[i]=arr[min_];
            arr[min_]=temp;
        }
    }
}
///////////////////////////
/**************************insertion sort algorithm
void insertionSort(int* &arr,int n)
{
    int j,v;
    for(int i=1;i<n;i++)
    {
        j=i;
        v=arr[i];
        while(j>0&&arr[j-1]>v)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=v;
    }
}
*////////////////////////////////////
/*******************merge sort algorithm
void mergeIt(int* &arr,int start,int mid,int last)
{
    //cout<<"amit";
    int n1=mid-start,i,j=0;
    int n2=last-mid+1;
    int *arr1=new int[n1+1];
    int *arr2=new int[n2+1];
    for(i=0;i<n1;i++)
        arr1[i]=arr[start+i];
    arr1[n1]=INT_MAX;
    for(i=0;i<n2;i++)
        arr2[i]=arr[mid+i];
    arr2[n2]=INT_MAX;
    i=0,j=0;
    for(int k=start;k<=last;k++)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k]=arr1[i];
            i++;
        }
        else
        {
            arr[k]=arr2[j];
            j++;
        }
    }
    delete[] arr1;
    delete[] arr2;
}
void mergeSort(int* &arr,int start,int last)
{    if(start>=last)
        return;
    else
    {
        int mid=(last+start+1)/2;
        mergeSort(arr,start,mid-1);
        mergeSort(arr,mid,last);
        mergeIt(arr,start,mid,last);
    }
}*///////////////////////

int partitionForQuickSort(int* &arr,int start,int last)
{

    int pivot=arr[last],temp;
    //cout<<pivot<<" ";
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
      //  cout<<pivot<<" ";
        quickSort(arr,start,pivot-1);
        quickSort(arr,pivot+1,last);
    }
}
/*************finding repition data in any array*////////////
void findRepaetingNumberInArray(int *arr,int n)
{
    int maxi=INT_MIN,maxiCand,currcount;
    cout<<"\n";
    int i=0,temp,flag=0;
    while(i<n)
    {
        currcount=1;
        flag=0;
        temp=arr[i];
        if(temp==arr[i+1])
        while(temp==arr[i+1])
        {
            currcount++;
            /*if(!flag)
              {
                  flag=1;
                  cout<<temp<<" ";
              }*/
            i++;
        }
            i++;
        if(currcount>maxi)
        {
            maxi=currcount;
            maxiCand=temp;
        }

    }
    cout<<maxiCand<<" "<<maxi;
}

/********************************************code for binary search*////////////
bool isBinary(int *arr,int start,int last,int data)
{
    if(start>last)
        return false;
    else
    {
        int mid=(last+start)/2;
        cout<<mid<<endl;
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
    int n,k,*arr,temp,*sorted;
    cout<<"enter the number oof the elements"<<endl;
    cin>>n;
    arr=new int[n]();
      for(int i=0;i<n;i++)
      {
          cin>>arr[i];
      }
    //bubbleSort(arr,n);
    //selectionSort(arr,n);
    //insertionSort(arr,n);
    //mergeSort(arr,0,n-1);
    quickSort(arr,0,n-1);
    printArray(arr,n);
    cout<<"\nenter the number you want to find";
    cin>>temp;
    if(isBinary(arr,0,n-1,temp))
        cout<<"\n data found";
    else
        cout<<"\n data is not found";
    //findRepaetingNumberInArray(arr,n);
    /*************finding repition data in any array*////////////

    /***************************counting sort
    cin>>n>>k;
    arr=new int[n]();
    sorted=new int[n]();
    map<int,int> map_;
    for(int i=0;i<=k;i++)
        map_.insert(pp(i,0));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        ++map_[arr[i]];
    }
    int sum=map_[0];
    for(int i=1;i<=k;i++)
    {
        sum+=map_[i];
        map_[i]=sum;

    }
    int curr;
    for(int i=0;i<n;i++)
    {
        curr=arr[i];
        sorted[map_[curr]-1]=curr;
        map_[curr]--;
    }
    printArray(sorted,n);
    delete[] arr;
    delete[] sorted;*/
    delete[] arr;
    return 0;
}
