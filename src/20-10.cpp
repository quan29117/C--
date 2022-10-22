#include<iostream>
#include<string>

class Student
{
public: 
    std::string fullname;

    //khởi tạo
    Student ()
    {}

    //Tường minh
    Student (const std::string ht, bool gr)
        : fullname(ht), graduate(gr)
    {}

    //Hủy
    ~Student()
    {/*code*/}

    void study()
    {
        std::cout<<"Hoc bai"<<"\n";
    }

private:
    bool graduate;
};

int main()
{
    Student *Quan = new Student;
    Quan->fullname = "Dang Minh Quan";
    Quan->study();
    std::cout<<Quan->fullname;
    delete Quan;
}