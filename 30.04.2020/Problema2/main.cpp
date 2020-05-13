#include <iostream>
#include <fstream>
void citire(int &n, int a[],char file[])
{
    std::ifstream fin (file);
    fin>>n;
    for(int i=0;i<n;i++)
    {
        fin>>a[i];
    }
    fin.close();
}
int main() {
    int sirA[100],lenA,sirB[100],lenB;
    citire(lenA,sirA,"Sir1Caz2.txt"),citire(lenB,sirB,"Sir2Caz2.txt");
    int itA=0,itB=0;
    int cSum=0,mxSize=0,mxSizeIndex,currentSize=0,currentSizeIndex=0;
    while(itA<lenA&&itB<lenB)
    {
        while(cSum<sirB[itB]&&itA<lenA)
        {
            cSum+=sirA[itA++];
            currentSize++;
        }
        if(cSum!=sirB[itB])
        {
            std::cout<<"NU";
            return 0;
        }
        else
        {
            itB++,cSum=0;
            if(currentSize>mxSize)
            {
                mxSize=currentSize,mxSizeIndex=currentSizeIndex;
            }
            currentSizeIndex=itA;
        }
    }
    if(itA==lenA&&itB==lenB)
        std::cout<<"DA\nCea mai mare secventa de lungime: "<<mxSize<<" incepand de la elementul "<<mxSizeIndex;
}