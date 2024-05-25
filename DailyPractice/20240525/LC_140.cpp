#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string,int>  help;
    vector<string> sol;
    void rec(int ind,string &s,vector<string> &curr,vector<string> &sol){
        if(ind==s.size()){
            string tmp;
            for(int i=0;i<curr.size();i++){
                tmp+=curr[i];
                if(i+1<curr.size()){
                    tmp+=' ';
                }
            }
            sol.push_back(tmp);
            return;
        }
        
        
        string y;
        for(int i=ind;i<s.size();i++){
            y+=s[i];
            if(help.find(y) != help.end()){
                curr.push_back(y);
                rec(i+1,s,curr,sol);
                curr.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        sol.clear();
        for(auto s:wordDict){
            help[s]=1;
        }
        vector<string> curr;
        rec(0,s,curr,sol);
        return sol;
    }
};