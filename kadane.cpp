#include<iostream>
using namespace std;

int robbery(int arr[],int n)
{
    
    int maxz=0;
    for(int i=0;i<2;i++)
    {
        
        int sum=0;
        for(int j=i;j<n;j+=2)
        {
            
            sum+=arr[j];
        }
        if(sum>maxz)
        {
            
            maxz=sum;
        }
            
    }
    return maxz;
}
int main()
{
    int arr[400];
    int n;
    cout<<"Enter the number of elements in the array:";
    cin>>n;
    cout<<"Enter elements of your array"<<endl;
    for(int i=0;i<n;i++)
    {
        
        cin>>arr[i];
    }
    int result=robbery(arr,n);
    cout<<"Maximum money you can rob is"<<result<<endl;
    return 0;
}
