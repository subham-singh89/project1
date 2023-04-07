//In this we found absolute difference of a 2D array

#include <iostream>
using namespace std;

const int MAX=100;
    
int lsum(int arr[][MAX],int n)
{
    int temp=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                temp+=arr[i][j];
            }
        }
    }
    return temp;
}
int rsum(int arr[][MAX],int n)
{
     int temp=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i+j)==n-1)
            {
                temp+=arr[i][j];
            }
        }
    }
    return temp;
}   
int main()
{
    int n;
    cin>>n;
    int arr[n][MAX];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int left_sum;
    left_sum=lsum(arr, n);
    int right_sum;
    right_sum=rsum(arr,n);
    int absolute_difference;
    if(right_sum>left_sum)
    {
        absolute_difference=right_sum-left_sum;
    }
    else
    {
        absolute_difference=left_sum-right_sum;
    }
    cout<<absolute_difference;
    return 0;
    
}
