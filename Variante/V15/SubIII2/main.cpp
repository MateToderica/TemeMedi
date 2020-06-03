#include <iostream>
#include <cstring>
int main()
{
    char str[105];std::cin.getline(str,100);
    int cons =0,vows=0,nr=0;
    char *p=str;
    while(*p)
    {
        if(*p==' ')
        {
            if(cons==vows)
                nr++;
            cons=0,vows=0;
        }
        else if(strchr("aeiou",*p))
            vows++;
        else
            cons++;
        p++;
    }
    if(cons==vows&&cons!=0)
        nr++;
    std::cout<<nr<<"\n";
}
