#include <iostream>
#include <fstream>

void getPrimes(int n, int a[][100])
{
    ///ciur de eratostene
    static bool ciur[10000]={false};///Sper ca sunt destule numere prime pana in 10000 pt mare parte din cazuri
    ciur[0]=1,ciur[1]=1;
    for(int i=2;i<10000;i++)
    {
        if(ciur[i]==0)
        {
            for(int j=2;i*j<10000;j++)
            {
                ciur[i*j]=1;
            }
        }
    }
    int it=3;///Enuntul spune doar numere prime consecutive asa ca incep de la 3 pt a putea verifica doar numerele impare
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            while(ciur[it]==true)
            {
                it+=2;
            }
            //std::cout<<it<<"\n";
            a[i][j]=it;
            it+=2;
        }
    }
}
int* makesir(int n, int a[][100])
{
    static int sir[10000];
    int ita=0;
    int num=0;///Num va tine cont de cate lini am procesat pana acum 
    while((num/2)<n)
    {
        for(int i=num/2;i<n;i++)
        {
            sir[ita++]=a[(num/2)][i];
        }
        num++;
        for(int i=(num+1)/2;i<n;i++)//num+1 deoarece trebuie sa nu proceseze primul element
        {                           //fiind deja procesat anteorior dar coloana trebuie sa ramana aceasi
            sir[ita++]=a[i][num/2];
        }
        num++;
    }
    return sir;
}
void afisare(int n, int a[][100])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}
void printvec(int n, int a[])
{
    for(int i=0;i<n;i++)
    {
        std::cout<<a[i]<<" ";
    }
}
int main()
{
    std::ifstream fin ("date.txt");
    int n,a[100][100];
    std::cin>>n;
    //std::cout<<*(sir+1);
    getPrimes(n,a);
    int *sir=makesir(n,a);
    printvec(n*n,sir);
    std::cout<<"\n";
    afisare(n,a);
}