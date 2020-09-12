#include<iostream>
using namespace std;
int subArray(int a[], int n, int total)
{
    int left=0, right=0;
    int sum = 0;

    while(right != n)
    {
        if(sum < total)
        {
            sum += a[right];
            right ++;
        }
        else
        {
            sum -= a[left];
            left ++;
        }
        if(sum == total)
        {
            sum = 0;
            while(left!=right)
            {
                cout<<a[left]<<" ";
                left++;
            }
        }
        else
        {
            continue;
        }
        
    }
}
int main()
{
    int a[] = {1,4,20,3,10,5,33};
    int lengthOfArray = sizeof(a)/sizeof(a[0]);
    subArray(a,lengthOfArray,33);
    return 0;
}