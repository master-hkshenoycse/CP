#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<ll,vector<ll> ,greater<ll> > pq;
        ll n=grid.size();
        for(ll i=0;i<n;i++){
            sort(grid[i].begin(),grid[i].end());
            reverse(grid[i].begin(),grid[i].end());
            
            for(ll j=0;j<limits[i];j++){
                pq.push(grid[i][j]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }

        ll ans=0;
        while(pq.size()>0){
            ans=ans+pq.top();
            pq.pop();
        }
 
        return ans;
    }
};