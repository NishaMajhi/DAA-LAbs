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
int binarySearch(int arr[],int n,int key,int &c)
{
    int start=0;
    int stop=n-1;
    while(start<=stop)
    {
        int mid=(start+stop)/2;
        if(key==arr[mid])
        {
            c++;
            return 1;
        }
        else if(key>arr[mid])
                start=mid+1;
             else
                stop=mid-1;
        c++;
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
        int ans=binarySearch(arr,n,key,cnt);
        if(ans==-1)
            cout<<"Not Present "<<cnt<<endl;
        else
            cout<<"present "<<cnt<<endl;
        t--;
    }
    return 0;
}
