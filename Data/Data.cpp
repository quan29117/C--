#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;

#define for(i,a,b) for(unsigned int i=a; i<b;i++)

struct Student
{
    string fullname,name;
    string gender;
    unsigned short age;
    string ID;
    double Math,Phys,IT,AV;
};

vector <Student> A;
vector <unsigned int> search_index;

void input(vector <Student> &A);
void print_student(); //1
void add_student(); //2
void edit_student(); //3
void delete_student(); //4
void search_student(); //5
void sort_student(); //6
void statistic_student(); //7
void save(); //8

int main()
{
    input(A);
    char key;
    bool kt=true;
    while (kt==true)
    {
        // system("cls");
        cout<<"Danh sach thao tac: \n1 - In danh sach sinh vien\n2 - Them sinh vien\n3 - Sua thong tin\n4 - Xoa sinh vien\n5 - Tim kiem";
        cout<<"\n6 - Sap xep\n7 - Thong ke\n8 - Sao luu\n9 - Thoat";
        cout<<"\nNhap lenh: ";
        cin>>key;
        _sleep(500);
        switch (key)
        {
            case '1': {
                        system("cls");
                        print_student();
                        system("pause");
                        break;
                    }
            case '2': {
                        system("cls");
                        add_student();
                        system("pause");
                        break;
                    }           
            case '3': {
                        system("cls");
                        edit_student();
                        system("pause");               
                        break;
                    }
            case '4': {
                        system("cls");
                        delete_student();
                        system("pause");                        
                        break;
                    }
            case '5': {
                        system("cls");
                        search_student();
                        system("pause");                        
                        break;
                    }
            case '6': {
                        system("cls");
                        sort_student();
                        system("pause");                        
                        break;
                    }
            case '7': {
                        system("cls");
                        statistic_student();
                        system("pause");                        
                        break;
                    }
            case '8': {
                        system("cls");                
                        save();                        
                        system("pause");
                        break;
                    }
            case '9': {
                        cout<<"(!!) Ban da thoat khoi chuong trinh\n     Cam on vi da su dung\n";
                        system("pause");
                        kt=false;
                    }
        }
    } 
}

string no_to_string(const double &n)
{
    stringstream ss;
    ss<<n;
    return ss.str();
}
double string_to_no (const string &s)
{
    stringstream ss;
    ss<<s;
    double a;
    ss >> a;
    return a;
}
void Tinh_AV(Student &s)
{
    s.AV=(s.Math+s.Phys+s.IT)/3;
}
void Cut_name(Student &s)
{
    unsigned int i=s.fullname.rfind(' ');
    i++;
    s.name = s.fullname.substr(i,s.fullname.size()-i);
}
void input(vector <Student> &A)
{
    ifstream file;
    file.open("./Data/Data.txt", ios::in | ios::app);
    Student tmp;
    string line;
    while(getline(file,line))
        {
            stringstream ss;
            string f_number;
            ss<<line;
            getline(ss,tmp.fullname,';');
            getline(ss,tmp.gender,';');
            getline(ss,f_number,';');
                tmp.age = string_to_no(f_number);
            getline(ss,tmp.ID,';');
            getline(ss,f_number,';');
                tmp.Math = stod(f_number);
            getline(ss,f_number,';');
                tmp.Phys = stod(f_number);
            getline(ss,f_number,';');
                tmp.IT = stod(f_number);
            A.push_back(tmp); 
            Tinh_AV(A[A.size()-1]);
            Cut_name(A[A.size()-1]);
        }
}

