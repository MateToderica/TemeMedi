#include <iostream>
#include <fstream>
int main()
{
    std::ifstream fin ("bac.in");
    int n,m;fin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        fin>>a[i];
    }
    int ita=0,itb=0;
    int t2;fin>>t2;
    int last=t2>a[ita]?a[ita++]:t2;
    std::cout<<last<<" ";
    if(itb)//Nu pot sa pun expresia in op ternar asa ca am pus-o aici
        fin>>t2,itb++;
    while(ita<n&&itb<m)
    {
        int offset=0;
        while(a[ita+offset]%2==last%2&&ita+offset<n)
        {
            offset++;
        }
        while(t2%2==last%2&&itb<m&&t2<a[ita+offset])
        {
            itb++;fin>>t2;
        }
        if(a[ita+offset%2!=last%2]&&(a[ita+offset]<=t2||itb>=m))
        {
            std::cout<<a[ita+offset];
            last=a[ita+offset];
            ita+=offset;
        }
        else if(t2%2!=last%2)
        {
            std::cout<<t2;
            itb++;
            if(itb<m)
            {
                fin>>t2;
            }
            else break;
        }
        std::cout<<" ";
    }
    while(ita<n)
    {
        if(a[ita]%2!=last%2)
            std::cout<<a[ita]<<" ",last=a[ita];
        ita++;
    }
    while(fin>>t2)
    {
        if(t2%2!=last%2)
            std::cout<<t2<<" ",last=t2;
    }
    return 0;
}
 
