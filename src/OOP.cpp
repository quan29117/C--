#include <iostream>
#include <vector>

class AbstractPeople {
protected:
    std::string Name;
    int Age;

public:
    virtual void Growth() = 0;

    AbstractPeople () = default;
    AbstractPeople (const std::string &name, const int &age)
        : Name(name), Age(age)
    {} 
};

class People : public AbstractPeople {
public:
    People () = default;

    People (const std::string &name, const int &age)
        : AbstractPeople(name, age)
    {}

    virtual void Introduce();

    void Growth() {
        
    }
};

void People::Introduce() {
    std::cout << "My Name is " << this->Name << "\n";
    std::cout << "I'm " << this->Age << " years old\n";
}

class Student: public People {
private:
    std::string School;
    std::string ID;

public:
    Student() {}
    
    Student(const std::string &name, const int &age, const std::string &school, const std::string &id)
        : People(name, age), School(school), ID(id)
    {}

    void Graduate() {
        std::cout << "Student " << this->Name << " has graduated from " << this->School << "!\n";
    }

};

class Employee: public People {
private:
    std::string Company;

public:
    
    Employee(const std::string &name, const int &tuoi,
             const std::string &company)
        : People(name,tuoi), Company(company)
    {}

    void Introduce() {
        std::cout << "I'm " << this->Name << " working at " << this->Company << "\n";
    }

};

//static:
class Rectangle {
private:
    double Width, Length;
    static int Count;
public:
    double Area();
    
    Rectangle() {
        Count++;
    }
    Rectangle(double W, double L) 
        : Width(W), Length(L)
    {
        Count++;
    }

    ~Rectangle() {
        std::cout << "Delete Rectangle\n";
        Count--;
    }

    static int GetCount() {
        return Count;
    }

    Rectangle(const Rectangle &temp) {
        Width = temp.Width;
        Length = 1;
    }

    double GetWidth() {
        return this->Width;
    }

    double GetLength() {
        return this->Length;
    }

    void SetWidth(const double &w) {
        this->Width = w;
    }

    void SetLength(const double &l) {
        this->Length = l;
    }
};

int Rectangle::Count = 0;       //mặc dù private nhưng khai báo và gán giá trị ban đầu thì được phép (không làm được trong class)
double Rectangle::Area() {
    return this->Width * this->Length;
}

//virtual constructor:
class Base {
public:
    //The Virtual Constructor
    static Base *Create (int id);

    Base() = default;
    
    virtual
    ~Base() {}  //virtual destructor: đảm bảo hàm hủy được gọi

    virtual void Display() =0;
};

class Derived1 : public Base{
public: 
    Derived1 () {
        std:: cout << "Derived1 created\n";
    };

    ~Derived1() {
        std:: cout << "Destroy Derived1\n";
    }

    void Display() {
        std:: cout << "Derived1 do sth\n";
    }
};

class Derived2 : public Base{
public: 
    Derived2 () {
        std:: cout << "Derived2 created\n";
    };

    ~Derived2() {
        std:: cout << "Destroy Derived2\n";
    }

    void Display() {
        std:: cout << "Derived2 do sth\n";
    }
};

class User {
private:
    Base *pBase;

public:
    User() 
        : pBase (nullptr)
    {
        //lấy cả Derived1 và 2
        std:: cout << "Enter 1 or 2 for derived: "; 
        int input;
        std:: cin >> input;
        if (input ==1 )
            pBase = new Derived1();
        else if (input == 2) 
            pBase = new Derived2();
    }

    ~User() {
        if (pBase) {
            delete pBase;
            pBase = nullptr;
        }
    }

    void Action () {
        pBase->Display();
    }

};
Base *Base::Create (int id) {
    switch (id) {
    case 1:
        return new Derived1();
        break;
    
    case 2:
        return new Derived2();
        break;
    }
}
int main() {
    People      p ("Amiya", 23);
    Student     s ("Dang Minh Quan", 18, "UET", "22021153");
    Employee    e ("Eyjafjalla", 21, "Rhodes Island");


    std::vector <People* > v { &p, &s, &e};
    
    for (const auto &x : v) {
        // x->Introduce();
    }

    // Rectangle   r1 (1.5,2.5);
    // std:: cout << r1.Area() << "\n";
    // Rectangle   r2 = r1;
    // std:: cout << r2.Area() << "\n";
    
    // r2.SetWidth(3);
    // std:: cout << r1.Area() << "\n" << r2.Area() << "\n";

    User *u1 = new User();

    u1->Action();
    
}