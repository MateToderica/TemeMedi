#include <iostream>
#include <cstring> 
int main()
{
    char str[100];
    std::cin.getline(str,100);
    char *p=strtok(str," "),rez[100]="\0";
    while(p)
    {
        if(*p!='-')
        {
            strcat(rez,p);
        }
            strcat(rez," ");
            p=strtok(NULL," ");
    }
    std::cout<<rez;
}
