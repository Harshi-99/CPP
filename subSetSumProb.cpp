#include<bits/stdc++.h>
using namespace std;
int subSetSumOfBitwiseOr(int a[], int len)
{
    int arr[len]; 
    for(int i=1; i<=len; i++)
        arr[i] = a[i-1];
    int max = 0;
    int subSet[len][len];
    for(int i=0; i<len; i++)
    {
        subSet[0][i] = 0;
        subSet[i][0] = 0;
    }
    for(int i = 2; i < len; i++)
    {
        for(int j=1; j < i; j++)
        {
            if(arr[i] + arr[j] > max)
            {
                subSet[j][i] = subSet[j-1][i-1] + 1;
                max = arr[i] + arr[j];
                cout<<arr[j]<<" "<<arr[i];
            }
        
        }
    cout<<"\n";
    }
    return subSet[len][len];
}
int main()
{
    int arr[] = {5,1,3,4,2};
    int len = sizeof(arr)/sizeof(arr[0]);
    int sizeOfArray = subSetSumOfBitwiseOr(arr, len);
    cout<<sizeOfArray;
    return 0;
}