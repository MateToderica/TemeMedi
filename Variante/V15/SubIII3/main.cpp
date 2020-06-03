#include <iostream>
#include <fstream>

int main() {
    int p1,p2;std::cin>>p1>>p2;
    for(int i=1;i<=9&&p1/i!=0;i++)
    {
        if(p1%i==0&&p1/i<=9)
        {
            int i2=p1/i;
            {
                for(int j=1;j<=9&&p2/j!=0;j++)
                {
                    if(p2%j==0&&p2/j<=9)
                    {
                    int j2=p2/j;
                    for(int e=0;e<=9;e++)
                    {
                        std::cout<<i<<i2<<e<<e<<e<<j<<j2<<"\n";
                    }
                    }
                    
                }
            }
        }
    }
}