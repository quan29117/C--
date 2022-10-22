#include<iostream>
#include "mylibrary.h"

#define for(i,a,b) for(int i=a;i<b;i++)

void Print_array (int *a, const int &length)
{
    for(i,0,length) std::cout<<a[i];
}

void Reaccolate_array (int *&a, const int &old_length, const int &new_length)      //a là con trỏ mảng cấp phát động  
{
    int *temp = new int [old_length];
    for(i,0,old_length) temp[i] = a[i];
    delete [] a;
    a = new int [new_length];
    for(i,0,old_length) a[i] = temp [i];
    delete [] temp;
}

int main()
{
    system("cls");
    int *a;
    int n=0,x;
    std::string s;
    std::cout<<Kiem_tra_so_Nguyen_To(37);
    int *ptr_array = new int [n];
    
}