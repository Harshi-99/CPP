#include<iostream>
using namespace std;
int main()
{
    int m = 10 , n = 20;
    int count = 0;
    while(m != n)
    {
        m>>=1;
        n>>=1;
        count += 1;
    }
    m<<=count;
    cout<<m;
}