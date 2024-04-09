#include<bits/stdc++.h>
using namespace std;

class Solution{

	public:
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // Your code goes here,
	    vector<vector<int> > dp(m,vector<int> (n,INT_MAX));
	    
	    for(int i=m-1;i>=0;i--){
	        for(int j=n-1;j>=0;j--){
	            if(i==m-1 and j==n-1){
	                if(points[i][j]>0){
	                    dp[i][j]=1;
	                }else{
	                    dp[i][j]=abs(points[i][j])+1;
	                }
	            }else{
	                int mi=INT_MAX;
	                if(i+1<m){
	                    mi=min(mi,dp[i+1][j]);
	                }
	                
	                if(j+1<n){
	                    mi=min(mi,dp[i][j+1]);
	                }
	                
	                dp[i][j]=max(mi-points[i][j],1);
	            }
	        }
	    }
	    
	    return dp[0][0];
	} 
};