#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int part(int arr[],int s,int e)
{
    int pivot = arr[e];
    int i = -1;
    for (int j=0;j<e;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1], arr[e]);
    return i+1;

}

void quicksort(int arr[], int s, int e)
{
    if(s>=e)
    {
        return;
    }
    else
    {
        int pi = part(arr, s, e);
        quicksort(arr,s,pi-1);
        quicksort(arr,pi+1,e);
    }
}


int main()
{
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    quicksort(arr,0,n-1);
    for (int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
