#include <iostream>
void fii(int n)
{
    for(int d=1;d*d<n;d++)
    {
        if(n%d==0)
        {
            std::cout<<'('<<n/d<<" "<<d<<')';
        }
    }
}
int main()
{
    fii(12);
    std::cout<<"\n";
    fii(16);
}
