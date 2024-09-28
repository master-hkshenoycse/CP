#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve_dp(int ind,vector<int> &dp,set<string> &d,string &s){
        if(ind==s.size()){
            return 0;
        }

        if(dp[ind] !=-1){
            return dp[ind];
        }

        int res=1+solve_dp(ind+1,dp,d,s);

        string tmp;
        for(int i=ind;i<s.size();i++){
            tmp+=s[i];
            if(d.find(tmp) != d.end()){
                res=min(res,solve_dp(i+1,dp,d,s));
            }else{
                res=min(res,(i-ind+1)+solve_dp(i+1,dp,d,s));
            }
        }

        return dp[ind]=res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> d;
        for(auto s:dictionary){
            d.insert(s);
        }

        int n=s.size();
        vector<int> dp(n,-1);

        return solve_dp(0,dp,d,s);
    }
};