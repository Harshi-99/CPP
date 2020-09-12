#include<iostream>
using namespace std;
int GCD(int a, int b)
{
    if(a == 0)
        return b;
    return GCD(b%a , a);
}
int LCM(int a, int b)
{
    return ((a*b)/GCD(a,b));
}
int main()
{
    cout<<LCM(15,20);
    return 0;
}