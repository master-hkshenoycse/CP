#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string get_add_one(string &s){
        
        string sol;
        string other="1";
        int c=0,i=0,n=s.size(),m=other.size();
        reverse(s.begin(),s.end());

        while(i<n or i<m){
            int v1=0,v2=0;
            if(i<n){
                v1=s[i]-'0';
            }

            if(i<m){
                v2=other[i]-'0';
            }

            int v=(v1+v2+c)%2;
            c=(v1+v2+c)/2;

            sol+=char('0'+v);
            i++;
        }

        if(c>0){
            sol+=char('0'+c);
        }

        reverse(sol.begin(),sol.end());

        return sol;
        
    }
    int numSteps(string s) {
        int ans=0;
        while(s.size()>1){
            ans++;
            if(s.back()=='0'){
                s.pop_back();
            }else{
                s=get_add_one(s);
            }
        }
        return ans;        
    }
};