#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int n,l;
        vector< vector<int> > dp;
        vector< vector<int> > memo;
        vector< vector<int> > jobs;
        vector<int> jb_st;
        
        int solve(int c_j,int lef){
            if(c_j>=n)return 0;
            if(lef==0)return 0;
            if(memo[c_j][lef])return dp[c_j][lef];
            
            memo[c_j][lef]=1;
            int res=INT_MIN;
            
            //skip job
            res=solve(c_j+1,lef);
            
            // find next  suitable job
            int en_time=jobs[c_j][1];
            int w=jobs[c_j][2];
            
            
            int ind=upper_bound(jb_st.begin(),jb_st.end(),en_time)-jb_st.begin();
            
            
            if(lef)res=max(res,w+solve(ind,lef-1));
            return dp[c_j][lef]=res;
        }
        int maxValue(vector<vector<int>>& events, int k) {
            n=events.size();
            l=k;
            jobs=events;
            
            vector<vector<int> >tmp1(n+1,vector<int> (k+1,0));
            vector<vector<int> >tmp2(n+1,vector<int> (k+1,0));
            
            dp=tmp1;
            memo=tmp2;
            
            sort(jobs.begin(),jobs.end());
            jb_st.resize(n);
            for(int i=0;i<n;i++)jb_st[i]=jobs[i][0];
                    
            return solve(0,k);
            
    
            
            
            
            
        }
    };