#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	ll t;
	cin>>t;
	
	while(t--){
	    ll n,m,k;
	    cin>>n>>m>>k;
	    
	    string s;
	    cin>>s;
	    vector<vector<int> > mark(n,vector<int> (m,0));


	    for(ll p=0;p<min(n,m);p++){
	        ll op=1;
	        if(s[p%k]=='B'){
	            op=0;
	        }
	        
	        for(int j=0;j<m;j++){
	            mark[p][j]=op;
	        }
	        
	        for(int i=0;i<n;i++){
	            mark[i][p]=op;
	        }
	    }
	    
	    ll al_cnt=0,bob_cnt=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(mark[i][j]==1){
	                al_cnt++;
	            }else{
	                bob_cnt++;
	            }
	        }
	    }
	    
	    
	    if(al_cnt>bob_cnt){
	        cout<<"Alice"<<endl;
	    }else if(bob_cnt>al_cnt){
	        cout<<"Bob"<<endl;
	    }else{
	        cout<<"Draw"<<endl;
	    }
	}

}
