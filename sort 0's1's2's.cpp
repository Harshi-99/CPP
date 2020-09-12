#include<iostream>
void sortArray(int a[], int n)
{
    int temp;
    int i = 0, j = n-1;
    wile(i < j)
    {
        if(a[i] > a[j])
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
        else if(a[j] > a[i])
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
    }
    for(int i=0; i<n; i++)
        cout<<a[i];
}
int main()
{
    int a[] = {0,2,1,2,0};
    int n = size(a)/size(a[0]);
    sortArray(a,n);

    return  0;
}