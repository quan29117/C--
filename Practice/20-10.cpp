#include<iostream>

template <typename Type>
void swap(Type &a, Type &b)
{
    Type temp;
    temp = a;
    a = b;
    b = temp;
}


int main()
{
    double n1,n2;
    std::cin>>n1>>n2;
    swap(n1,n2);
    std::cout<<n1<<" "<<n2;
}