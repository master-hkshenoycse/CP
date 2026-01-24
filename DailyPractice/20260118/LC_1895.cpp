#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int a[55][55];
    int rsum[55][55],csum[55][55],d1_sum[55][55],d2_sum[55][55];
    bool chk(int x,int y,int l){
        
        int x1=x;
        int y1=y;
        int x2=x+l-1;
        int y2=y+l-1;
        int x3=x;
        int y3=y+l-1;
        int x4=x+l-1;
        int y4=y;
        
        set<int> coll;
        for(int i=x;i<=x+l-1;i++){
            coll.insert(rsum[i][y+l-1]-rsum[i][y-1]);
            if(coll.size()>1){
                return 0;
            }
        }
        
        coll.insert(d1_sum[x2][y2]-d1_sum[x-1][y-1]);
        coll.insert(d2_sum[x3][y3]-d2_sum[x4+1][y4-1]);
        
        for(int i=y;i<=y+l-1;i++){
            coll.insert(csum[x+l-1][i]-csum[x-1][i]);
            if(coll.size()>1){
                return 0;
            }
        }
        
        return 1;
        
        
        
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]=grid[i-1][j-1];
                csum[i][j]=csum[i-1][j]+a[i][j];
                rsum[i][j]=rsum[i][j-1]+a[i][j];
                d1_sum[i][j]=d1_sum[i-1][j-1]+a[i][j];
            }
        }
        
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                d2_sum[i][j]=d2_sum[i+1][j-1]+a[i][j];
            }
        }
        
        for(int l=n;l>=1;l--){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    
                    if(i+l-1<=n and j+l-1<=m){
                        if(chk(i,j,l)){
                            return l;
                        }
                    }                    
                }
            }
        }
        
        return 0;
    }
};