#include<bits/stdc++.h>
using namespace std;
void bfs(int i, int x)
{
    queue<int> q;
    int num;
    int unitDigit;
    q.push(i);
    while(!q.empty())
    {
        num = q.front();
        q.pop();
        if(num <= x)
        {
            cout<<num<<" ";
            unitDigit = num % 10;
            
            if(unitDigit == 0)
            {
                q.push((num*10)+(unitDigit+1));
            }
            if(unitDigit == 9)
            {
                q.push((num * 10)+(unitDigit-1));
            }
            else
            {
                q.push((num*10)+(unitDigit+1));
                q.push((num * 10)+(unitDigit-1));
            }
        }

    
    }
}
void printNumber(int x)
{
    cout<<0;
    for(int i=1; i<=9; i++)
        bfs(i,x);
    
    
}
int main()
{
    int x = 40;
    printNumber(x);

    return 0;
}
