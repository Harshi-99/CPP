#include<bits/stdc++.h>
using namespace std;
void printSumOfStrings(string s, int len)
{
    string temp = "";
    int sum = 0;
    for(char ch: s)
    {
        if(isdigit(ch))
            temp += ch;
        else
        {
            sum += atoi(temp.c_str());
            temp = "";
        }
        
    }
    cout<<sum+ atoi(temp.c_str());
}
int main()
{
    string s = "ge26eks4geeks11";
    int len = s.length();
    printSumOfStrings(s, len);
    return 0;
}