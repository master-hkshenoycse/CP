#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans=0;
    void rec(int ind,string &s,set<string> &curr){
        if(ind==s.size()){
            ans=max(ans,(int)curr.size());
        }
        
        int n=s.size();
        string tmp;
        for(int i=ind;i<n;i++){
            tmp+=s[i];
            if(curr.find(tmp)==curr.end()){
                curr.insert(tmp);
                rec(i+1,s,curr);
                curr.erase(tmp);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        set<string> curr;
        ans=0;
        rec(0,s,curr);
        return ans;
    }
};