#include<iostream>
#include<random>
using namespace std;
int  Generate_Random(int t)
{
       random_device rd;
       uniform_int_distribution<int> dis(1,t);
       return dis(rd);

}

void fair_decide(int seat,int overload)
{
  int t=seat+overload;
  for(int i=seat;i<t;i++)
  {
    int rad=Generate_Random(t);
    if(rad!=i+1)
    {
      cout<<i+1<<" will take the place of "<<rad<<endl; 
    }
    else
    {
      cout<<"passanger number "<<i+1<<"is not allowed"<<endl;
    }

  }
}

int main()
{
  int seats[500];
  cout<<"Enter the number of seats in the airplane:";
  int seat,bookings,overload;
  cin>>seat;
  cout<<"How many bookings are made:"<<endl;
  cin>>bookings;
  overload=bookings-seat;
  if(overload<=0)
  {
    cout<<"Flight is not overbooked."<<endl;
  }
  else
  {
    fair_decide(seat,overload);
  }
}
