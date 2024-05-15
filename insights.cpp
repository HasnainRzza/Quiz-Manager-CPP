#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
class insights
{
protected:
    float marks;
    const int LIMIT=30;
    string **ins_data;
    int in_option;
    string getdata;
public:
    insights(/* args */)
    {
        marks=0;
        ins_data=new string*[100];
        for(int i=0;i<100;i++)
        {
            ins_data[i]=new string[100];
        }
    }
    void in_prompt(string link)
    {
        string temp=link;
        link=temp+"file_names.txt";
        //cout<<link;
        ifstream zzc(link);
        string t;
        int i=0;
        int d=0;
        while(getline(zzc,t))
        {
            if(t.find("marks")!=string::npos)
            {
                ins_data[d][i]=t;
                i++;
            }
            if(t.find("att")!=string::npos)
            {
                ins_data[d][i]=t;
                i++;
                
            }
            if(i>=2)
            {
                d++;
                i=0;
            }
        }

        zzc.close();
    cout<<"\nPress 0 To SEE Attendance: "<<endl;
    cout<<"Press 1 to see Marks: "<<endl;
    cout<<"Press 2 to see Garphs: ";
    cout<<"\nPress 3 to exit";
    cin>>in_option;
        if(in_option==0)
        {
            show_present(d,temp);
        }
        else if(in_option==1)
        {
            show_avg(d,temp);
        }
        else if(in_option==2)
        {
            show_bar(temp);
        }
        else if(in_option==3)
        {
            cout<<"Good bye :)";
            exit(1);
        }
        else
        {
            cout<<"\nInvalid Input";
            in_prompt(temp);
        }
    }
    void show_bar(string temp)
    {
        srand(time(0));
        int ran=rand()%21+10;
        char bar_ary[5][LIMIT];
        ran=ran+marks;
        int pat=rand()%4+1;
        cout<<pat<<" "<<ran<<endl;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<LIMIT;j++)
            {
                if(pat==i)
                {
                    if(ran>j)
                    bar_ary[i][j]='>';
                    else
                    {
                        bar_ary[i][j]='-';
                    }
                }
                else
                {
                    bar_ary[i][j]='-';
                }
            }
        }
        string moto[5]={"Better: ","Good: ","Perfect: ","Excellent: ","Superb: "};
        for(int i=0;i<5;i++)
        {
            cout<<moto[i];
            for(int j=0;j<LIMIT;j++)
            {
                cout<<bar_ary[i][j];
            }
            cout<<endl;
        }

        cout<<"\nThe class performance is: "<<moto[pat];
    in_prompt(temp);

    }
    void show_avg(int d,string temp)
    {
        
        cout<<"\nEnter quiz number (start from 0): ";
        cin>>in_option;
        if(in_option>d)
        {
            cout<<"\nInvlaid input :( "<<endl;
            show_avg(d,temp);
        }        
        else
        {
            cout<<ins_data[in_option][1];
            ifstream show_marks(ins_data[in_option][1]);
            float highest=0.0,lowest=0.0,mark=0.0,total=0.0;
            while(show_marks>>mark)
            {
                marks=marks+mark;
                if(mark>highest)
                {
                    highest=mark;
                }
                if(lowest>mark)
                {
                    lowest=mark;
                }
            }
            marks=marks/14;
            cout<<"\nAverage Marks are: "<<marks;
            // while(show_marks>>mark)
            // {
            //     cout<<mark;
            //     if(mark>highest)
            //     {
            //         highest=mark;
            //     }
            // }
            cout<<"\nHighest Marks are: "<<highest;
            // while(show_marks>>lowest)
            // {
            //     if(lowest>mark)
            //     {
            //         lowest=mark;
            //     }
            // }
            cout<<"\nLowest Marks are: "<<lowest;
            show_marks.close();
        }
        in_prompt(temp);
        
    }
    void show_present(int d,string temp)
    {
        cout<<"\nEnter quiz number (start from 0): ";
        cin>>in_option;
        if(in_option>d)
        {
            cout<<"Invlaid input :( "<<endl;
            show_present(d,temp);
        }
        else
        {
            int temp=0;
            ifstream show_attendace(ins_data[in_option][0]);
            while(getline(show_attendace,getdata))
            {
                cout<<temp<<" " <<getdata<<endl;
            }
            show_attendace.close();
        }
        in_prompt(temp);
    }

    ~insights()
    {
        for(int i=0;i<100;i++)
        {
            delete [] ins_data;
        }
        delete[] ins_data;
    }
};

