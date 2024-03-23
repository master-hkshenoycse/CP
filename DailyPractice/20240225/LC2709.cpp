#include<bits/stdc++.h>
using namespace std;
/*https://leetcode.com/problems/greatest-common-divisor-traversal/description/?envType=daily-question&envId=2024-02-25*/
/*make edges between the factors of number other than 1 and see if all elements are in single component*/ 
class Solution {
public:
    
    vector<int> adj[100005];
    int vis[100005];
    
    void dfs(int v){
        vis[v]=1;
        for(auto to:adj[v]){
            if(vis[to]==0){
                dfs(to);
            }
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int cnt_1=0,n=nums.size();
        
        if(n==1){
            return 1;
        }
        for(int i=0;i<n;i++){
            cnt_1+=(nums[i]==1);
        }
        
        if(cnt_1>0){
            return 0;
        }
        
        for(int i=0;i<n;i++){
            int val=nums[i];
            for(int j=2;j*j<=val;j++){
                if(val%j==0){
                    adj[j].push_back(val);
                    adj[val].push_back(j);
                    
                    if(j != val/j){
                        adj[val/j].push_back(val);
                        adj[val].push_back(val/j);
                    }
                }
            }
        }
        
        dfs(nums.back());
        
        for(int i=0;i<n;i++){
            if(vis[nums[i]]==0){
                return 0;
            }
        }
        
        return 1;
        
        
    }
};