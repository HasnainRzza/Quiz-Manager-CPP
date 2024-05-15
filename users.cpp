#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class users
{
protected:
    string **s_IP;
    string **t_IP;
    int c;
public:
    users(/* args */)
    {
        s_IP=0;
        t_IP=0;
    }
    int menu()
    {
        
        cout<<"\t\t****WELCOME TO EXAMINATION SYSTEM****"<<endl;
        cout<<"Pres 1 if you are a teacher: ";
        cout<<"\nPress 2 if you are a Student: ";
        cout<<"\nEnter your desired answer: ";
        cin>>c;
        if(c!=1&&c!=2)
        {
            cout<<"\nINVLAID DATA :|"<<endl;
            menu();
        }
        else
        {
            return c;
        }
        
    }
    ~users()
    {
        delete s_IP,t_IP;
    }
};

