#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        
        vector< int > dp(k+1,0);
        unordered_map<int,unordered_map<int,int> > help;
        
        int ans=0;
        
        for(int i=1;i<=n;i++){
            
            int val=nums[i-1];
            vector<int> eq(k+1,0);
            for(int j=0;j<=k;j++){
                
                if(help.count(val) >0 and help[val].count(j)>0){
                    eq[j]=max(eq[j],help[val][j]+1);
                }
                
                if(j+1<=k){
                    eq[j+1]=max(eq[j+1],dp[j]+1);
                }
                
                
                
                
                    
            }
            
            eq[0]=max(eq[0],1);
            
            for(int j=1;j<=k;j++){
                eq[j]=max(eq[j],eq[j-1]);
            }
            
            
            for(int j=0;j<=k;j++){
                
                if(j==0 or eq[j] != eq[j-1]){
                    help[val][j]=max(help[val][j],eq[j]);
                }
                
                ans=max(ans,eq[j]);
                
                
                dp[j]=max(dp[j],eq[j]);
                
                
                
                
            }
        
        }
        //cout<<endl;
        
        return ans;
    }
};