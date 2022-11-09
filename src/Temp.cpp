#include <bits/stdc++.h>
using namespace std;

int closest( vector <int> a, int n, int target)
{
    if (target <= a[0]) return 0;
    if (target >= a[n-1]) return n-1;
    int l=0, r=n-1, mid = 0;
    while (r >= l)
    {
        mid = (r+l) /2;
        if (a[mid] == target) return mid;
        if (a[mid] > target)
        {
            if (mid >0 && a[mid-1] < target)
                return ( a[mid] - target <= target - a[mid-1] ? mid : mid-1);
            r = mid -1;
        }
        else
        {
            if (mid < n-1 && a[mid+1] > target) 
                return ( target - a[mid] <= a[mid+1] - target ? mid : mid+1);
            l = mid +1;
        }
    }
}


int main()
{
    
}