void print_space (const short &n)
{
    for(i,0,n) cout<<" ";
}
void print_student ()
{   
    cout<<"[1] In danh sach sinh vien:\n";
                 //9                 //30                 //10           //18                //20
    cout<<"\t+---------+------------------------------+----------+------------------+--------------------+\n";
    cout<<"\t|   STT   |          Ho va Ten           |   Tuoi   |        ID        |   Diem trung binh  |\n";
    cout<<"\t+---------+------------------------------+----------+------------------+--------------------+\n";
    for(i,0,A.size())
        {
        unsigned short stt_space=(9-no_to_string(i+1).length())/2;
        unsigned short fullname_space=(30-A[i].fullname.length())/2;
        unsigned short age_space=(10-no_to_string(A[i].age).length())/2;
        unsigned short ID_space=(18-A[i].ID.length())/2;
        unsigned short AV_space=(20-no_to_string(A[i].AV).length())/2;
        cout<<"\t|"; print_space(stt_space); cout<<i+1; print_space(9-stt_space-no_to_string(i+1).length());
        cout<<"|"; print_space(fullname_space); cout<<A[i].fullname; print_space(30-A[i].fullname.length()-fullname_space);
        cout<<"|"; print_space(age_space); cout<<A[i].age; print_space(10-age_space-no_to_string(A[i].age).length());
        cout<<"|"; print_space(ID_space); cout<<A[i].ID; print_space(18-A[i].ID.length()-ID_space);
        cout<<"|"; print_space(AV_space); cout<<A[i].AV; print_space(20-AV_space-no_to_string(A[i].AV).length()); cout<<"|\n";
        }
    cout<<"\t+---------+------------------------------+----------+------------------+--------------------+\n";
}

void add_student()
{
    cout<<"[2] Them sinh vien:\n";
    Student s;
    cout<<"\t(>>) Nhap ten: "; cin>>s.fullname;
    cout<<"\t(>>) Nhap gioi tinh: "; cin>>s.gender;
    cout<<"\t(>>) Nhap tuoi: "; cin>>s.age;
    cout<<"\t(>>) Nhap ID: "; cin>>s.ID;
    cout<<"\t(>>) Nhap diem thanh phan: \n\t          Toan: "; cin>>s.Math;
    cout<<"\t          Ly: "; cin>>s.Phys;
    cout<<"\t          Tin: "; cin>>s.IT;
    A.push_back(s);
    cout<<"\t(!!) Dang them sinh vien";
    _sleep(1000);
    cout<<".";
    _sleep(1000);
    cout<<".";
    _sleep(1000);
    cout<<".";
    _sleep(2000);
    cout<<"\n\t(!!) Da them sinh vien thanh cong\n";
}

