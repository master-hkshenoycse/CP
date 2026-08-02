#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int> > valid(n,vector<int> (m,1));
        int ans=0;
        for(int b=20;b>=0;b--){
            int ov_cnt=0;
            for(int i=0;i<n;i++){
                int val_cnt=0,cnt=0;
                for(int j=0;j<m;j++){
                    if(valid[i][j]){
                        val_cnt++;
                        if(grid[i][j]&(1<<b)){
                            cnt++;
                        }
                    }
                }
                if(cnt<val_cnt){
                    ov_cnt++;
                }
            }

            if(ov_cnt==n){
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(valid[i][j]==1){
                            if(grid[i][j] & (1<<b)){
                                valid[i][j]=0;
                            }
                        }
                    }
                }
            }else{
                ans=ans+(1<<b);
            }
        }

        return ans;

    }
};