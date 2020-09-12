#include<iostream>
using namespace std;
int gcd(int a, int b)
{
    int gc = 0,num;
    int i;
    int j = 1;
    while(b>gc)
    {
        i = j;
        num = b*(-i);
        cout<<num<<"\n";
        gc = a + num;
        cout<<gc<<"endl";
        j++;
    }   

    cout<<gc;
}
int main()
{
    gcd(30,20);
}