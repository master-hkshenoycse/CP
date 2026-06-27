#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int is_sq(int n){
        int sq=sqrt(n);
        if(sq*sq==n){
            return sq;
        }
        return -1;
    }
    int maximumLength(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        map<int,int> help;
        vector<int> uniq;
        for(int i=0;i<n;i++){
            
            if(i==0){
                help[nums[i]]++;
                uniq.push_back(nums[i]);
            }else{
                help[nums[i]]++;
                if(nums[i] != nums[i-1]){
                    uniq.push_back(nums[i]);
                }
            }
        }
        
        int ans=1;

        int sz=uniq.size();
        map<int,int> dp;
        if(help.find(1) != help.end()){
            ans=max(ans,help[1]-(help[1]%2==0));
        }
        
        
        for(int i=0;i<sz;i++){
            
            
            int rt=is_sq(uniq[i]);
            
            
            if(dp.find(rt) != dp.end()){
            
               //cout<<rt<<" "<<dp[rt]<<endl;
               ans=max(ans,dp[rt]+1);
               
               if(help[uniq[i]]>1){
                   dp[uniq[i]]=dp[rt]+2;
               }
                
                
            }else{
                
                if(help[uniq[i]]>1){
                    dp[uniq[i]]=2;
                }
            }
        }
        
        return ans;
        
    }
};