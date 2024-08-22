#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > dp;
    int solve(int current,int copy,int n){
        //cout<<current<<" "<<copy<<endl;
        if(current==n){
            return 0;
        }

        if(dp[current][copy] != -1){
            return dp[current][copy];
        }

        int res=n+1;

        //paste current copy available
        if(current+copy<=n and copy>0){
            res=min(res,1+solve(current+copy,copy,n));
        }

        if(copy<current)res=min(res,1+solve(current,current,n));

        return dp[current][copy]=res;



    }
    int minSteps(int n) {
        dp.resize(n+1,vector<int> (n+1,-1));

        return solve(1,0,n);
    }
};