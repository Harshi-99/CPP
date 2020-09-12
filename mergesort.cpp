#include<iostream>
using namespace std;
void Merge(int* left,int len_left, int* right,int len_right, int* a,int n)
{
    int i=0,j=0,k=0;
    while(i<len_left && j<len_right)
    {
        if(left[i] < right[j])
        {
            a[k] = left[i];
            k = k+1;
            i = i+1;
        }
        else
        {
            a[k] = right[j];
            k = k+1;
            j = j+1;
        }
    }
    while(i<len_left)
    {
        a[k] = left[i];
        i = i+1;
        k = k+1;
    }
    while(j<len_right)
    {
        a[k] = right[j];
        j = j+1;
        k = k+1;
    }
    
    
    
}

void MergeSort(int* a, int n)
{   
    int mid;
    if(n<2) return;
    mid = n/2;
    int left[mid], right[n-mid];
    for(int i=0; i<mid; i++)
        left[i] = a[i];
    for(int i=mid; i<n; i++)
       right[i-mid] = a[i];
    MergeSort(left,mid);
    MergeSort(right,n-mid);
    Merge(left,mid,right,n-mid,a,n);    

}

int main()
{
    int a[] = {2,4,1,6,8,5,3,7};
    int n = sizeof(a)/sizeof(a[0]);
    MergeSort(a,n);
   
    for(int i=0; i<n; i++)
    {
        cout<<a[i];
    }
     return 0;
    
}