#include <bits/stdc++.h>
using namespace std;
void print(string s, int start, int n)
{
    for(int i = start; i<=n; i++)
        cout<<s[i];
}
void printlongestPalindrome(string s)
{
    int start = 0;
    int maxLength = 1;
    int n = s.length();
    int low, high;
    for(int i = 1; i<n; ++i)
    {
        low = i-1; high = i;
        while(low >= 0 && high < n && s[low] == s[high])
        {
            if(high - low + 1 > maxLength)
            {
                maxLength = high - low + 1;
                start = low;
            }
            --low;
            ++high;
        }

        low = i-1; high = i+1;
        while(low >= 0 && high < n && s[low] == s[high])
        {
            if(high + low - 1 > maxLength)
            {
                maxLength = high - low +1;
                start = low;
            }
            --low;
            ++high;
        }
        
    }
   
    print(s, start, ( start + maxLength  - 1));
    cout<<"\n"<<maxLength;
}
int minimumInsertionOnLeftToPalindrome(string s, int n)
{
    int l = 0, h = n-1, counta = 0;
    while(l<h) 
    {
        if(s[l] == s[h])
        {
            l++; h--;
        }
        else
        {
            counta++;
            h--;
        }
        
    }
    return counta;
}
int minimumInsertionToformPalindrom(string s, int n)
{
    int table[n][n], l,h,gap;
    memset(table,0,sizeof(table));
    for(int gap=1; gap<n; gap++)
    {
        for(int l=0,h=gap; h<n; ++l,++h)
        {
            table[l][h]  = (s[l] == s[h]) ?
             table[l+1][h-1]:(min(table[l][h-1],table[l+1][h])+1);
        }
    }
    return table[0][n-1];
}
int formlongestPalindromicString(string s, int n)
{
    int palindromeLength = 0;
    int oddCount = 0;
    map<char,int> a;
    for(int i=0; i<n; i++)
    {
        a[s[i]] += 1;
    }
    for(auto ele: a)
    {
        if(ele.second % 2 == 0)
            palindromeLength += ele.second;
        else
        {
            oddCount ++;
            palindromeLength += (ele.second - 1);
        }
    }
    if(oddCount)
        return palindromeLength+1;
    else
        return palindromeLength;

}
int main()
{
    string input = "forgeeksskeegfor";
    //string input2 = "hbjeausdwetcoigruoczwvlfxjvygtpnuatvulatsuxie";
    string input2 = "btblaiwvtopwcqolwjgsdizwjodrtabuveivmeqhuhdwy";
    //string input2 = "afpntkqvdkgfwoctxsmcjrmtpuvqliflqvajhrenbksyawryqfczwoulksewcljsgkcqbidevxcvvtvlaanzqhmbbqzeckwkuacxjfceegbzcznczabpjosletriepvaqxabfcfjkilmjypiaqajeuwlonvsdqsvqswvwdgjltvvrkfrdhdhczuqnskqkenazjxxmegzzcwrockrlnbnnvfcpruawhaxqyueebddfawtejlpwmfljmnzehzcobzgbtkhwqnbqlvwuilrwseffsgjbhlsjmymflucbjdruappiaievmmaeulicyankabrlvvmezfzbuqmxyqukeurzhzdhbstbtknrgbxhjykfowempyzvuqubrzkstdtpqigymfhverauohjffiaaaxdryolstehjppjbwqyciaxyhifnqfpscsjbiuvcaenrvxurnsuxvtxebcrtkilmbupjqknsqbmlagdpbznwsmavruobcznfvfrnrefifrtfawvbxkxpyzkptaqyzgdulujcbpkgigoiellcxitvkgnfgddgljcydodedpnnvdyaqjcpuvkebzlkdpsqyupdisknhzddcdduohjievoivasarkqrgfurzeghdlmhorddymneiemfgefxqxoxdiqepwluixeyqhbqwpvgvjlbqqygnofsyvxnskkckoaaxertvozqxmrnepusfbmdxlrrwdvitvkqzbmwrnmpadceuyyzaldzywqwznesipkksygkmvbmyfsvgruiezhevzbwmhqwybirbrdnmgbklwfrncztbixzhavviosgpazsregfkjqwfxpubppfxpehpbczpwigxhzqohwyqowwnmqrdiwcxajmdootkwbjfacthauyoqwdcoufwqktstiyhwtusudxvftefnevdabirxpnqzjivrienbyhwegtlbxtocq";
    string input3 = "java";
    int lengthOfInput3 = input3.length();
    int lengthOfInput = input.length();
    int lengthOfInput2 = input2.length();
    int count = formlongestPalindromicString(input, lengthOfInput);
    int minimumInsertion = minimumInsertionToformPalindrom(input2, lengthOfInput2);
    int a = minimumInsertionOnLeftToPalindrome(input3, lengthOfInput3);
    cout<<a<<"\n";
    cout<<count<<"\n";
    cout<<minimumInsertion<<"\n";
    string s = "forgeeksskeegfor";
    printlongestPalindrome(s);
}
