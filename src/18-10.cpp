#include<iostream>
#include<vector>
#include<iterator>

int main()
{
    std::vector<int> A,B;
    std::vector<int>::iterator iter,iter1;
    A ={1,2,3,4,5};
    B ={10,20,30,40,50};
    iter =B.begin()+3;
    std::copy (A.begin(), A.end(),std::inserter(B,iter));
    for(iter1 = B.begin(); iter1!=B.end();iter1++)
        std::cout<<*iter1<<" ";
}