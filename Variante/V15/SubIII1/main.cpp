#include <iostream>
#include <cstring>
int divPrimMax(int n,int &p)
{
    p=0;int d=2;
    while(n>1)
    {
        if(n%d==0)
        {
            p=d;n/=d;
        }
        else
        {
            d++;
        }
    }
}
int main()
{
    int t=0;
    divPrimMax(2000,t);
    std::cout<<t;
}