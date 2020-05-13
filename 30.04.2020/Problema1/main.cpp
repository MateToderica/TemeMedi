#include <iostream>
#include <fstream>
int Sir3[100]={14},lenSir3=1;///Sirul prieten
int isPrim(int x)
{
    if(x<2||(x>2&&x%2==0))
    {
        return 0;
    }
    for(int div=3;div*div<=x;div+=2)
    {
        if(x%div==0)
            return 0;
    }
    return 1;
}
int type1(int x)
{
    if(x/9999!=0)
        return 0;
    if(x<2||(x>2&&x%2==0))
        return 0;
    if(isPrim(x))
        return 1;
    else
        return 0; 
}
int cifPrim(int x)
{
    while(x)
    {
        int t=x%10;
        if(t==2||t==3||t==5||t==7)
        {
            return 1;
        }
        x/=10;
    }
    return 0;
}
int type2(int x)
{
    if(!isPrim(x)&&cifPrim(x))
        return 1;
    else
        return 0;
}
int sumDiv(int x)
{
    int sum=x+1;
    for(int it=2;it<x/2;it++)
    {
        if(x%it==0)
        sum+=(it+(x/it));
    }
    return sum;
}
int type3(int x,int a[],int n) ///Cautare Binara ar fi mai eficienta
{
    int sdx=sumDiv(x);
    for(int i=0;i<n;i++)
    {
        if(sdx==sumDiv(a[i]))
            return 1;
    }
    return 0;
}
void citire(int &n,int a[],char file[])
{  
    try
    {
    std::ifstream fin (file);
    fin>>n;
    for(int i=0;i<n;i++)
        { 
            fin>>a[i]; 
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
struct punct
{
    int x,y,z;
};
punct readCodif(int &n,int a[])
{
    static punct t;
    t.x=0,t.y=0,t.z=0; 
    for(int i=0;i<n;i++)
    {
        if(type1(a[i]))
            a[i]=1,t.x++;
        else if(type2(a[i]))
            a[i]=2,t.y++;
        else if(type3(a[i],Sir3,lenSir3))//sir3 si lensir declarate la inceputul fisierului
            a[i]=3,t.z++;
        else
        {
            a[i]=sumDiv(a[i]);
        }
    }
    return t;
}
void cpPunct(punct &target,punct source)
{
    target.x=source.x;
    target.y=source.y;
    target.z=source.z;
}
punct readCodifRec(int n, int a[])
{
    if(!n)
    {
        punct temp;
        temp.x=0,temp.y=0,temp.z=0;
        return temp;
    }
    else if(type1(a[n-1]))
    {
        a[n-1]=1;
        punct temp=readCodifRec(n-1,a);
        temp.x++;
        return temp;
    }
    else if(type2(a[n-1]))
    {
        a[n-1]=2;
        punct temp=readCodifRec(n-1,a);
        temp.y++;
        return temp;
    }
    else if(type3(a[n-1],Sir3,lenSir3))
    {
        a[n-1]=3;
        punct temp=readCodifRec(n-1,a);
        temp.z++;
        return temp;
    }
}
void afis(int n,int a[100])
{
    for(int i=0;i<n;i++)
    {
        std::cout<<a[i]<<" ";
    }
}
void predominant(punct a)
{
    if(a.x>a.y&&a.y>a.z)
        std::cout<<"Tip1 predominant: "<<a.x<<"\n";
    else if(a.y>a.z)
        std::cout<<"Tip2 predominant: "<<a.y<<"\n";
    else
        std::cout<<"Tip3 predominant: "<<a.z<<"\n";
}
void idenTrip(int &n, int a[],bool delFlag)///Delflag alege intre subpunctul c si d (true=d,flase=c)
{
    int offset=0;
    for(int i=0;i<n-2;i++)
    {
       if(a[i]==1&&a[i+1]==2&&a[i+2]==3)
       {
           std::cout<<"Gasit la i:"<<i<<"\n";
           if(delFlag)
           {
           offset+=3;
           i--;
           }
        }
        a[i+1]=a[i+1+offset];
    }
    n-=offset;
}
///Subpunct E
///Sa stiti ca imi pare rau pt functia de mai jos, am scris-o asa in idee de a obtine o(n),
///Alternativ as fi rulat functia de delete pana nu s-ar modifca n, cea ce ar fi mai usor de citit
int sequence(int n,int a[],bool isRoot)///Functia presupune ca sirul are nr de el = multiplu al lui 3
{
        int i;
        for(i=1;i<=3;i++)
        {
            if(a[i-1]!=i)///a[i-1] deoarece i reprezinta codurile incep de la 1 dar indexarea de la 0 
            {
                if(a[i-1]==1)///in cazul in care nu se potriveste dar este 1 => poate incepe o noua secventa
                {
                    if(sequence(n-i+1,a+i-1,0))
                    {
                        a+=3,n-=3,i--;//i-- pt a verifica din nou elementul
                    }
                    else 
                        return 0;
                }
                else return 0;
            }
        }
        n-=(i-1);//elimin pozitiile parcurse intodeauna 3 daca a iesit din for
        a+=(i-1);
        if(!isRoot)//Verific daca sunt in interiorul unei alte secvente,
            return 1;
        if(n>2)//daca n are mai mult de 1 el => ori sirul nu e multiplu de 3 ori mai am secvente neprocesate(n>=3<=>n>2) 
        {
            return sequence(n,a,1);//n-1,a+1 
        }
        else
            return 1;
        
}
int pozvec(int &n, int a[], bool insFlag)
{
    int counter=0;
    for(int i=1;i<n;i++)
    {
        if(a[i-1]==a[i])
            counter++;
    }
    if(insFlag)
    {
        int offset=counter;
        for(int i=n-1;i>0;i--)
        {
            if(a[i-1]==a[i])
            { 
                a[i+offset]=a[i];
                offset--;
                a[i+offset]=1;
                i--;
            }
            else
            a[i+offset]=a[i];
        }
        
    }
    n+=counter;
    return counter;
}


int main() {
    int n,a[100],t1,t2,t3;
    citire(n,a,"file.txt");//Un vector
    punct counter;
    //Subpunct a Iterativ:
    //counter=readCodif(n,a);

    //Subpunct a Recursiv:
    counter=readCodifRec(n,a);

    //Subpunctul b
    predominant(counter);

    //subpunctele c si d.Daca delFlag(ultimul parametru) este true atunci subpunctul d altfel subpuctul c
    idenTrip(n,a,0);

    //Subpunctul e
    std::cout<<sequence(n,a,1)<<"\n";

    //Subpunctele f si g insFlag=1 =>g altfel f    
    std::cout<<pozvec(n,a,1)<<"\n";

    //Afisare vector codificat/inserat 
    //afis(n,a);
}