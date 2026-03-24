#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
   int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack< pair<int,int> >s;
        vector<int> pr_l(n,-1),nx_r(n,n);
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            while(s.size() and s.top().first >= heights[i])s.pop();
            
            if( s.size() ) pr_l[i]=s.top().second;
            
            ans=max(ans,(i-pr_l[i])*heights[i]);
            
            s.push({heights[i],i});
            
        }
        while(s.size())s.pop();
        for(int i=n-1;i>=0;i--){
            while(s.size() and s.top().first >= heights[i])s.pop();
            
            if( s.size() )nx_r[i]=s.top().second;
            
            ans=max(ans,(nx_r[i]-i)*heights[i]);
            ans=max(ans,(nx_r[i]-pr_l[i]-1)*heights[i]);
            
            s.push({heights[i],i});
        }
        return ans;
        
    }
    
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0) return 0;
        
        int m=matrix[0].size();
        if(m==0) return 0;

        vector< vector<int> > c_heights(n, vector<int> (m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               int v=matrix[i][j];
               if(i==0)c_heights[i][j]=v;
               else c_heights[i][j]=c_heights[i-1][j]*v+v;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> h(m,0);
            for(int j=0;j<m;j++) h[j]=c_heights[i][j];
           sort(h.begin(),h.end());
            ans=max(ans,largestRectangleArea(h));
        }
        
        return ans;    
    }
};