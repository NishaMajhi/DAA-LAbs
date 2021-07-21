#include<iostream>
using namespace std;

void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int jumpSearch(int arr[],int n,int key,int &c)
{
    int m=2;
    int step=m;
    int prev=0;
    while(arr[min(step,n)-1]<key)
    {
        prev=step;
        step+=m;
        if(prev>=n)
        {
            return -1;
        }
        c++;
    }
    while(arr[prev]<key)
    {
        prev++;
        if(prev==min(step,n))
        {
            return -1;
        }
        c++;
    }
    if(arr[prev]==key)
    {
        c++;
        return 1;
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        insertionSort(arr,n);
        int key,cnt=0;
        cin>>key;
        int ans=jumpSearch(arr,n,key,cnt);
        if(ans==-1)
            cout<<"Not Present "<<cnt<<endl;
        else
            cout<<"present "<<cnt<<endl;
        t--;
    }
    return 0;
}
