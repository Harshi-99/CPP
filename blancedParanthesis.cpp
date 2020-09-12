#include<bits/stdc++.h> 
#include<stack>
using namespace std;
bool balancedParanthesis(string s, int len)
{
    int count = 0,x;
    std::stack<int>st;
    for(int i=0; i<len; i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
            continue;
        }
            if(st.empty())
                return false;
            switch(s[i])
            {
                case ')': x = st.top();
                            st.pop();
                            if(x == '{' || x == '[')
                                return false;
                            break;   
                case '}': x = st.top();
                            st.pop();
                            if(x == ')' || x == ']')
                                return false;
                            break;
                case ']': x = st.top();
                            st.pop();
                            if(x == ')' || x == ']')
                                return false;
                            break;        
            }
            
        }
        
        
    
   return(st.empty());
}
int main()
{
    string s = "{()}[";
    int len = s.length();
    if(balancedParanthesis(s,len))
    cout<<"balanced";
    else
    {
        cout<<"not balanced";
    }
    
    return 0;
}