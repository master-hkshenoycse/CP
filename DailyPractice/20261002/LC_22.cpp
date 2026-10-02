#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lim;
    vector<string> sol;
    string s;
    
    void rec(int ind,int op,int cl,int n){
        if(ind==lim){
            sol.push_back(s);
            return;
        }
        if(op==cl){
            s[ind]='(';
            rec(ind+1,op+1,cl,n);
        }else{
            if(cl<n){
                s[ind]=')';
                rec(ind+1,op,cl+1,n);    
            }
            
            if(op<n){
               s[ind]='(';
               rec(ind+1,op+1,cl,n);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        lim=2*n;
        
        for(int i=0;i<2*n;i++)s+='(';
        rec(0,0,0,n);
        
        return sol;
        
        
    }
};