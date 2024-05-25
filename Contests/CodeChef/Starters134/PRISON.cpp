#include <bits/stdc++.h>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    
	    vector<vector<int> > prison(n,vector<int> (m,0));
	    vector<vector<int> > dp(n,vector<int> (m,1e9));
	    
	    string s;
	    for(int i=0;i<n;i++){
	        cin>>s;
	        
	        for(int j=0;j<m;j++){
	            prison[i][j]=s[j]-'0';
	        }
	        
	        
	    }
	    
	    queue<pair<int,int> > q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(i==0 or j==0 or i==n-1 or j==m-1){
	                dp[i][j]=prison[i][j];
	                q.push({i,j});
	            }
	        }
	    }
	    
	    int ans=0;
	    while(q.size()>0){
	        int x=q.front().first;
	        int y=q.front().second;
	        q.pop();
	        
	        for(int i=0;i<4;i++){
	            int nx=x+dx[i];
	            int ny=y+dy[i];
	            if(nx>=0 and ny>=0 and nx<n and ny<m and dp[nx][ny]>dp[x][y]+prison[nx][ny]){
	               q.push({nx,ny});
	               dp[nx][ny]=dp[x][y]+prison[nx][ny];
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(prison[i][j]==0){
	                ans=max(ans,dp[i][j]);
	            }
	        }
	    }
	    
	    cout<<ans<<endl;
	    
	}

}
