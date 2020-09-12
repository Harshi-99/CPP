#include<string.h>
#include<iostream>
#include<vector>

using namespace std;
void substring(string s1, string s2)
{
    int match[s1.length()][s2.length()] ; 
    int m = s1.length();
    int n = s2.length();
    vector<string> result;
    result.push_back("");
    int max = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(s1[i]==s2[j])
            {
                if(i == 0 || j == 0)
                   match[i][j] = 1;
                else
                
                    match[i][j] = match[i-1][j-1] + 1;
                
                if(match[i][j] > max)
                {
                    max = match[i][j];
                    result.pop_back();
                    result.push_back(s1.substr(i-max+1,i));
                } 
                else if(match[i][j] == max){
                    result.pop_back();
                    result.push_back(s1.substr(i-max+1, i));}
            }
            else
            {
                match[i][j] = 0;
            }
            
        }
    }
    for(string str: result)
	{
	    cout<<str;
	}
}
int main()
{
    string s1 = "ABCDGH";
    string s2 = "ACDGHRACDGH";
    substring(s1,s2);
}