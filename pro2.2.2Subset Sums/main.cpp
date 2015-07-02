/*
ID: lxxxsou1
PROG: subset
LANG: C++
*/
#include<fstream>
#include<cmath>
#include<iostream>
#include <string>
#include<memory.h>

using namespace std;

int main()
{
    ifstream fin ("subset.in");
    ofstream fout ("subset.out");
    int num,sum,i,j;
    unsigned long f[10000];//f[j]即为策略数
    fin>>num;
    sum=(num*num+num)/2;
    if(sum%2!=0)
    {
        fout<<0<<endl;
        return 0;
    }
    else
        sum=sum/2;

    memset(f,0,sizeof(f));
    f[0]=1;
    for(i=1;i<=num;i++)//第i个循环中   f[j]为背包容量j时，放入前i-1个时的策略数  例如第1个循环  f[j]=1即为背包容量为j是用第一个将他填满的策略数为1，所以f[1]=1
    {
        for(j=sum;j>=i;--j)
        {
            f[j]=f[j]+f[j-i];
        }
    }
    fout<<f[sum]/2<<endl;
    return 0;
}
