#include<iostream>
#include <ctime>
#include <cstdlib>
#include<fstream>
#include<string.h>
using namespace std;
class Quiz
{
protected:
    /* data */
    string *quiz_bank;
    string n_quiz;
    string *keys;
    double due_time;
    string quiz_t;
    string *ques_t;
    string *select_topic;
    int quiz_sel;
public:
    Quiz(/* args */)
    {
     quiz_bank=new string[100];
     n_quiz="no";
     keys=new string[100];
     due_time=0;
     quiz_t="no";
     ques_t=new string[100];
     select_topic=new string [100];   
    }
    void Quiz_prompt(string x)
    {
 
        cout<<"\nPress 1 to make quiz by importing file: ";
        cout<<"\nPress 2 to make a new quiz: ";
        cout<<"\nPress 3 to exit from program: ";
        cin>>quiz_sel;
        if(quiz_sel==2)
        {

            write_quiz(x);
        }
        else if(quiz_sel==1)
        {
            import_quiz(x);
        }
        else
        {
            cout<<"\nGood BYE :)";
            exit(1);
        }
    }
    int import_quiz(string x)
    {
            quiz_t=x+"file_names.txt";
            ifstream file(quiz_t);
                if (!file) {
                    cerr << "Error: could not open file_names.txt\n";
                    return 1;
                }

                string filename;
                cout << "Enter a filename: ";
                cin >> filename;

                bool found = false;
                string line;
                while (getline(file, line)) {
                    if (line == filename) {
                        found = true;
                        break;
                    }
                }

                file.close();

                if (found) {
                    cout << "The file name " << filename << " is present in file_names.txt\n";
                    import_quiz(x);
                } else {
                    time_t time_var=set_time();
                  string  path=x+filename+".txt";
                    ofstream N_file(quiz_t,ios_base::app);
                    ofstream qf(path,ios_base::app);
                    qf<<time_var<<endl;
                    N_file<<path<<endl;
                    path=x+filename+"att.txt";
                    ofstream qa(path,ios_base::app);
                    N_file<<path<<endl;
                    path=x+filename+"marks.txt";
                    ofstream qm(path,ios_base::app);
                    N_file<<path<<endl;
                    path=x+filename+"key.txt";
                    ofstream qk(path,ios_base::app);
                    N_file<<path<<endl;
                    N_file<<"----!!"<<endl;
                    N_file.close();
                 //   qf.close();
                    qa.close();
                    qm.close();
                 //   qk.close();
                    path=x+"quiz.txt";
                    ifstream ans_key(path);
                    path=x+"topics.txt";
                    ifstream top(path);
                    string pass;
                    string *head=new string[100];
                    int j=0;
                    char ans;
                     int s;
                    while(getline(top,pass))
                    {
                        head[j]=pass;
                        j++;
                    }
                  //  cout<<head[0];
                    char user_sees='y';
                    while(user_sees!='n')
                    {
                        cout<<"You have topics: "<<endl;
                        for(int i=0;i<j;i++)
                        {
                            cout<<"Press "<<i<<" for "<<head[i]<<endl;
                        }
                        cout<<"Press desired number: ";
                        cin>>j;
                        while (getline(ans_key,pass))
                        {
                            if(pass.find("a5380ee")!=string::npos&&pass.find(head[j])!=string::npos)
                            {
                                cout<<"how many questions you want to include: ";
                                cin>>s;
                                while (getline(ans_key,pass)&&s>0)
                                {
                                    if(pass.find("dabfac4")!=string::npos&&pass.find(head[j])==string::npos)
                                    {
                                        ans=pass.back();
                                        qk<<ans<<endl;
                                        qf<<"<lop>"<<endl;
                                        s--;
                                    }
                                    else
                                    {
                                        qf<<pass<<endl;
                                    }
                                }
                                
                            }
                            
                        }

                        cout<<"\nDo you want to add more questions form different topic n/y: ";
                        cin>>user_sees; 
                        if(user_sees=='n')
                        {
                            Quiz_prompt(x);
                        }
                    }    
                        // while(getline(ans_key,pass))
                        // {
                        //     if(pass.find("dabfac4 ")!=string::npos)
                        //     {
                        //         ans=pass.back();
                        //         qk<<ans<<endl;
                        //     }
                        // }
                        qf.close();
                        qk.close();
                }
                

    }
    void write_quiz(string x)
    {

        
        quiz_t=x;
        string file_name="quiz.txt";
       // file_name.append(".txt");
        string path_name=x;
        string final_name=path_name+file_name;
        
        ofstream T_W_QUIZ(final_name,ios_base::app);
        ofstream topics(x+"topics.txt",ios_base::app);
        if(T_W_QUIZ.is_open())
        {
      //   T_W_QUIZ<<time_var<<endl;
        }
        int descriptive=0,TF=0,MCQ=0;
        string topic;
        char sell='y';
        while (sell!='n')
        {    
            cout<<"\nEnter topic of Questions: ";
            cin.ignore();
            getline(cin,topic);
            topics<<topic<<endl;
            topics.close();
            string temp;
            cout<<"\nEnter no of descriptive questions: "<<endl<<"Enter number of true false questions: "<<endl<<"Enter number of MCQ questions: ";
            cin>>descriptive>>TF>>MCQ;
            T_W_QUIZ<<"a5380ee "<<topic<<endl;
            string question="no vaue";
            if(descriptive>0)
            {
                T_W_QUIZ<<"88f7ace "<<endl;
                cout<<"\n Descriptive Questions ";
                while(descriptive>0)
                {
                cin.ignore();
                    cout<<"Enter a question :";
                    getline(cin,question);
                    T_W_QUIZ<<question<<endl<<"dabfac4"<<endl;
                    descriptive--;
                }
            }
            if(TF>0)
            {
                T_W_QUIZ<<"b94d27b "<<endl;
                cout<<"\n True False Questions ";                
                while(TF>0)
                {
                cin.ignore();
                    cout<<"Enter a question :";
                    getline(cin,question);
                    T_W_QUIZ<<question<<endl;
                    cout<<"OPTION 1: ";
                    getline(cin,question);
                    T_W_QUIZ<<"OPTION 1: "<<question<<endl;        
                    cout<<"Enter correct option as t or f :";
                    cin>>question;
                    T_W_QUIZ<<"dabfac4 "<<question<<endl<<endl;                        
                    TF--;
                }           
            }
            if(MCQ>0)
            {
                T_W_QUIZ<<"b94d27b "<<endl;
                cout<<"\n MCQ Questions ";                
                while(MCQ>0)
                {
                    cin.ignore();
                    cout<<"Enter a question :";
                    getline(cin,question);
                    T_W_QUIZ<<question<<endl;
                    cout<<"OPTION 1: ";
                    getline(cin,question);
                    T_W_QUIZ<<"OPTION 1: "<<question<<endl;
                    cout<<"Option 2: ";
                    getline(cin,question);
                    T_W_QUIZ<<"OPTION 2: "<<question<<endl;
                    cout<<"OPtion 3: ";
                    getline(cin,question);
                    T_W_QUIZ<<"Option 3: "<<question<<endl;
                    cout<<"Enter correct option as a,b,c :";
                    cin>>question;
                    T_W_QUIZ<<"dabfac4 "<<question<<endl<<endl;
                    MCQ--;
                }   
            }
            cin.ignore();
            cout<<"\nDO you want to add anotr topic: ";
            cin>>sell;
            if(sell=='n')
            {
                T_W_QUIZ.close();
                Quiz_prompt(x);
                break;
            }
        }
        cout<<"\nQuestions added  Successfully!";
        T_W_QUIZ.close();

    }
    time_t set_time()
    {
        int t_set_time=0;
        cout<<"Enter time in minutes: ";
        cin>>t_set_time;
        t_set_time=t_set_time*60;
        return t_set_time;
    }
    ~Quiz()
    {
        delete[] quiz_bank;
        delete[] keys;
        delete[] ques_t;
        delete[] select_topic;
    }
};

