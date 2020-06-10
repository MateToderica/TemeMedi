#include <iostream>
#include <fstream> 
int main()
{
    int temp,mx1=0,mx2=0,mx3=0;
    std::ifstream fin ("bac.in");
    while(fin>>temp)
    {
       if(temp%100==20) 
       {
           if(temp>mx1)
           {
               mx3=mx2;
               mx2=mx1;
               mx1=temp;
           }
           else if(temp>mx2)
           {
               mx3=mx2;
               mx2=temp;
           }
           else if(temp>mx3)
           {
               mx3=temp;
           }
       }
    }
    fin.close();
    std::cout<<mx3<<" "<<mx2<<" "<<mx1;
    return 0;
}
