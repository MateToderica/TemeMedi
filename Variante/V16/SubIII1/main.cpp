#include <iostream>
int nrdivprim(int n)
{
    int div=2;int sum=0;
    while(n>1)
    {
        int cnum=0;
        while(n%div==0)
            {
                n/=div,cnum++;
            }
        if(cnum%2==1)
            sum++;
        div++;
    }
    return sum;
}
int main()
{
  std::cout<<nrdivprim(5000);
}
