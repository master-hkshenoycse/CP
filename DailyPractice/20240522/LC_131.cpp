#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string> > sol;
    bool isp(string &s){
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i] != s[n-i-1])return 0;
        }
        return 1;
    }
    void rec(int ind,string &s,vector<string> &v){
        if(ind==s.size()){
            sol.push_back(v);
            return;
        }
        
        for(int j=ind;j<s.size();j++){
            string y=s.substr(ind,j-ind+1);
            
            if(isp(y)){
                v.push_back(y);
                rec(j+1,s,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        rec(0,s,v);
        return sol;
        
    }
};