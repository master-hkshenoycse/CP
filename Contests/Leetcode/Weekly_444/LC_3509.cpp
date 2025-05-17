#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxProduct(vector<int>& nums, int k, int limit) {
            int n=nums.size();
            
            if(abs(k) > n*12){
                return -1;
            }
    
            set<pair<int,int> > s1,s0;
            s0.insert({0,1});
    
            int ans=-1;
            
            for(auto e:nums){
                set < pair<int,int> > t1,t0;
    
                for(auto [s,p] : s0){
                    int nx_s = s + e;
                    int nx_p = min(limit+1,p*e);
    
                    if(nx_s == k && nx_p <= limit){
                        ans = max(ans,nx_p);
                    }
                    
                    t1.insert({nx_s,nx_p});   
                }
    
                for(auto [s,p] : s1){
                    int nx_s = s - e;
                    int nx_p = min(limit+1,p*e);
    
                    if(nx_s == k && nx_p <= limit){
                        ans = max(ans,nx_p);
                    }
    
                    t0.insert({nx_s,nx_p});
                }
    
                for(auto [s,p] : t1){
                    s1.insert({s,p});
                }
    
                for(auto [s,p] : t0){
                    s0.insert({s,p});
                }
            }
    
            return ans;
        
        }
    };