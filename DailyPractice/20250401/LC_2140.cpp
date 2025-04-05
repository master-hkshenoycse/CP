#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll dp[200005];
    
    ll solve(ll n,vector<vector<int> >&questions){
        if(n>=questions.size()){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        ll res=0;
        res=max(res,(ll)questions[n][0]+solve(n+questions[n][1]+1,questions));
        res=max(res,solve(n+1,questions));

        return dp[n]=res;

    }
    long long mostPoints(vector<vector<int>>& questions) {
        ll n=questions.size();
        for(ll i=0;i<=n;i++){
            dp[i]=-1;
        }

        return solve(0,questions);

    
    }
};