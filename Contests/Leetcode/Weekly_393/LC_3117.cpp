#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector< unordered_map<int,int> > > dp;
    int solve(int ind,int indAnd,vector<int> &nums,vector<int> &andValues,int currAnd){
        if(ind==nums.size()){
            if(indAnd==andValues.size()){
                return 0;
            }else{
                return 1e8;
            }
        }

        if(indAnd==andValues.size()){
            return 1e8;
        }

        if(dp[ind][indAnd].count(currAnd)>0){
            return dp[ind][indAnd][currAnd];
        }

        int incl=1e8;//make this index a endpoint 
        if((currAnd&nums[ind])==andValues[indAnd]){
            incl=nums[ind]+solve(ind+1,indAnd+1,nums,andValues,(1<<17)-1);
        }

        int excl=solve(ind+1,indAnd,nums,andValues,(currAnd & nums[ind]));

        return dp[ind][indAnd][currAnd]=min(incl,excl);
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        
        int n=nums.size(),m=andValues.size();
        
        dp.resize(n,vector<unordered_map<int,int> > (m));
        
        int ans=solve(0,0,nums,andValues,(1<<17)-1);
        
        if(ans==1e8){
            ans=-1;
        }

        return ans;
    }
};