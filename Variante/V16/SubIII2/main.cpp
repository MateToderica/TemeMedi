#include <iostream>
int main() {
    int n,m;std::cin>>n>>m;
    int a[n][m],pp=(n*m*2)-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            a[i][j]=pp*pp;
            pp-=2;std::cout<<a[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}
