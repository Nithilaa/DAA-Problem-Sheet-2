#include<bits/stdc++.h>
using namespace std;
int Binary_search(int arr[],int l,int r, int key)
{
    if(l<=r)
    {
        int mid = l+((r-l)/2);
        if(arr[mid]==key)
            return 1;
        else if(arr[mid]>key)
            return Binary_search(arr,l,mid-1,key);
        else
            return Binary_search(arr,mid+1,r,key);
    }
    return 0;
}
int main()
{
    int *arr;
    int n;
    int i = 1;
    cout<<"Enter the number of element in the array : ";
    cin>>n;
    arr = new int[n];
    cout<<"Enter the elements:\n";
    for(i=0;i<n;i++)
        cin>>arr[i];
    int key;
    cout<<"Enter the key to be searched : ";
    cin>>key;
    sort(arr,arr+n);
    if(Binary_search(arr,0,n-1,key))
        cout<<"key is found in given array\n";
    else
        cout<<"key is not found in given array\n";
}
