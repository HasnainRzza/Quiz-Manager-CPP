#include"login.cpp"
class temp:public login
{
protected:
    string **teacher_r;
    string **student_r;
    
public:
    temp(/* args */)
    {
        teacher_r=new string*[11];
        for(int i=0;i<11;i++)
        {
            teacher_r[i]=new string[11];
        }
        student_r=new string*[12];
        for(int i=0;i<12;i++)
        {
            student_r[i]=new string[216];
        }        
        next= selection();
        select_load();
    }
    void select_load()
    {
        if(next==1)
        {
            load_teacher_course();
        }
        else if(next==2)
        {
            load_studunt_course();
        }
    }
    void load_teacher_course()
    {
        ifstream tc("course_r_for_teachers.txt");
        ifstream t_n("t_names.txt");
        string t_C;
        int i=0;
        while(t_n>>t_C&&i<11)
        {
            teacher_r[0][i++]=t_C;
        }
        i=0;
        while(tc>>t_C&&i<11)
        {
            teacher_r[1][i++]=t_C;
        }
        tc.close();
        t_n.close();

    }
    void load_studunt_course()
    {
        ifstream s_file("s_id.txt");
        ifstream c_reg("s_creg.txt");
        string data;
        int i=0;
        while(s_file>>data&&i<216)
        {
            student_r[0][i]=data;
          //  cout<<student_r[0][i]<<endl;
            i++;
        }
        s_file.close();
        int j=0;
        i=1;
        while(c_reg>>data&&j<216)
        {
            student_r[i][j]=data;
            i++;
            if(i>11)
            {
                i=1;
                j++;
            }
        }
    c_reg.close();
    
    }
    ~temp()
    {
        for(int i=0;i<11;i++)
        {
            delete[] teacher_r;
        }
        delete[] teacher_r;
         for(int i=0;i<12;i++)
        {
            delete[] student_r;
        }
        delete[] student_r;
    }
};


