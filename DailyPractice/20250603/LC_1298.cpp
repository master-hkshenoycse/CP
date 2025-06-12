#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
            int n = status.size();
            vector<int> key_available(n,0),box_available(n,0);
            queue<int> q;
            for(auto i:initialBoxes){
                box_available[i]=1;
                if(status[i]==1){
                    q.push(i);
                }
            }
            for(int i=0;i<n;i++){
    
                key_available[i]=status[i];
                status[i]=0;
            }
    
            while(q.size()>0){
                int sz=q.size();
                
                for(int i=0;i<sz;i++){
                    int b = q.front();
                    q.pop();
                    
                    for(auto k:keys[b]){
                        key_available[k]=1;
                    }
    
                    for(auto cb:containedBoxes[b]){
                        box_available[cb]=1;
                    }
                }
    
                for(int i=0;i<n;i++){
                    if(status[i]==0 && box_available[i]==1 && key_available[i]==1){
                        status[i]=1;
                        q.push(i);
                    }
                }
            }
    
            int ans=0;
            for(int i=0;i<n;i++){
                if(status[i]==1){
                    ans=ans+candies[i];
                }
            }
    
            return ans;
        }
    };