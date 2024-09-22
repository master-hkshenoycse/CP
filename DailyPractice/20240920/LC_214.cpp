
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s) {
        string tmp=s;
        reverse(tmp.begin(),tmp.end());
        
        string t=s+'$'+tmp;
        int n=s.size();
        int m=t.size();
        vector<int> lps(m,0);

        int i=1,len=0;
        while(i<m){
            if(t[len]==t[i]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len==0){
                    lps[i]=0;
                    i++;
                }else{
                    len=lps[len-1];
                }
            }
        }

        len=lps[m-1];
        string sol=s.substr(len);
        reverse(sol.begin(),sol.end());
        sol+=s;

        return sol;


    }
};