#include<iostream>
using namespace std;
void kadanesAlgorithm(int array[], int n)
{
    int maxEndingHere = array[0];
    int maxSoFar = array[0];
    for(int i = 1; i<n; i++)
    {
        maxEndingHere = max(array[i],(array[i]+maxEndingHere));
        maxSoFar = max(maxEndingHere , maxSoFar);

    }
    cout<<maxSoFar;
}
int main()
{
    int n, element;
    cout<<"Enter the number of elements";
    cin>>n;
    cout<<"enter n elements";
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>element;
        arr[i] = element;
    }
    kadanesAlgorithm(arr, n);
    return 0;
}