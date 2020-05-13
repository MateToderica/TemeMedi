#include <iostream>
#include <fstream>
void generare(int &n,int &k,int a[][100],char file[])
{
    std::ifstream fin (file);
    fin>>n>>k; 
    fin.close();
    for(int i=0;i<=n+2;i++)
    {
        for(int j=0;j<2*n+2;j++)
        {
            a[i][j]=0;
        }
    }
    a[1][((2*n+1)/2)+1]=1;
    for(int i=2;i<=n+1;i++)
    {
        for(int j=1;j<=2*n+1;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1];
        }
    }
}
int linsum(int a[],int len)
{
    int sum=0;
    for(int i=1;i<=len;i++)
    {
        sum+=a[i];
    }
    return sum;
}
int valLinie(int k)
{
    if(k==0)
    return 1;
    int r=3;
    for(int i=1;i<k;i++)
    {
        r*=3;
    } 
    return r;
}
int consum(int n,int m,int k,int a[][100])
{
    int sum=0;
    int i=1;
    while(i<=n&&k<=m) 
        {
            sum+=a[i][k];
            std::cout<<a[i][k]<<"\n";
            i++,k+=2;
        }
    return sum;
}
void printmat(int n,int m, int a[][100])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]<10)
            std::cout<<" ";
            std::cout<<a[i][j]<<" ";
            if(a[i][j]<100)
            std::cout<<" ";
        }
        std::cout<<"\n";
    }
}
int main()
{
    int n,k, a[100][100];
    generare(n,k,a,"input.txt");
    std::cout<<valLinie(k);//Am verificat si pentru oricare k<n+1 formula functioneaza
    printmat(n+1,2*n+1,a);
    std::cout<<"\n"<<consum(n+1,2*n+1,k+1,a);//Nu am gasit solutie in o(1) timp
}