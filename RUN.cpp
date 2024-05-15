#include"teacher_student.cpp"
class RUN:public teacher,public student
{
private:
    /* data */
public:
    RUN(/* args */)
    {
        cout<<"\nClosing...";
    }
    ~RUN()
    {
        cout<<"\nGood bye";
    }
};

int main()
{
 RUN obl;
    return 0;
}
