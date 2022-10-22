#include "mylibrary.h"

bool Kiem_tra_so_Nguyen_To (const int &n)
{
    if (n==0 || n==1) return false;
    else 
        {
            for (int i=2; i<=sqrt(n);i++)
                if (n % i == 0)
                {
                    return false;
                    break;
                }
        }
    return true;    
}