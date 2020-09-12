#include<iostream>
#include<map>
using namespace std;
int main()
{
    string s = "geeksforgeeks";
    map<char,int>dup;
    for(int i=0; i<s.length(); i++)
    {
        dup [s[i]] += 1;
    }
    for(auto e: dup)
        if(e.second > 1)
            cout<<e.first<<" "<<e.second<<"\n";

    return 0;
}