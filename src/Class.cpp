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

class Sinh_vien
{
private:
    std::string full_name;
    std::string ID;
    int age;
    double point;
    bool graduate;

public:
//Hàm tạo - Constructor
    Sinh_vien() = default;  //khi chỉ muốn khởi tạo

    Sinh_vien(const std::string &ho_ten, const std::string &id, int tuoi, double diem, bool tot_nghiep = false) 
    {                                           //định nghĩa
        full_name = ho_ten;
        ID = id;
        age = tuoi;
        point = diem;
        graduate = tot_nghiep;
    }

    Sinh_vien(const std::string &ho_ten, const std::string &id, int tuoi, double diem, bool tot_nghiep = false)
        : full_name(ho_ten), ID(id), age(tuoi), point(diem), graduate(tot_nghiep)
    {   /*định nghĩa thường dùng hơn*/  }

//Hàm hủy - Destructor
    ~Sinh_vien()
    {
        std::cout<<"Da xoa sinh vien" << full_name;
    }

//setter - getter
    std::string getFullName()   {return full_name;}
    std::string getID()         {return ID;}
    int getAge()                {return age;}
    double getPoint()           {return point;}
    bool getGraduate()          {return graduate;}

};

int main()
{
    double x1,y1,x2,y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    Vector v1 (x1, y1);
    Vector v2 (x2, y2);
    v1.print();
    Vector *v_temp = v1.add(v2);
    v_temp ->print();
}