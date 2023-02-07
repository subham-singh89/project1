#include<iostream>
using namespace std;
using std::string;
class AskPromotion
{
    virtual void promotion()=0;
};
class Employee:AskPromotion
{   private:
    
    string name;
    string company;
    int age;

    public:

    void set_namel(string Name)
    {
        name=Name;
    }
    string getname()
    {
        return name;
    }
    void set_company(string Company)
    {
        company=Company;
    }
    string getcompany()
    {
        return company;
    }
    void setAge(int Age )
    {  if(Age>=18)
       age=Age;
    }
    int getAge()
    {
        return age;
    }

    void introduce_yourself()
    {
        cout<<"Name-"<<name<<endl;
        cout<<"Company-"<<company<<endl;
        cout<<"Age-"<<age<<endl;
    }
    Employee (string Name,string Company,int Age)
    {
        name=Name;
        company=Company;
       age=Age;
    };
    void promotion()
    {
        if(age>30)
        {
            cout<<name<<",You got promoted!"<<endl;
        }
        else
        cout<<name<<",N0 promotion for you!"<<endl;
    }
};
int main()
{
    Employee employee1=Employee("hirdyansh","Black rifle coffee",23);
    Employee employee2=Employee("Aditya Sharma","Black rifle coffee",31);
    employee1.introduce_yourself();
    cout<<"\n"<<endl;
    employee2.introduce_yourself();
    cout<<"\n"<<endl;
    employee1.promotion();
    employee2.promotion();

}