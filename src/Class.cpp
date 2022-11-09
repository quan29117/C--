#include<bits/stdc++.h>

class Vector
{
private:
    double x;
    double y;

public:
    Vector() = default;

    Vector (double _x, double _y)
    {
        x = _x;
        y = _y;
    }

    Vector* add(const Vector &other) const
    {
        return new Vector (x + other.x, y + other.y);
    }

    void print() const
    {
        std::cout << "(" << x << ", " << y << ")";
    }
//setter - getter
    double getX()   {return x;}
    double getY()   {return y;}
};

class Student
{
private:
    std::string full_name;
    std::string name;
    std::string ID;
    int age;
    double point;
    bool graduate;

public:
//Hàm tạo - Constructor
    Student() = default;  //khi chỉ muốn khởi tạo

    // Student(const std::string &ho_ten, const std::string &id, int tuoi, double diem, bool tot_nghiep = false) 
    // {                                           //định nghĩa
    //     full_name = ho_ten;
    //     ID = id;
    //     age = tuoi;
    //     point = diem;
    //     graduate = tot_nghiep;
    // }

    Student(const std::string &ho_ten, const std::string &id, int tuoi, double diem, bool tot_nghiep = false)
        : full_name(ho_ten), ID(id), age(tuoi), point(diem), graduate(tot_nghiep)
    {   /*định nghĩa thường dùng hơn*/  }

//Hàm hủy - Destructor
    ~Student()
    {
        std::cout<<"Da xoa sinh vien" << full_name;
    }

//setter - getter
    std::string getFullName()   {return full_name;}
    std::string getID()         {return ID;}
    int getAge()                {return age;}
    double getPoint()           {return point;}
    bool getGraduate()          {return graduate;}

//hàm bạn - friend: dùng khi chỉ muốn 1 số hàm (thủ tục) có khả năng truy cập vào phần tử private mà không cần setter / getter
    friend void cut_name (Student* temp);

//"this" pointer: bên trong hàm thành viên, con trỏ this trỏ tới đối tượng hiện đang chạy trong hàm thành viên đó
    //không dùng chung với friend vì bản chất là đã thay đổi đối tượng rồi
    void Tot_nghiep()
    {
        this ->graduate = true;
    }
    void Edit_name(const std::string &new_full_name)
    {
        this ->full_name = new_full_name;
    }
};

int main()
{
    Student *A;
    A -> Edit_name("Dang Minh Quan");
    std::cout << A->getFullName();
}