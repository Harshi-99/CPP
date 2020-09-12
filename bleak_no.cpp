#include<iostream>
int countbits(int num)
{
    int count = 0;
    int d;
    int num1 = num;
    while(num){
    d = num % 2;
    num = num/2;
    if(d==1 || num==1)
        count++;
    }
    return count;
}
int main()
{
    int num = 7;
    
    for (int i=1; i<num; i++)
        if(i+countbits(i)==num)
        {
            printf("false");
            return 0;
        }
        
printf("true");
        

    return 0;
}