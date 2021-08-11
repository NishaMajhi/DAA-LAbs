#include<iostream>
using namespace std;


int Merge(int arr[],int lowerBound,int mid,int upperBound,int &c)
{
    int inv=0;
    int s1=mid-lowerBound+1;
    int s2=upperBound-mid;

    int leftArray[s1];
    for(int i=0;i<s1;i++)
    {
        leftArray[i]=arr[lowerBound+i];
    }

    int rightArray[s2];
    for(int j=0;j<s2;j++)
    {
        rightArray[j]=arr[mid+1+j];
    }


    int i=0,j=0,k=lowerBound;
    while(i<s1&&j<s2)
    {
        c++;
       if(leftArray[i]<=rightArray[j])
        {
           arr[k]=leftArray[i];
           i++;
        }
        else
        {
            arr[k]=rightArray[j];
            j++;
            inv+= (mid-i);
        }
        k++;
    }

    while(i<s1)
    {
        arr[k]=leftArray[i];
        i++;
        k++;
    }

    while(j<s2)
    {
        arr[k]=rightArray[j];
        j++;
        k++;
    }

   return inv;
}


int mergeSort(int arr[],int lowerBound,int upperBound,int &c)
{
    int inv=0;
    if(lowerBound>=upperBound)
    {
        return 0;
    }

    int mid=(lowerBound+upperBound)/2;
    inv+= mergeSort(arr,lowerBound,mid,c);
    inv+= mergeSort(arr,mid+1,upperBound,c);
    inv+= Merge(arr,lowerBound,mid,upperBound,c);
    return inv;
}


void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t;
    int c=0,inv=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        inv=mergeSort(arr,0,n-1,c);
        display(arr,n);
        cout<<"comparisons = "<<c<<endl;
        cout<<"Inversion = "<<inv<<endl;

    }
    return 0;
}
