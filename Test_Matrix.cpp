#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a[5][5],b[5][5],sum[5][5],hieu[5][5],c[5][5],d[5][5];
    for(int i=1;i<=5;i++)
     for(int j=1;j<=5;j++)
        {
            cin>>a[i][j]>>b[i][j];
            sum[i][j]=a[i][j]+b[i][j];
            hieu[i][j]=a[i][j]-b[i][j];
            c[i][j]=0;
            d[i][j]=0;
        }
    //jioji
    for(int i=1;i<=5;i++)
     for(int j=1;j<=5;j++)
        {
            int count =1;
            while (count<=5)
            {
                d[i][j]+=sum[i][count]*hieu[count][j];
                c[i][j]+=a[i][count]*a[count][j];
            }
        }
    double hieu2[5][5];
}