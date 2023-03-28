#include<iostream>
using namespace std;
int euclid_algoritm(int x,int y)
{   
	int rem=1, dev;
	while(rem!=0)
	{
		dev=x/y;
		rem=x%y;
		x=y;
		y=rem;
	}
	return x;
}

int main()
{
	int num1,num2;
	cout<<"Enter the numbers you wanna find common divisior of:"<<endl;
	cin>>num1;
	cin>>num2;
	int output;
	output=euclid_algoritm(num1,num2);
	cout<<"The common divisor of numbers "<<num1<<" and "<<num2<<" is "<<output<<endl;
	return 0;
}
