#include<bits/stdc++.h>
using namespace std;
void reverseLetter(string s)
{
    stack<char> rev;
    for(int i=0; i<s.length(); i++)
    {
        rev.push(s[i]);

    }
    while(!rev.empty())
    {
        cout<<rev.top();
        rev.pop();
    }
}
void reverseWord(string s)
{
    stack<string>st;
    string temp;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == ' ')
        {
            temp+=' ';
            
            st.push(temp);
            temp.clear();
        }
        else
        {   
                
            temp +=s[i];
        }
           
    }
    temp +=' ';
    st.push(temp);
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}
int main()
{
    string s = "I Love Programming Very much";
    reverseWord(s);
    cout<<"\n";
    reverseLetter(s);
    return 0;
}