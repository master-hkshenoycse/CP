#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve_dp(int src_ind,int pat_ind,string &src,string &pat,vector<int> &mark,vector<vector<int> >&dp){

        if(src_ind==src.size()){
            if(pat_ind==pat.size()){
                return 0;
            }

            return -1e9;
        }

        if(dp[src_ind][pat_ind]!=-1){
            return dp[src_ind][pat_ind];
        }

        int res=-1e9;

        if(pat_ind==pat.size()){
            res=max(res,mark[src_ind]+solve_dp(src_ind+1,pat_ind,src,pat,mark,dp));
        }else{
            res=max(res,solve_dp(src_ind+1,pat_ind+(src[src_ind]==pat[pat_ind]),src,pat,mark,dp));
            if(mark[src_ind]){
                res=max(res,1+solve_dp(src_ind+1,pat_ind,src,pat,mark,dp));
            }
        }


        return dp[src_ind][pat_ind]=res;
    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n=source.size(),m=pattern.size();
        vector<int> mark(n,0);
        for(auto t:targetIndices){
            mark[t]=1;
        }
        vector<vector<int> > dp(n+1,vector<int> (m+1,-1));
        return solve_dp(0,0,source,pattern,mark,dp);
    }
};