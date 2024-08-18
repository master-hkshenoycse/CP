#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        ll ans=-1e18;
        
        
        
        ll n=board.size(),m=board[0].size();
        vector<pair<ll,ll> > best_cols[n];
        set<pair<ll,ll> > cols[m];
        
        for(ll i=0;i<n;i++){
            
            for(ll j=0;j<m;j++){
                best_cols[i].push_back({board[i][j],j});
                cols[j].insert({board[i][j],i});
                
                if(cols[j].size()>3){
                    cols[j].erase(cols[j].begin());
                }
            }
            
            sort(best_cols[i].begin(),best_cols[i].end());
            reverse(best_cols[i].begin(),best_cols[i].end());
            
            while(best_cols[i].size()>2){
                best_cols[i].pop_back();
            }
            
        }
        
        set<vector<ll> > c[3];
        for(int j=0;j<m;j++){
            
            for(int cnt=0;cnt<3;cnt++){
                auto it=*cols[j].begin();
                c[cnt].insert({it.first,it.second,j});
                cols[j].erase(cols[j].begin());
            }
                   
        }
        

        
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                                    
                    
                    for(auto c1:best_cols[i]){
                        for(auto c2:best_cols[j]){
                            
                            if(c1.second != c2.second){
                                
                                
                                for(int k=0;k<3;k++){
                                    
                                    vector<vector<ll> > to_ins_later;
                                    while(c[k].size()>0){
                                        auto it=*(--c[k].end());
                                            
                                        if(it[1]==i or it[1]==j or it[2]==c1.second or it[2]==c2.second){
                                            to_ins_later.push_back(it);
                                            c[k].erase(it);
                                            
                                        }else{
                                            
                                            ans=max(ans,it[0]+c1.first+c2.first);
                                            break;
                                        }
                                    }
                                    
                                    for(auto it:to_ins_later){
                                        c[k].insert(it);
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