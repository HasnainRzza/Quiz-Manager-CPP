#include"course_reg.cpp"
#include"Quiz.cpp"
#include"insights.cpp"
#include<ctime>
#include <cstdlib>
class teacher:public Quiz,public insights,virtual public temp
{
protected:
    int t_option;
    string Teacher_name;
    string teacher_stream;
public:
    teacher(/* args */)
    {
        if(next==1)
        {
            t_option=0;
            prompt();
        }
    }
    void prompt()
    {
        for(int i=0;i<11;i++)
        {
            if(t_IP[1][i]==name)
            {
                Teacher_name=t_IP[0][i];
                break;
            }
        }
        for(int i=0;i<11;i++)
        {
            if(teacher_r[0][i]==Teacher_name)
            {
                teacher_stream=teacher_r[1][i];
                break;
            }
        }
        
        cout<<"\nRespected Teacher: "<<Teacher_name<<" Welcome to the stream of "<<teacher_stream;
        cout<<"\nPress 1 to make a QUIZ: ";
        cout<<"\nPress 2 to see INSIGHTS: ";
        cin.ignore();
        cin>>t_option;
         string **paths=new string*[11];
        for(int i=0;i<11;i++)
        {
            paths[i]=new string[11];
        }

        ifstream file("pft.txt");
        string transfer,path_tranfer;
        int b=0;
        while(file>>transfer&&b<11)
        {
            paths[0][b]=transfer;
            b++;
        }
        b=0;
        file.close();
        ifstream file1("paths.txt");
        while(file1>>transfer&&b<11)
        {
            paths[1][b]=transfer;
            b++;
        }
        file1.close();
        for(int i=0;i<11;i++)
        {
            if(paths[0][i]==name)
            {
                transfer=paths[1][i];
            }
        }
        if(t_option==1)
        {
            Quiz_prompt(transfer);
        }
        else if(t_option==2)
        {
            in_prompt(transfer);
        }

    }
    ~teacher()
    {
        cout<<"\nStatus: "<<1;
    }
};
class student:virtual public temp,public Quiz
{
    protected:
        double total;
        double r_time;
        double curr_time;
        string std_choice;
        string **mark_p;
        string **csv;
        int option;
    public:
    student()
    {
        if(next==2)
        {
            total=0;
            curr_time=0;
            std_choice="no";
            mark_p=new string*[500];
            for(int i=0;i<500;i++)
            {
                mark_p[i]=new string[500];
            }
            option=0;
            csv=new string*[2];
            for(int i=0;i<2;i++)
            {
                csv[i]=new string[11];
            }
            show_stream();
        }
    }
    void show_stream()
    {
        cout<<"\nDear Student "<<name<<" you are registered in follwing courses: "<<endl;
        ifstream allocate("course_r_for_teachers.txt");
        while(getline(allocate,std_choice))
        {
            csv[0][option]=std_choice;
            option++;
        }
        allocate.close();
        int m=0;
        option=0;
        for(int i=0;i<216;i++)
        {
            if(name==student_r[0][i])
            {
                int j=i;
                for(int p=1;p<12;p++)
                {
                   csv[1][option++]=student_r[p][j];
                }
            }    
            if(option>11)
            {
                break;
            }
        }
        select_stream();
    } 
        void select_stream()
        {
            cout<<"Do you want to exit: press 1 for yes ";
            cin>>option;
            if(option==1)
            {
                cout<<"GOOD BYE :)";
                exit(1);
            }
            for(int i=0;i<11;i++)
            {
                if(csv[1][i]=="1")
                {
                    cout<<"Press "<<i<<" for "<<csv[0][i];
                    cout<<endl;
                }
            }
            cout<<"\nEnter desired option: ";
            cin>>option;
            if(option>11)
            {
                cout<<"\nIvalid data";
                select_stream();
            }
            ifstream xm("paths.txt");
            string path_Array[100];
            string zc;
            int x=0;
            while(getline(xm,std_choice))
            {
                path_Array[x++]=std_choice;
            }
            xm.close();
            x=0;
            int n=0;
            string d2[50][50];
            if(option==0)
            {

                zc=path_Array[0]+"file_names.txt";
                ifstream files(zc);
                while(getline(files,std_choice))
                {
                    d2[n][x++]=std_choice;
                    if(std_choice.find("----!!")!=string::npos)
                    {
                        n++;
                        x=0;
                    }
 
                }
                files.close();
            }
            else if(option==1)
            {
                zc=path_Array[1]+"file_names.txt";
                ifstream files(zc);
                while(getline(files,std_choice))
                {
                    d2[n][x++]=std_choice;
                    if(std_choice.find("----!!")!=string::npos)
                    {
                        n++;
                        x=0;
                    }
 
                }
                files.close();
            }
            else if(option==2)
            {
                zc=path_Array[2]+"file_names.txt";
                ifstream files(zc);
                while(getline(files,std_choice))
                {
                    d2[n][x++]=std_choice;
                    if(std_choice.find("----!!")!=string::npos)
                    {
                        n++;
                        x=0;
                    }
 
                }
                files.close();
            }
 
            else if(option==3)
            {
                zc=path_Array[3]+"file_names.txt";
                ifstream files(zc);
                while(getline(files,std_choice))
                {
                    d2[n][x++]=std_choice;
                    if(std_choice.find("----!!")!=string::npos)
                    {
                        n++;
                        x=0;
                    }
 
                }
                files.close();
            }
            else if(option==4)
            {
                zc=path_Array[4]+"file_names.txt";
                ifstream files(zc);
                while(getline(files,std_choice))
                {
                    d2[n][x++]=std_choice;
                    if(std_choice.find("----!!")!=string::npos)
                    {
                        n++;
                        x=0;
                    }
 
                }
                 files.close();               
            }
  
            else if(option==5)
            {
                zc=path_Array[5]+"file_names.txt";
                ifstream files(zc);
                while(getline(files,std_choice))
                {
                    d2[n][x++]=std_choice;
                    if(std_choice.find("----!!")!=string::npos)
                    {
                        n++;
                        x=0;
                    }
 
                }
                files.close();
            }
            else if(option==6)
            {
                zc=path_Array[6]+"file_names.txt";
                ifstream files(zc);
                while(getline(files,std_choice))
                {
                    d2[n][x++]=std_choice;
                    if(std_choice.find("----!!")!=string::npos)
                    {
                        n++;
                        x=0;
                    }
 
                }
                 files.close();               
            }
            else if(option==7)
            {
                zc=path_Array[7]+"file_names.txt";
                ifstream files(zc);
                while(getline(files,std_choice))
                {
                    d2[n][x++]=std_choice;
                    if(std_choice.find("----!!")!=string::npos)
                    {
                        n++;
                        x=0;
                    }
 
                }
                files.close();
            }
            else if(option==8)
            {
                zc=path_Array[8]+"file_names.txt";
                ifstream files(zc);
                while(getline(files,std_choice))
                {
                    d2[n][x++]=std_choice;
                    if(std_choice.find("----!!")!=string::npos)
                    {
                        n++;
                        x=0;
                    }
 
                }
                files.close();
            }
            else if(option==9)
            {
                zc=path_Array[9]+"file_names.txt";
                ifstream files(zc);
                while(getline(files,std_choice))
                {
                    d2[n][x++]=std_choice;
                    if(std_choice.find("----!!")!=string::npos)
                    {
                        n++;
                        x=0;
                    }
 
                }
                                files.close();
            }
            else if(option==10)
            {
                zc=path_Array[10]+"file_names.txt";
                ifstream files(zc);
                while(getline(files,std_choice))
                {
                    d2[n][x++]=std_choice;
                    if(std_choice.find("----!!")!=string::npos)
                    {
                        n++;
                        x=0;
                    }
                }
                files.close();
            }
            
            else 
            {
                cout<<"\n Invalid";

            }

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<5;j++)
                {
                    if(d2[i][j]=="----!!")
                    {
                        cout<<"\nPress "<<i<<" to attempt quiz "<<i+1;
                    }
                }
            }
            do{
            cout<<"\nEnter your option: ";
            cin>>option;
            }while(option>11);
            
            if(eligible_chk(d2,n,option))
            {
                attempt_quiz(d2,n,option);
            }
            else
            {
                cout<<"\nAn error occurred :( ";
                show_stream();
            }
                                         }   
        void attempt_quiz(string d2[][50],int row,int opt)
        {
            ofstream att(d2[opt][1],ios_base::app);
            att<<name<<" P"<<endl;
            att.close();
            string attempt[100][100];
            int g=0;
            ifstream tq(d2[opt][0]);
            string ans;
            cin.ignore();
            while(getline(tq,ans))
            {
                if(ans.find("a5380ee")!=string::npos||ans.find("2efcde9")!=string::npos||ans.find("b94d27b")!=string::npos||ans.find("88f7ace")!=string::npos)
                {
                    continue;
                }
                if(ans.find("<lop>")!=string::npos)
                {
                    cout<<"\nAnswer the question: ";

                    getline(cin,std_choice);
                    attempt[1][g]=std_choice;
                    g++;
                    continue;
                }
                else
                {
                    cout<<ans<<endl;
                }
            }
            int h=0;
            tq.close();
            ifstream key(d2[opt][3]);
            
            ofstream mark(d2[opt][2],ios_base::app);
            
            while(getline(key,std_choice))
            {

                attempt[0][h++]=std_choice;
            }
            
            for(int i=0;i<h;i++)
            {
                if(attempt[0][i]=="4")
                {
                  std_choice=attempt[1][i];

                    for(int j=0;j<std_choice.length();j++)
                    {
                        if(std_choice[j]==' ')
                        {
                            total=total+1.2;
                        }
                    }
                }
                if(attempt[0][i]==attempt[1][i])
                {

                    total=total+1;
                }
            }
            mark<<total<<endl;
            mark.close();
            key.close();
             show_stream();



        }
        bool eligible_chk(string d2[][50],int row,int opt)
        {
        //    ifstream file(d2[opt][0]);
            string c;
            int b=0;
            time_t ct=time(nullptr);
            time_t qwt=0;
    
    ifstream fileRead(d2[opt][0]);
    string line;
    getline(fileRead, line);
    int timeFromFile = atoi(line.c_str());
    fileRead.close();
    bool test1=(timeFromFile>0);
    bool test2=false;
    ifstream readfile(d2[opt][1]);
    if(readfile.peek()==ifstream::traits_type::eof())
    {
        test2=true;
    }
    while(getline(readfile,line))
    {
        if(line.find(name)!=string::npos)
        {
            cout<<"\nYou have either attempted or have missed the quiz :(";
            test2=false;
            break;
        }
        else
        {
            test2=true;
        }
    }
            if(test1&&test2)
            {
                return 1;
            }   
            else
            {
                return 0;
            }
        }
    ~student()
    {
        if(next==2)
        {
            for(int i=0;i<500;i++)
            {
                delete[] mark_p[i];
            }
            delete mark_p;
            mark_p=nullptr;
            for(int i=0;i<2;i++)
            {
                delete[] csv[i];
            }
            delete csv;
            csv=nullptr;            
        }
    }
};
// int main()
// {
//     teacher obj;

//     return 0;
// }