void edit_s(Student &s)
{
    system("cls");
    cout<<"Nhap lenh: 3\n[3] Suu thong tin sinh vien:";
    _sleep(500);
    cout<<"\n\t(??) Sua thong tin: \n\t\t(1) Ho va ten: "<<s.fullname<<"\n\t\t(2) Gioi tinh: "<<s.gender<<"\n\t\t(3) Tuoi: "<<s.age;
    cout<<"\n\t\t(4) ID: "<<s.ID<<"\n\t\t(5) Diem Toan: "<<s.Math<<"\n\t\t(6) Diem Ly: "<<s.Phys<<"\n\t\t(7) Diem Tin: "<<s.IT;
    cout<<"\n\t(>>) "; 
    char key_edit2;
    cin>>key_edit2;
    switch (key_edit2)
        {
             case '1': {
                cout<<"\tNhap ho ten sau khi sua: "; 
                string ten;
                cin>>ten;
                s.fullname=ten;
                cout<<"\t(!!) Da sua ho ten thanh: "<<ten<<"\n";
                break;
                }
             case '2': {
                cout<<"\tNhap gioi tinh sau khi sua: "; 
                string gioi_tinh;
                cin>>gioi_tinh;
                s.gender=gioi_tinh;
                cout<<"\t(!!) Da sua gioi tinh thanh: "<<gioi_tinh<<"\n";
                break;
                }
            case '3': cout<<"\tNhap tuoi sau khi sua: "; 
                unsigned short tuoi;
                cin>>tuoi;
                s.age=tuoi;
                cout<<"\t(!!) Da sua do tuoi thanh: "<<tuoi<<"\n";
                break;
            case '4': cout<<"\tNhap ID sau khi sua: "; 
                unsigned int ID_edit;
                cin>>ID_edit;
                s.ID=ID_edit;
                cout<<"\t(!!) Da sua ID thanh: "<<ID_edit<<"\n";
                break;
            case '5': cout<<"\tNhap diem Toan sau khi sua: "; 
                double Mpoint;
                cin>>Mpoint;
                s.Math=Mpoint;
                Tinh_AV(s);
                cout<<"\t(!!) Da sua diem Toan thanh: "<<Mpoint<<"\n";
                break;
            case '6': cout<<"\tNhap diem Ly sau khi sua: "; 
                double Ppoint;
                cin>>Ppoint;
                s.Phys=Ppoint;
                Tinh_AV(s);
                cout<<"\t(!!) Da sua diem Ly thanh: "<<Ppoint<<"\n";
                break;
            case '7': cout<<"\tNhap diem Tin sau khi sua: "; 
                double Ipoint;
                cin>>Ipoint;
                s.IT=Ipoint;
                Tinh_AV(s);
                cout<<"\t(!!) Da sua diem Tin thanh: "<<Ipoint<<"\n";
                break;
        }
}
void edit_student()
{
    cout<<"[3] Suu thong tin sinh vien:\n";
    cout<<"\t(??) Ban muon sua thong tin cua ai: \n";
    for(i,0,A.size())
        cout<<"\t     "<<i+1<<". "<<A[i].fullname<<" - ID: "<<A[i].ID<<"\n";
    cout<<"\t(>>) Sua thong tin so: "; 
    short key_edit1;
    cin>>key_edit1;
    edit_s(A[key_edit1-1]);
}

void search_fullname(string &str)
{
    search_index.clear();
    for(i,0,A.size()) 
        if(A[i].fullname.find(str)!= string::npos) 
            search_index.push_back(i);
}
void search_ID(string ID_search)
{
    search_index.clear();
    for(i,0,A.size()) 
        if(A[i].ID.find(ID_search)!= string::npos) 
            search_index.push_back(i);
}
void delete_student()
{
    cout<<"[4] Xoa sinh vien:\n";
    cout<<"\t(??) Ban muon xoa theo:\n\t\t(1) Ten\n\t\t(2) ID";
    char key_delete1;
    cout<<"\n\t(>>) "; 
    cin>>key_delete1;
    switch(key_delete1)
    {
        case '1': 
        {
            cout<<"\tNhap ten can xoa: ";
            string fullname_delete; cin>>fullname_delete;
            search_fullname(fullname_delete);
            if (search_index.size()==0) cout<<"\t(!!) Ten khong ton tai";
             else 
             {
                cout<<"\t(??) Danh sach sinh vien co the xoa: ";
                for(i,0,search_index.size()) cout<<"\n\t\t("<<i+1<<") "<<A[search_index[i]].fullname<<" - ID: "<<A[search_index[i]].ID;
                short key_delete2;
                cout<<"\n\t(>>) Nhap so cua sinh vien ban muon xoa: "; cin>>key_delete2;
                cout<<"\t(!!) Da xoa sinh vien co ho ten: "<<A[search_index[key_delete2-1]].fullname;
                A.erase(A.begin()+search_index[key_delete2-1]);
             }
            break;
        }

        case '2':
            cout<<"\tNhap ID can xoa: ";
            string ID_delete; cin>>ID_delete;
            search_ID(ID_delete);
            if (search_index.size()==0) cout<<"\t(!!) ID khong ton tai\n";
             else 
             {
                cout<<"\t(??) Danh sach sinh vien co the xoa: ";
                for(i,0,search_index.size()) cout<<"\n\t\t("<<i+1<<") "<<A[search_index[i]].fullname<<" - ID: "<<A[search_index[i]].ID;
                short key_delete2;
                cout<<"\n\t(>>) Nhap so cua sinh vien ban muon xoa: "; cin>>key_delete2;
                cout<<"\t(!!) Da xoa sinh vien co ID: "<<A[search_index[key_delete2-1]].ID<<"\n";
                A.erase(A.begin()+search_index[key_delete2-1]);
             }
            break;
    }
}

