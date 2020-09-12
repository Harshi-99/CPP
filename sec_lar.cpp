#include<iostream>
using namespace std;
int main()
{
    int a[] = {6,5,2,3,1,4};
    int n = sizeof(a)/sizeof(a[0]);
    int maxi = 0;
    int sec_max = 0;
    for(int i=0; i<n; i++)
    {
        if(maxi < a[i])
            maxi = a[i];
    }
    for(int i=0; i<n; i++)
    {
        if(a[i]!=maxi)
        {
            if(sec_max<a[i])
                sec_max = a[i];

        }
    }
    cout<<sec_max;
    return 0;
}