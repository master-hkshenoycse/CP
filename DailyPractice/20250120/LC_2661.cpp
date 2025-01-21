#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        int n=mat.size(),m=mat[0].size();
        int lo=0,hi=n*m-1,ans=n*m-1;
        vector<vector<int> > color(n,vector<int> (m,0));
        vector<pair<int,int> > pos(n*m+1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pos[mat[i][j]]={i,j};
            }
        }
        
        
        
        
        while(hi>=lo){
            int mid=(hi+lo)/2;
                
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    color[i][j]=0;
                }
            }
            
            for(int i=0;i<=mid;i++){
                color[pos[arr[i]].first][pos[arr[i]].second]=1;
            }
            
            int f=0;
            for(int i=0;i<n;i++){
                int c=0;
                for(int j=0;j<m;j++){
                    c=c+color[i][j];
                }
                
                if(c==m){
                    f=1;
                }
                
                if(f){
                    break;
                }
            }
            
            for(int j=0;j<m;j++){
                int c=0;
                for(int i=0;i<n;i++){
                    c=c+color[i][j];
                }
                
                if(c==n){
                    f=1;
                }
                
                if(f){
                    break;
                }
            }
                
            
            if(f){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        
        return ans;
    }
};