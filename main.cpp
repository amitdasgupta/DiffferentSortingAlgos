#include <iostream>

using namespace std;
/**************bubble sort algorithm*////////////////
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
/**********************selection sort algorithm*///////////////////////////
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
void printArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<< " ";
}

int main()
{
    int n,*arr,temp;
    cout<<"enter the number oof the elements"<<endl;
    cin>>n;
    arr=new int[n]();
      for(int i=0;i<n;i++)
      {
          cin>>arr[i];
      }
    //bubbleSort(arr,n);
    selectionSort(arr,n);
    printArray(arr,n);
    return 0;
}
