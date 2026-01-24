#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_sum(int x1,int y1,int x2,int y2,vector<vector<int> >&csum){
        return csum[x2][y2]-csum[x2][y1-1]-csum[x1-1][y2]+csum[x1-1][y1-1];
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int> > csum(n+1,vector<int> (m+1,0));
        //csum matrix stores sum of rectangle from (1,1) to (i,j);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                csum[i][j]=csum[i-1][j]+csum[i][j-1]-csum[i-1][j-1]+mat[i-1][j-1];                
            }
        }

        int lo=1,hi=min(n,m),ans=0;

        while(hi>=lo){
            int mid=(hi+lo)/2ll;
            int f=0;
            for(int i=1;i<=n-mid+1;i++){
                for(int j=1;j<=m-mid+1;j++){
                    if(get_sum(i,j,i+mid-1,j+mid-1,csum)<=threshold){
                        f=1;
                        break;
                    }
                }
                if(f==1){
                    break;
                }
            }

            if(f){
                ans=max(ans,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

        return ans;


    }
};