void print_s()
{                //9                // 30                 //10           //18                //20
    cout<<"\t+---------+------------------------------+----------+------------------+--------------------+\n";
    cout<<"\t|   STT   |          Ho va Ten           |   Tuoi   |        ID        |   Diem trung binh  |\n";
    cout<<"\t+---------+------------------------------+----------+------------------+--------------------+\n";
    for(i,0,search_index.size())
        {
        unsigned short stt_space=(9-no_to_string(search_index[i]).length())/2;
        unsigned short fullname_space=(30-A[search_index[i]].fullname.length())/2;
        unsigned short age_space=(10-no_to_string(A[search_index[i]].age).length())/2;
        unsigned short ID_space=(18-A[search_index[i]].ID.length())/2;
        unsigned short AV_space=(20-no_to_string(A[search_index[i]].AV).length())/2;
        cout<<"\t|"; print_space(stt_space); cout<<search_index[i]+1; print_space(9-stt_space-no_to_string(i+1).length());
        cout<<"|"; print_space(fullname_space); cout<<A[search_index[i]].fullname; print_space(30-A[search_index[i]].fullname.length()-fullname_space);
        cout<<"|"; print_space(age_space); cout<<A[search_index[i]].age; print_space(10-age_space-no_to_string(A[search_index[i]].age).length());
        cout<<"|"; print_space(ID_space); cout<<A[search_index[i]].ID; print_space(18-A[search_index[i]].ID.length()-ID_space);
        cout<<"|"; print_space(AV_space); cout<<A[search_index[i]].AV; print_space(20-AV_space-no_to_string(A[search_index[i]].AV).length()); cout<<"|\n";
        }
    cout<<"\t+---------+------------------------------+----------+------------------+--------------------+";
}
void search_student()
{
    cout<<"[5] Tim kiem:\n";
    cout<<"\t(??) Ban muon tim kiem thong tin theo:\n\t\t(1) Ten\n\t\t(2) ID";
    char key_search1; 
    cout<<"\n\t(>>) "; cin>>key_search1;
    switch (key_search1)
    {
    case '1':
        {
            string s_search;
            cout<<"\tNhap ki tu: "; cin>>s_search;
            search_fullname(s_search);
            break;
        }     
    case '2':
        {
            string ID_search;
            cout<<"\tNhap ID: "; cin>>ID_search;
            search_ID(ID_search);
            break;
        }
    }
    print_s();
    cout<<"\n";
}

