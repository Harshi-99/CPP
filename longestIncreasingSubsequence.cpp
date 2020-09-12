#include <bits/stdc++.h>
using namespace std;
 subsequence(int a[], int n)
 {
     vector<int>count(n,1);
     
     for(int i=1; i<n; i++)
     {
         for(int j=0; j<i; j++)
         {
             if(a[i] >= a[j] && count[i] <= count[j])
                count[i] = count[j] + 1;
               
         }
     }
     cout<<*max_element(count.begin(), count.end());
     
     
 }
int main()
{
    int a[] = {5,8,7,1,9};
    int n = sizeof(a)/sizeof(a[0]);
    subsequence(a,n);
}