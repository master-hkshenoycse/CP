#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        ll ans=-1e18;
        
        
        
        ll n=board.size(),m=board[0].size();
        vector<pair<ll,ll> > best_cols[n];
        
        for(ll i=0;i<n;i++){
            
            for(ll j=0;j<m;j++){
                best_cols[i].push_back({board[i][j],j});
            }
            sort(best_cols[i].begin(),best_cols[i].end());
            reverse(best_cols[i].begin(),best_cols[i].end());
            
            while(best_cols[i].size()>5){
                best_cols[i].pop_back();
            }
            
        }
        
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                for(ll k=j+1;k<n;k++){
                    
                    
                    for(auto c1:best_cols[i]){
                        for(auto c2:best_cols[j]){
                            for(auto c3:best_cols[k]){
                                
                                if(c1.second!=c2.second and c1.second!=c3.second and c2.second!=c3.second){
                                    ans=max(ans,c1.first+c2.first+c3.first);
                                }
                                
                            }
                        }
                    }
                    
                    
                }
            }
        }
        
        return ans;
    }
};