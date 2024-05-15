#include"users.cpp"
class login:public users
{
protected:
    int next;
    string name;
public:
    login(/* args */)
    {
        t_IP=new string*[216];
        for(int i=0;i<216;i++)
        {
            t_IP[i]=new string[216];
        }
        s_IP=new string*[216];
        for(int i=0;i<216;i++)
        {
            s_IP[i]=new string[216];
        }
 
    }
    int selection()
    {
        int user=menu();
        if(user==1)
        {
           next= store_data_t();
        }
        else if(user==2)
        {
           next= store_data_s();
        }
        return next;
    }
    int store_data_t()
    {
        ifstream t_name("t_names.txt");
        
        int i=0;
        while(t_name>>name&&i<11)
        {
            t_IP[0][i++]=name;
        }
        t_name.close();
        ifstream t_pass("pft.txt");
        i=0;
        while(t_pass>>name&&i<11)
        {
            t_IP[1][i++]=name;
        }
        t_pass.close();
        for(int i=0;i<11;i++)
        {
            cout<<i<<" "<<t_IP[0][i]<<endl;
        }
        cout<<"press 1 to exit the program: ";
        cin>>c;
        if(c==1)
        {
            cout<<"Good bye ";
            exit(1);
        }
        cout<<"\nSelect who you are: ";
        cin>>c;
        if(c>10)
        {
            cout<<"\nInvalid Data :|";
            store_data_t();
        }
        cout<<"\nEnter you pass:";
        cin>>name;
        if(name==t_IP[1][c])
        {
            return 1;
        }
        else
        {
            cout<<"\nINVALID DATA:";
            store_data_t();
        }
    }
    int store_data_s()
    {
        ifstream s_name("s_id.txt");
        
        int i=0;
        while(s_name>>name&&i<216)
        {
            s_IP[0][i++]=name;
        }
        s_name.close();
        ifstream s_pass("sft.txt");
        i=0;
        while(s_pass>>name&&i<216)
        {
            s_IP[1][i++]=name;
        }
        s_pass.close();
        cout<<"\nEnter your ID:";
        cin>>name;
        string pass;
        cout<<"\nEnter your pass: ";
        cin>>pass;
        int j=0;
        bool aq=false;
        int zxcv=0;
        while(j<216)
        {
            if(s_IP[0][j]==name&&s_IP[1][j]==pass)
            {
                aq=true;
                //return 2;
                break;
            }
            j++;
        }
        if(aq)
        {
            return 2;
        }
        else
        {
            cout<<"\nInvalid ";
            store_data_s();
        }
         
    }
    ~login()
    {
        for(int i=0;i<216;i++)
        {
            delete s_IP[i];
        }
        delete[] s_IP;
        for(int i=0;i<216;i++)
        {
            delete t_IP[i];
        }
        delete[] t_IP;        
    }
};
// int main()
// {
//     login obj;
//     obj.selection();
// }

