#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int in_time[1005],out_time[1005],sub_xor[1005];
        int tim=0;
        vector<int> adj[1005];
        void dfs(int v,vector<int> &nums,int p){
            in_time[v]=tim++;
            sub_xor[v]=nums[v];
            
            for(auto to:adj[v]){
                
                if(to==p)continue;
                
                dfs(to,nums,v);
                sub_xor[v]=(sub_xor[v] ^ sub_xor[to]);
            }
            
            out_time[v]=tim++;
        }
        
        
        //is x ancestor of y
        bool is_anc(int x,int y){
            if(in_time[x]<= in_time[y] and out_time[y]<=out_time[x]){
                return 1;
            }
            return 0;
        }
        
        int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
            tim=0;
            
            for(auto e:edges){
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }
            
            int n=nums.size();
            
            dfs(0,nums,-1);
            int ans=INT_MAX;
            
            for(int i=1;i<n;i++){
                for(int j=i+1;j<n;j++){
                    
                    int c1=sub_xor[i];
                    int c2=sub_xor[j];
                    int c3=(sub_xor[0] ^ c1 ^ c2);
                    
                    if(is_anc(i,j)){
                        c3=(c3 ^ c2);
                        c1=(c1 ^ c2);
    
                    }else if(is_anc(j,i)){
                        c3=(c3 ^ c1);
                        c2=(c2 ^ c1);
                    }
                    
                    //cout<<i<<" "<<j<<" "<<c1<<" "<<c2<<" "<<c3<<endl;
                    
                    
                    ans=min(ans,max(c1,max(c2,c3))-min(c1,min(c2,c3)));
                    
                    
                }
            }
            
            return ans;
            
        }
    };