#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    
    
        int rec(int ind,vector<int> &curr,vector<int> &vis,int n){
    
            if(ind==curr.size()){
                for(int i=1;i<=n;i++){
                    if(vis[i]==0){
                        return 0;
                    }
                }
    
                return 1;
            }
    
            if(curr[ind]!=-1){
                return rec(ind+1,curr,vis,n);
            }
    
            for(int i=n;i>=1;i--){
                if(vis[i]==0){
                    if(i==1){
                        curr[ind]=1;
                        vis[i]=1;
    
                        if(rec(ind+1,curr,vis,n)){
                            return 1;
                        }   
    
                        curr[ind]=-1;
                        vis[i]=0;
    
                    }else{
                        if(ind+i<curr.size() and curr[ind+i]==-1){
                            curr[ind]=i;
                            curr[ind+i]=i;
                            vis[i]=1;
    
                            if(rec(ind+1,curr,vis,n)){
                                return 1;
                            }
    
                            curr[ind]=-1;
                            curr[ind+i]=-1;
                            vis[i]=0;
                        }
                    }
                }   
            }
    
            return 0;
        }
        vector<int> constructDistancedSequence(int n) {
            vector<int> curr(2*n-1,-1);
            vector<int> vis(n+1,0);
    
            rec(0,curr,vis,n);
    
            return curr;
    
            
        }
    };