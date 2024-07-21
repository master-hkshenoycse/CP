/*The people in HackerLand are getting ready for a parade. There should be no instance where a person is wearing a white-colored uniform. There is a given string color that contains lowercase English characters (a - z). Some of the positions in the string are empty, meaning that the color of the uniform is white at that position and is denoted by the . character.

A beautiful string is defined as a string in which all characters are the same. For example, "aaa", "zzzzz", "r" are beautiful while "aba", "aaad" are not beautiful. Replace each non-colored uniform with some lowercase English character such that the total number of substrings that are beautiful is maximized.

Find the maximum total number of beautiful substrings after replacing every empty character.

Note: A substring of a string is a contiguous subsequence of that string.

color = ".a.bb."
The optimal filled string is "aabbbb".
The beautiful substrings are {"a", "a", "aa", "b", "b", "b", "b", "bb", "bb", "bb", "bbb", "bbb", "bbbb"}. 
The maximum possible number of beautiful substrings is 13.
color = "p.r."
The optimal string is "prrr". 
The beautiful substrings are {"p", "r", "r", "r", "rr", "rr", "rrr"}
The maximum possible number of beautiful substrings is 7.*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  

    string color;
    cin>>color;

    int n=color.size();

    vector<int> dp(n+1,0);

    for(int i=1;i<=n;i++){
        if(color[i-1]=='.'){
            for(char ch='a';ch<='z';ch++){
                for(int j=i;j>=1;j--){
                    if(color[j-1]==ch or color[j-1]=='.'){
                        int len=i-j+1;
                        dp[i]=max(dp[i],dp[j-1]+(len*len+len)/2);
                    }else{
                        break;
                    }
                }
            }   
        }else{
            for(int j=i;j>=1;j--){
                if(color[i-1]==color[j-1] or color[j-1]=='.'){
                    int len=i-j+1;
                    dp[i]=max(dp[i],dp[j-1]+(len*len+len)/2);
                }else{
                    break;
                }
            }
        }
    }

    cout<<dp[n]<<endl;

}