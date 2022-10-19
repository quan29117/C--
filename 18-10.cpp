#include<bits/stdc++.h>
using namespace std;

int main()
{
    int myint [] = {3,9,5,36,222,145,65};
		set <int> A (myint, myint + 5);
    cout<<"Set A truoc khi thao tac: ";
    for (const auto &x: A)
        cout<<x<<" ";
    int n=0, index=2;
    for (auto &x: A)
    {
        if (n==index)
        {
            A.insert(x+3);
            A.erase(x);
            break;
        }
        n++;
    }
    cout<<"\nSet A sau khi thao tac: ";
    for (const auto &x: A)
        cout<<x<<" ";
}