bool ascending_compare_by_name(const Student &x, const Student &y)
{
    if (x.name != y.name) return (x.name < y.name);
        else return(x.fullname < y.fullname);
}
bool descending_compare_by_name(const Student &x, const Student &y)
{
    if (x.name != y.name) return (x.name > y.name);
        else return(x.fullname > y.fullname);
}
bool ascending_compare_by_Math(const Student &x, const Student &y)
{
    return (x.Math < y.Math);
}
bool descending_compare_by_Math(const Student &x, const Student &y)
{
    return (x.Math > y.Math);
}
bool ascending_compare_by_Phys(const Student &x, const Student &y)
{
    return (x.Phys < y.Phys);
}
bool descending_compare_by_Phys(const Student &x, const Student &y)
{
    return (x.Phys > y.Phys);
}
bool ascending_compare_by_IT(const Student &x, const Student &y)
{
    return (x.IT < y.IT);
}
bool descending_compare_by_IT(const Student &x, const Student &y)
{
    return (x.IT > y.IT);
}
bool ascending_compare_by_AV(const Student &x, const Student &y)
{
    return (x.AV < y.AV);
}
bool descending_compare_by_AV(const Student &x, const Student &y)
{
    return (x.AV > y.AV);
}
void sort_student()
{
    cout<<"[6] Sap xep:\n";
    cout<<"\t(??) Sap xep theo: \n\t\t(1) Ten ABC\n\t\t(2) Diem Toan\n\t\t(3) Diem Ly\n\t\t(4) Diem Tin\n\t\t(5) Diem trung binh\n";
    cout<<"\t(>>) ";
    char key_sort1;
    cin>>key_sort1;
    cout<<"\t(??) Sap xep: \n\t\t(1) Tang dan\n\t\t(2) Giam dan\n";
    cout<<"\t(>>) ";
    char key_sort2;
    cin>>key_sort2;
    switch (key_sort1)
    {
        case '1': //name
        {
            if (key_sort2=='1') sort(A.begin(),A.end(),ascending_compare_by_name);
                else sort(A.begin(),A.end(),descending_compare_by_name);
            break;
        }
        case '2': //Math
        {
            if (key_sort2=='1') sort(A.begin(),A.end(),ascending_compare_by_Math);
                else sort(A.begin(),A.end(),descending_compare_by_Math);
            break;
        }
        case '3': //Phys
        {
            if (key_sort2=='1') sort(A.begin(),A.end(),ascending_compare_by_Phys);
                else sort(A.begin(),A.end(),descending_compare_by_Phys);
            break;
        }
        case '4': //IT
        {
            if (key_sort2=='1') sort(A.begin(),A.end(),ascending_compare_by_IT);
                else sort(A.begin(),A.end(),descending_compare_by_IT);
            break;
        }
        case '5': //AV
        {
            if (key_sort2=='1') sort(A.begin(),A.end(),ascending_compare_by_AV);
                else sort(A.begin(),A.end(),descending_compare_by_AV);
            break;
        }
    }
    system("cls");
    cout<<"[6] Sap xep:\n";
    print_student();
}

void statistic_student()
{
    cout<<"[7] Thong ke:\n";
    search_index.clear();
    unsigned int GA=0, MA=0, WA=0;
    double AV_class=0, GR=0, MR=0, WR=0,max_AV=0;
    for (i,0,A.size())
    {
        AV_class+=A[i].AV;
        if (max_AV<A[i].AV) 
            max_AV=A[i].AV;
        if (A[i].AV>8) 
            GA++;
            else if(A[i].AV>6 && A[i].AV <8) MA++;
                else WA++;
    }
    for (i,0,A.size())
        if (A[i].AV ==max_AV) search_index.push_back(i);
    GR=GA/A.size()*100;
    MR=MA/A.size()*100;
    WR=WA/A.size()*100;
    cout<<"\t(!!) Diem trung binh ca lop: "<<AV_class / A.size();
    cout<<"\n\t(!!) Ti le sinh vien gioi: "<<GR<<"%";
    cout<<"\n\t(!!) Ti le sinh vien kha: "<<MR<<"%";
    cout<<"\n\t(!!) Ti le sinh vien kem: "<<WR<<"%";
    cout<<"\n\t(!!) Sinh vien co diem trung binh cao nhat ("<<max_AV<<") la:";
    for(i,0,search_index.size()) cout<<"\n\t\t\t"<<A[search_index[i]].fullname;
    cout<<"\n";
}

void save()
{
    cout<<"[8] Luu thong tin:\n";
    ofstream file;
    file.open("./Data/Data.txt", ios::out);
    for (i,0,A.size()) 
     file<<A[i].fullname<<";"<<A[i].gender<<";"<<A[i].age<<";"<<A[i].ID<<";"<<A[i].Math<<";"<<A[i].Phys<<";"<<A[i].IT<<(i!=A.size()-1 ? "\n" : "");
    cout<<"\t(!!) Dang luu du lieu";
    _sleep(1000);
    cout<<".";
    _sleep(1000);
    cout<<".";
    _sleep(1000);
    cout<<".";
    _sleep(2000);
    cout<<"\n\t(!!) Da luu du lieu thanh cong\n";
}