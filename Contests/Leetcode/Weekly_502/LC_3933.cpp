#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int csum[205][205][205];
    void pre_cum(int val,vector<vector<int> > &matrix){
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                csum[val][i][j]=(matrix[i][j]>=val);
                if(i-1>=0)
                    csum[val][i][j]+=csum[val][i-1][j];
                if(j-1>=0)
                    csum[val][i][j]+=csum[val][i][j-1];
                if(i-1>=0 && j-1>=0)
                    csum[val][i][j]-=csum[val][i-1][j-1];
            }
        }
    }

    int get_sum(int val,int x1,int y1,int x2,int y2,int n,int m){
        
        int ret=0;
        if(x2>=0 && y2>=0 && x2<n && y2<m)
            ret+=csum[val][x2][y2];
        
        if(x2>=0 && y1-1>=0 && x2<n && y1-1<m)
            ret-=csum[val][x2][y1-1];
        
        if(x1-1>=0 && y2>=0 && x1-1<n && y2<m)
            ret-=csum[val][x1-1][y2];
        
        if(x1-1>=0 && y1-1>=0 && x1-1<n && y1-1<m)
            ret+=csum[val][x1-1][y1-1];

        return ret;
    }
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();

    
        for(int val=1;val<=200;val++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    csum[val][i][j]=0;
                }
            }
            pre_cum(val,matrix);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int x=matrix[i][j];
                if(x==0)
                    continue;

                int lo_i=max(i-x,0);
                int hi_i=min(i+x,n-1);
                int lo_j=max(j-x,0);
                int hi_j=min(j+x,m-1);
                int cnt_gt=get_sum(x+1,lo_i,lo_j,hi_i,hi_j,n,m);
                
                if(i-x>=0 && j-x>=0)
                    cnt_gt-=(matrix[i-x][j-x]>x);
                
                if(i-x>=0 && j+x<m)
                    cnt_gt-=(matrix[i-x][j+x]>x);

                if(i+x<n && j-x>=0)
                    cnt_gt-=(matrix[i+x][j-x]>x);
                
                if(i+x<n && j+x<m)
                    cnt_gt-=(matrix[i+x][j+x]>x);

                if(cnt_gt==0)
                    ans++;

            }
        }

        return ans;
    }
};