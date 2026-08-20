#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int> >grid(n,vector<int> (m,-1));
        sort(sources.begin(),sources.end(),[](vector<int> &a,vector<int> &b){
                return a[2]>b[2];
            });

        for(auto s:sources){
            int v=s[2];
            int x=s[0];
            int y=s[1];

            if(grid[x][y] == -1)
                grid[x][y]=v;
        }
        
        while(sources.size()>0){
            vector<vector<int> > curr_order;
            for(auto s:sources){
                int v=s[2];
                int x=s[0];
                int y=s[1];
                if(grid[x][y]==v){
                    for(int i=0;i<4;i++){
                        int nx=x+dx[i];
                        int ny=y+dy[i];
                        if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==-1){
                            curr_order.push_back({nx,ny,v});
                            grid[nx][ny]=v;
                        }
                    }
                }
            }
            sources=curr_order;
        }

        return grid;
    }
};