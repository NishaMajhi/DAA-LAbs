#include<iostream>
using namespace std;

int linearSearch(int arr[],int n,int key,int &c)
{

    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            c++;
            return 1;
        }
        else
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
        int key,cnt=0;
        cin>>key;
        int ans=linearSearch(arr,n,key,cnt);
        if(ans==-1)
            cout<<"Not Present "<<cnt<<endl;
        else
            cout<<"present "<<cnt<<endl;
        t--;
    }
    return 0;
}
