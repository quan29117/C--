#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int main()
{
        fstream FILE;
        int n1,n2;
        string line,s1,s2,f_number;
        stringstream ss;
        FILE.open("../txt/22-10.txt", ios::in);
        getline(FILE, line);
        ss<<line;
        getline(ss,s1,' ');
        getline(ss,f_number,';');
                n1 = stoi(f_number);
        getline(ss,s2,',');
        getline(ss,f_number);
                n2 = stoi(f_number);
        cout<<"n1: "<<n1<<"\n"<<"n2: "<<n2<<"\n"<<"s1: "<<s1<<"\n"<<"s2: "+s2+"\n";
}