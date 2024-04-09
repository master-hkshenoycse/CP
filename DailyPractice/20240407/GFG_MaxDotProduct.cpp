#include<bits/stdc++.h>
using namespace std;

class Solution{
		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		vector<vector<int> > dp(n+1,vector<int> (m+1,INT_MIN));
		
		for(int i=0;i<=n;i++){
		    dp[i][0]=0;
		}
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=m;j++){
		        
		        dp[i][j]=max(dp[i-1][j-1]+a[i-1]*b[j-1],dp[i-1][j]);
		        
		    }
		}
		
		
		return dp[n][m];
		
	} 
};