#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        
        int m=chars.size();
        vector<int> cost(26);
        for(int i=0;i<26;i++){
            cost[i]=i+1;
        }
        for(int i=0;i<m;i++){
            cost[chars[i]-'a']=vals[i];
        }


        int ans=0,cs=0;
        for(auto ch:s){
            cs=max(cs+cost[ch-'a'],cost[ch-'a']);
            ans=max(ans,cs);
        }
        return ans;
            
    }
};