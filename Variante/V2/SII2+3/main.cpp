#include <iostream>
struct piece{
    int cod,nrExemplare,varsta[10];
}s[20];
int main()
{   
    
    std::cout<<s[0].cod<<" "<<s[0].nrExemplare<<" "<<s[0].varsta[3];
    std::cout<<"\n\n\n\n\nsub3\n";
    int a[5][7]={{1,1,1,1,1,1,1},{1,1,1,1,1,1,1},{1,1,1,1,1,1,1},{1,1,1,1,1,1,1},{1,1,1,1,1,1,1}};
    for(int i=1;i<5;i++)
    {
        for(int j=1;j<7;j++)
        {
            a[i][j]=(a[i-1][j]+a[i][j-1])%10;
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<7;j++)
        {
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<"\n";
    }

}
