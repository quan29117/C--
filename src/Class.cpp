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
/*phạm vi truy cập
    - public: có thể truy cập bên ngoài class
    - private: không thể truy cập bên ngoài class
    - protected: chỉ cho phép class kế thừa truy cập*/
protected:
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
    {   /*định nghĩa thường dùng hơn*/    
        Cut_name(this);
    }

//Hàm hủy - Destructor
    ~Student()
    {
        std::cout<<"Da xoa sinh vien " << full_name;
    }

//Hàm copy - Copy Constructor: Dùng khi nào dữ liệu của class có cấp phát động
    Student (const Student &sinhvien) {
        ID = sinhvien.ID;
    }
//setter - getter
    std::string getFullName()   {return full_name;}
    std::string getName()       {return name;}
    std::string getID()         {return ID;}
    int getAge()                {return age;}
    double getPoint()           {return point;}
    bool getGraduate()          {return graduate;}

//hàm bạn - friend: dùng khi chỉ muốn 1 số hàm (thủ tục) ở ngoài class có khả năng truy cập vào phần tử private mà không cần setter / getter
    friend void Cut_name(Student* temp);

//"this" pointer: bên trong hàm thành viên, con trỏ this trỏ tới đối tượng hiện đang chạy trong hàm thành viên đó
    //không dùng chung với friend vì bản chất là đã thay đổi đối tượng rồi
    void Tot_nghiep()
    {
        this->graduate = true;
    }
    void Edit_name(const std::string &new_full_name)
    {
        this->full_name = new_full_name;
        Cut_name(this);
    }
    
};

//tính kế thừa - kế thừa những gì class được kế thừa có
//cựu sinh viên - phương thức public: có thể dùng ngoài hàm, private: không thể
class Alumnus : public Student 
{
private:
    std::string gift;

public: 
//Constructor: do không kế thừa những constructor nên phải tự định nghĩa lại
    Alumnus () = default;

    Alumnus (const std::string &ho_ten, const std::string &id, int tuoi, double diem, bool tot_nghiep = true)
        : Student(ho_ten, id, tuoi, diem, tot_nghiep)   //định nghĩa kế thừa
    {
        Cut_name(this);
    }

    void tang_qua(const std::string &qua)
    {
        this->gift = qua;
        std::cout<< "Cuu sinh vien " << this->full_name << " da tang " << this->gift << " cho truong!";
    }

    
};      

int main()
{
    Student *A = new Student ("Dang Minh Quan", "22021153", 18, 8.0);
    //std::cout << A->getName() << "\n";

    A -> Edit_name("Nguyen Hoang Nhi");
    // std::cout << A->getFullName() << "\n";
    // std::cout << A->getName() << "\n";

    Alumnus *B = new Alumnus ("Dinh Tien Hoang", "15021153", 25, 9.0);
    B ->tang_qua("ghe da");
    
    
}

void Cut_name(Student* temp)
    {
        int i = temp->full_name.rfind(' ');
        temp->name = temp->full_name.substr(i+1, temp->full_name.length()-i);
    }
