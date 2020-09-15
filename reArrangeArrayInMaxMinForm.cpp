#include<bits/stdc++.h>
using namespace std;
void rearrangeArrayInMaxMinForm(int inputArray[], int size)
{
    int resultantArray[size];
    int left, right;
    left = 0; right = size-1;
    int i = 0;
    while(left <= right)
    {
        resultantArray[i] = inputArray[right];
        resultantArray[++i] = inputArray[left];
        
        i++;
        left++;
        right--;
    }
    for(int j = 0; j<size; j++)
    {
        cout<<resultantArray[j]<<" ";
    }
} 
int main()
{
    int inputArray[] = {1,2,3,4,5,6,7};
    int size = sizeof(inputArray)/sizeof(inputArray[0]);
    rearrangeArrayInMaxMinForm(inputArray, size);
     return 0;
}