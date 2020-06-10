#include <iostream>
int main() 
{
    int n,m=0,c;std::cin>>n;
    do
    {
        c=n%10;n/=10;
        if(c==0)
            c=2;
        else if(c%2==0)
            c=0;
        m=m*10+c;
    }while(n);
    std::cout<<m;
    return 0;
}
