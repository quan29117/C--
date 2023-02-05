#include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int f[1000][1000], t[1000];
//     int n;
//     cin >> n;
//     for (int i=0;i<n;++i) cin >> t[i];
    
//     for (int i=n-1;i>=0;--i) {
//         for (int j=i;j<n;++j) {
//             if (i == j)
//                 f[i][j] = n * t[i];
//             else 
//                 f[i][j] = max(f[i+1][j]+t[i]*(n-j+i), f[i][j-1]+t[j]*(n-j+i));
//         }
//     }
    
//     cout << f[0][n-1];
// }

class Sinh_vien {
private:
    std::string ho_ten;
    std::string ten;
    std::string ma_sv;
    int         diem;

    
public:
    Sinh_vien (std::string name, std::string id, int point) 
        : ho_ten (name), ma_sv (id), diem (point)
    {}

    std::string Get_full_name() {
        return this->ho_ten;
    }

    std::string Get_name() {
        return this->ten;
    }

    void Cat_ten();
};

void Sinh_vien::Cat_ten() {
    std::string name = this -> Get_full_name().substr(this -> Get_full_name().rfind(' ')+1,
                                                      this -> Get_full_name().length() - this -> Get_full_name().rfind(' '));
    this -> ten = name;
}

class Cuu_sinh_vien : public Sinh_vien {
    
};

int main () {
    Sinh_vien *first = new Sinh_vien ("Dang Minh Quan", "22021153", 8.5);
    std:: cout << first->Get_full_name() << "\n";
    std:: cout << first->Get_name() << "\n";
    first->Cat_ten();
    std:: cout << first->Get_name();

    return 0;
}
