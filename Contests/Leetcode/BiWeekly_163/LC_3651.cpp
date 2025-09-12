#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
class Solution {
public:
    void solve(vector<vector<int> >&curr,vector<vector<int> >&grid){
        int n=grid.size(),m=grid[0].size();

        curr[0][0]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0)curr[i][j]=min(curr[i][j],curr[i-1][j]+grid[i][j]);
                if(j>0)curr[i][j]=min(curr[i][j],curr[i][j-1]+grid[i][j]);
            }
        }
    }

    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int> > prev(n, vector<int> (m,INF));
        vector<vector<int> > curr(n, vector<int> (m,INF));

        vector<int> A;
        unordered_map<int,int> MP;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                A.push_back(grid[i][j]);
            }
        }
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(),A.end()),A.end());

        int sz=A.size();
        for(int i=0;i<sz;i++){
            MP[A[i]]=i;
        }


        //DP without teleports
        solve(prev,grid);
        int ans=prev[n-1][m-1];

        for(int t=1;t<=k;t++){
            vector<int> best(sz,INF);
            curr.assign(n,vector<int> (m,INF));

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    best[MP[grid[i][j]]]=min(best[MP[grid[i][j]]],prev[i][j]);
                }
            }

            for(int i=sz-2;i>=0;i--){
                best[i]=min(best[i],best[i+1]);
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    curr[i][j]=min(prev[i][j],best[MP[grid[i][j]]]);
                }
            }

            solve(curr,grid);
            prev.swap(curr);
        }

        return prev[n-1][m-1];
    }
};