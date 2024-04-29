#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        ll n=grid.size(),m=grid[0].size();

        vector<ll> col_cnt(m,0);

        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                col_cnt[j]+=grid[i][j];
            }
        }

        ll ans=0;

        for(ll i=0;i<n;i++){
            ll suffix_cnt=0,prefix_cnt=0;
            for(ll j=0;j<m;j++){    
                if(grid[i][j]==1){
                    ans=ans+(col_cnt[j]-1)*prefix_cnt;
                }
                prefix_cnt+=grid[i][j];
            }

            for(ll j=m-1;j>=0;j--){    
                if(grid[i][j]==1){
                    ans=ans+(col_cnt[j]-1)*suffix_cnt;
                }
                suffix_cnt+=grid[i][j];
            }
        }

        return ans;
    }
};